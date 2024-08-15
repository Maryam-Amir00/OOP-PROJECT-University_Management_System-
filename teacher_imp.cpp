#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <stdexcept>
#include "person_int.h"
#include "teacher_int.h"

using namespace std;

teacher::teacher() : Person(), id(0) {
    strcpy(course, "Unknown");
}

teacher::teacher(string fn, string ln, int t_id, string t_course) : Person(fn, ln), id(t_id) {
    try {
        if (!isAlpha(t_course)) {
            throw invalid_argument("Invalid course name: must be alphabetic");
        }
        strncpy(course, t_course.c_str(), 25);
        course[25] = '\0';
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in teacher constructor." << endl;
    }
}

 bool teacher::IDExists(int t_id){
        ifstream file("teacher.dat", ios::binary);
        if (!file) {
        	cerr<<"Error Opening File\n";
		}
        teacher record;
        while (file.read(reinterpret_cast<char*>(&record), sizeof(teacher))) {
            if (record.id == t_id) {
                return true;
            }
        }
        return false;
    }

bool teacher::isAlpha(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) return false;
    }
    return true;
}

void teacher::setData() {
    Person::setData();
    while (true) {
        try {
            cout << "Enter ID: ";
            cin >> id;
            if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (cin.fail() || id <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. ID must be a positive integer.");
            }
            string remainingInput;
            getline(cin, remainingInput);
            if (!remainingInput.empty()) {
                throw invalid_argument("Invalid input. ID must be a positive integer.");
            }
             if (IDExists(id)) {
                    throw invalid_argument("ID number already exists. Please enter a different ID.");
                }
            break; 
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true) {
        try {
            cout << "Enter course: ";
            cin.getline(course, 26);
            if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
                throw invalid_argument("Course input failed or too long.");
            } else if (!isAlpha(course)) {
                cerr << "Invalid input. Course must be alphabetic." << endl;
                cout<<"\n Press Enter To Input Again:\n";
            } else {
                // If we reach here, the input is valid
                break;
            }

        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }

        // Clear the input buffer before the next iteration
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    try {
        writeRecord();
    } catch (const ios_base::failure& e) {
        cerr << "File operation error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in writeRecord." << endl;
    }
}



int teacher::getid() const {
    return id;
}

const char* teacher::getcourse() const {
    return course;
}

void teacher::print() const {
    Person::getData();
    cout << "ID: " << id << ", Course: " << course << endl;
}

void teacher::writeRecord() const {
    try {
        ofstream file("teacher.dat", ios::binary | ios::app);
        if (!file) {
            throw ios_base::failure("Error opening file for writing");
        }
        file.write(reinterpret_cast<const char*>(this), sizeof(teacher));
        if (!file) {
            throw ios_base::failure("Error writing to file");
        }
        file.close();
    } catch (const ios_base::failure &e) {
        cerr << "File operation error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in writeRecord." << endl;
    }
}


bool teacher::isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}


void teacher::checkinfo() {
    try {
        ifstream file("teacher.dat", ios::binary);
        if (!file) {
            throw ios_base::failure("Error opening file for reading");
        }
        int roll;
        string tid;
        bool found = false;
        
        while (true) {
            cout << "Enter ID: ";
            cin >> tid;
            if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (!isNumeric(tid) || tid.empty()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. ID must be a positive integer." << endl;
            } else {
                roll = stringToInt(tid);
                if (roll > 0) {
                    break;
                }
                cerr << "Invalid input. ID must be a positive integer." << endl;
            }
        }

        teacher temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(teacher))) {
            if (roll == temp.getid()) {
                temp.print();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "\nInvalid ID: " << roll << "\n";
        }
        
        file.close();
    } catch (const ios_base::failure &e) {
        cerr << "File operation error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in checkinfo." << endl;
    }
    system("pause");
}


// Assignment operator
teacher& teacher::operator=(const teacher& other) {
    if (this != &other) {
        Person::operator=(other); // Assign base class members
        id = other.id;
        strncpy(course, other.course, 25);
        course[25] = '\0';
    }
    return *this;
}

// Equality operator
bool teacher::operator==(const teacher& other) const {
    return Person::operator==(other) && id == other.id && strcmp(course, other.course) == 0;
}


void teacher::teacherexist() {
    ifstream file("teacher.dat", ios::binary);
    if (!file) {
        cerr << "Error Opening File" << endl;
        return;
    }

    bool found = false;
    teacher t;             // Object to read input from the user
    teacher teacher_in_file; // Object to read from the file

    cout << "Enter Teacher details to search:\n ";
    cin >> t; // Read student details to search

    while (file.read(reinterpret_cast<char*>(&teacher_in_file), sizeof(teacher))) {
        if (t == teacher_in_file) { // Compare objects
            cout<<endl;
			teacher_in_file.print(); // Print matched student
            cout<<"\nRecord Exist\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nInvalid Record\n";
    }

    file.close();
    system("pause");
    system("cls");
}

int teacher::stringToInt(const string& str) {
    int num = 0;
    for (char ch : str) {
        if (ch < '0' || ch > '9') {
            throw invalid_argument("Invalid input. Roll number must be a positive integer.");
        }
        num = num * 10 + (ch - '0');
    }
    return num;
}


teacher::~teacher() {
}


// Overloaded insertion operator
ostream& operator<<(ostream& os, const teacher& t) {
    os << static_cast<const Person&>(t); // Print base class part
    os << "ID: " << t.id << "\nCourse: " << t.course << endl;
    return os;
}

// Overloaded extraction operator
istream& operator>>(istream& is, teacher& t) {
    // Read base class part, assuming Person has overloaded >> operator
    is >> static_cast<Person&>(t);
    cout << "Enter ID: ";
    is >> t.id;
    is.ignore(); // Ignore leftover newline
    cout << "Enter course: ";
    is.getline(t.course, sizeof(t.course));
    return is;
}
