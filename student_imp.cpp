#include <stdexcept>
#include<fstream>
#include <limits>
#include "student_int.h"

student::student() : Person(), rollno(0), birthdate() {
    strcpy(depart, "");
}

student::student(string fn, string ln, int roll, string dep, date birth)
    : Person(fn, ln), rollno(roll), birthdate(birth) {
    try {
        if (dep.length() > 8 || !isAlpha(dep)) {
            throw invalid_argument("Invalid department name");
        }
        strncpy(depart, dep.c_str(), 8);
        depart[8] = '\0'; // Ensure null-terminated
        writeRecord();
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in student constructor." << endl;
    }
}

bool student::isAlpha(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool student::isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

 bool student::rollExists(int rollno) {
        ifstream file("student.dat", ios::binary);
        if (!file) {
        	cerr<<"Error Opening File\n";
		}

        student record;
        while (file.read(reinterpret_cast<char*>(&record), sizeof(student))) {
            if (record.rollno == rollno) {
                return true;
            }
        }
        return false;
    }

void student::setData() {
    Person::setData();

    while (true) {
        try {
            string rollInput;
            cout << "Enter Rollno: ";
            cin >> rollInput;
			if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            // Check if rollInput is numeric and not empty
            if (!isNumeric(rollInput) || rollInput.empty()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. Roll number must be a positive integer.");
            }

            // Convert rollInput to integer
            rollno = stringToInt(rollInput);

            // Check if rollno is positive
            if (rollno <= 0) {
                throw invalid_argument("Invalid input. Roll number must be a positive integer.");
            }
            
            if (rollExists(rollno)) {
                    throw invalid_argument("Roll number already exists. Please enter a different roll number.");
                }

            break; // Exit the loop if input is valid
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

while (true) {
        try {
            cout << "Enter Department name: ";
            cin.getline(depart, 9); // Read up to 8 characters (leaving space for '\0')
            if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
                throw invalid_argument("Department input failed or too long.");
            } else if (!isAlpha(depart)) {
                cerr << "Invalid input. Department must be alphabetic." << endl;
            } else {
                break;
            }

        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
             cout<<"\n Press Enter To Input Again:\n";
        }

        // Clear the input buffer before the next iteration
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Use the date class to handle birthdate input and validation
    birthdate.setDate();

    try {
        writeRecord();
    } catch (const ios_base::failure& e) {
        cerr << "File operation error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in writeRecord." << endl;
    }
    cout<<"\n\n-----------------Student Successfully Added-------------------\n"<<endl;
    system("pause");
}

int student::getroll() const {
    return rollno;
}

const char* student::getdepart() const {
    return depart;
}

void student::print() const {
    cout << "Roll Number: " << rollno << endl;
    Person::getData();
    cout << "Department: " << depart << endl;
    cout << "BirthDate: ";
    birthdate.printDate();
    cout << endl;
}

void student::writeRecord() const {
    try {
        ofstream file("student.dat", ios::binary | ios::app);
        if (!file) {
            throw ios_base::failure("Error opening file for writing");
        }
        file.write(reinterpret_cast<const char*>(this), sizeof(student));
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

void student::checkinfo() {
    try {
        ifstream file("student.dat", ios::binary);
        if (!file) {
            throw ios_base::failure("Error opening file for reading");
        }
        int roll;
        bool found = false;
        while (true) {
            string rollInput;
            cout << "Enter Rollno: ";
            cin >> rollInput;
            if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (!isNumeric(rollInput) || rollInput.empty()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Roll number must be a positive integer." << endl;
            } else {
                roll = stringToInt(rollInput);
                if (roll > 0) {
                    break;
                }
            }
        }

        student temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(student))) {
            if (roll == temp.getroll()) {
                temp.print();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nInvalid Rollno: \n";
        }
        file.close();
    } catch (const ios_base::failure &e) {
        cerr << "File operation error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred in checkinfo." << endl;
    }
    system("pause");
}

void student::checkcourse() {
    bool found = false;
    string dep;
    while (true) {
        cout << "Enter Your Department: BS";
        cin >> dep;
        if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
        if (dep.empty() || dep.length() > 2 || !isAlpha(dep)) {
            cerr << "Invalid input. Department must be alphabetic and up to 2 characters." << endl;
        } else {
            break;
        }
    }

    if (dep == "CS" || dep == "cs") {
        cout << "Your Assigned Courses are: " << endl;
        cout << "1. Programming Fundamentals" << endl;
        cout << "2. English" << endl;
        cout << "3. Logics" << endl;
        cout << "4. Computer Architecture" << endl;
        found = true;
    } else if (dep == "IT" || dep == "it") {
        cout << "Your Assigned Courses are: " << endl;
        cout << "1. Introduction to IT" << endl;
        cout << "2. Database" << endl;
        cout << "3. Web Designing" << endl;
        cout << "4. Networking" << endl;
        found = true;
    } else if (dep == "IOT" || dep == "iot") {
        cout << "Your Assigned Courses are: " << endl;
        cout << "1. Introduction to IT" << endl;
        cout << "2. Database" << endl;
        cout << "3. Web Designing" << endl;
        cout << "4. Networking" << endl;
        found = true;
    } else if (dep == "CB" || dep == "cb") {
        cout << "Your Assigned Courses are: " << endl;
        cout << "1. Programming Fundamentals" << endl;
        cout << "2. English" << endl;
        cout << "3. Logics" << endl;
        cout << "4. Computer Architecture" << endl;
        found = true;
    } else {
        cout << "No Course Found" << endl;
        found = true;
    }

    if (!found) {
        cout << "\nInvalid Department: \n";
    }
    system("pause");
}

student& student::operator=(const student& other) {
    if (this != &other) {
        Person::operator=(other); // Assign base class members
        rollno = other.rollno;
        strncpy(depart, other.depart, 8);
        depart[8] = '\0';
        birthdate = other.birthdate;
    }
    return *this;
}

// Equality operator
bool student::operator==(const student& other) const {
    return Person::operator==(other) && rollno == other.rollno && strcmp(depart, other.depart) == 0 && birthdate == other.birthdate;
}


void student::studentexist() {
    ifstream file("student.dat", ios::binary);
    if (!file) {
        cerr << "Error Opening File" << endl;
        return;
    }

    bool found = false;
    student s;             // Object to read input from the user
    student student_in_file; // Object to read from the file

    cout << "Enter student details to search:\n ";
    cin >> s; // Read student details to search

    while (file.read(reinterpret_cast<char*>(&student_in_file), sizeof(student))) {
        if (s == student_in_file) { // Compare objects
		    cout<<endl; 
            student_in_file.print(); // Print matched student
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

int student::stringToInt(const string& str) {
    int num = 0;
    for (char ch : str) {
        if (ch < '0' || ch > '9') {
            throw invalid_argument("Invalid input. Roll number must be a positive integer.");
        }
        num = num * 10 + (ch - '0');
    }
    return num;
}



student::~student() {
}



ostream& operator<<(ostream& os, const student& s) {
    os << static_cast<const Person&>(s); // Print base class part
    os << "Roll No: " << s.rollno << endl;
    os << "Department: " << s.depart << endl;
    os << "Birthdate: " << s.birthdate << endl; // Assuming overloaded << operator for date
    return os;
}



istream& operator>>(istream& is, student& s) {
    is >> static_cast<Person&>(s); // Input base class part
    cout << "Enter roll number: ";
    is >> s.rollno;
    cout << "Enter department: ";
    is >> s.depart;
    cout << "Enter birth date (mm dd yyyy): ";
    is >> s.birthdate; // Assuming overloaded >> operator for date
    return is;
}

