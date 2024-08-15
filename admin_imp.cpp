#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <limits>
#include "person_int.h"
#include "student_int.h"
#include "teacher_int.h"
#include "admin_int.h"
using namespace std;

admin::admin() : studentCount(0), studentCapacity(10), teacherCount(0), teacherCapacity(10) {
    students = new student[studentCapacity];
    teachers = new teacher[teacherCapacity];
    loadStudents();
    loadTeachers();
}

// Copy constructor
admin::admin(const admin& other) : studentCount(other.studentCount), studentCapacity(other.studentCapacity), teacherCount(other.teacherCount), teacherCapacity(other.teacherCapacity) {
    students = new student[studentCapacity];
    for (int i = 0; i < studentCount; ++i) {
        students[i] = other.students[i];
    }
    teachers = new teacher[teacherCapacity];
    for (int i = 0; i < teacherCount; ++i) {
        teachers[i] = other.teachers[i];
    }
}

// Assignment operator
admin& admin::operator=(const admin& other) {
    if (this != &other) {
        studentCount = other.studentCount;
        studentCapacity = other.studentCapacity;
        teacherCount = other.teacherCount;
        teacherCapacity = other.teacherCapacity;

        delete[] students;
        students = new student[studentCapacity];
        for (int i = 0; i < studentCount; ++i) {
            students[i] = other.students[i];
        }

        delete[] teachers;
        teachers = new teacher[teacherCapacity];
        for (int i = 0; i < teacherCount; ++i) {
            teachers[i] = other.teachers[i];
        }
    }
    return *this;
}

// Equality operator
bool admin::operator==(const admin& other) const {
    if (studentCount != other.studentCount || teacherCount != other.teacherCount) {
        return false;
    }
    for (int i = 0; i < studentCount; ++i) {
        if (!(students[i] == other.students[i])) {
            return false;
        }
    }
    for (int i = 0; i < teacherCount; ++i) {
        if (!(teachers[i] == other.teachers[i])) {
            return false;
        }
    }
    return true;
}



void admin::expandStudentArray() {
    studentCapacity *= 2;
    student* newStudents = new student[studentCapacity];
    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = students[i];
    }
    delete[] students;
    students = newStudents;
}

void admin::expandTeacherArray() {
    teacherCapacity *= 2;
    teacher* newTeachers = new teacher[teacherCapacity];
    for (int i = 0; i < teacherCount; ++i) {
        newTeachers[i] = teachers[i];
    }
    delete[] teachers;
    teachers = newTeachers;
}

void admin::createStudent() {
    if (studentCount == studentCapacity) {
        expandStudentArray();
    }
    students[studentCount].setData();
    ++studentCount;
    saveStudents();
}

void admin::readStudent() const {
    ifstream file("student.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    student temp;
    try {
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(student))) {
            temp.print();
            cout << "-----------------------------------" << endl;
        }
    } catch (const ios_base::failure& e) {
        cerr << "File read error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred while reading the file." << endl;
    }

    file.close();
    system("pause");
}

void admin::updateStudent() {
    int roll;
    cout << "Enter roll number of the student to update: ";
    while (!(cin >> roll) || roll <= 0) {
    	if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a positive integer for roll number: ";
    }
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getroll() == roll) {
            students[i].setData();
            saveStudents();
            return;
        }
    }
    cout << "Student not found.\n";
}

void admin::deleteStudent() {
    int roll;
    cout << "Enter roll number of the student to delete: ";
    while (!(std::cin >> roll) || roll <= 0) {
    	if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a positive integer for roll number: ";
    }

	    for (int i = 0; i < studentCount; ++i) {
	        if (students[i].getroll() == roll) {
	            for (int j = i; j < studentCount - 1; ++j) {
	                students[j] = students[j + 1];
	            }
            --studentCount;
            saveStudents();
            cout << "Student deleted.\n";
            system("pause");
            return;
        }
    }
    cout << "Student not found.\n";
     system("pause");
}

void admin::createTeacher() {
    if (teacherCount == teacherCapacity) {
        expandTeacherArray();
    }
    teachers[teacherCount].setData();
    ++teacherCount;
    saveTeachers();
    cout<<"\nTeacher Added Successfully\n";
    system("pause");
}

void admin::readTeacher() const {
    ifstream file("teacher.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    teacher temp;
    try {
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(teacher))) {
            temp.print();
            cout << "-----------------------------------" << endl;
        }
    } catch (const ios_base::failure& e) {
        cerr << "File read error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred while reading the file." << endl;
    }

    file.close();
    system("pause");
}

void admin::updateTeacher() {
	cin.ignore(1000,'\n');
    string input;
    int id;

    cout << "Enter ID of the teacher to update: ";
    while (true) {
        getline(cin, input);
        if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
        // Check if the entire input is a valid positive integer
        bool isValid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }
        
        if (isValid && !input.empty()) {
            id = stoi(input);
            if (id > 0) {
                break; // Valid input, exit the loop
            }
        }
        
        cerr << "Invalid input. Please enter a positive integer for ID: ";
        // Clear any error flags and ignore remaining input
        cin.clear();
    }

    for (int i = 0; i < teacherCount; ++i) {
        if (teachers[i].getid() == id) {
            teachers[i].setData();
            saveTeachers();
            return;
        }
    }
    cout << "Teacher not found.\n";
    system("pause");
}

void admin::deleteTeacher() {
    int id;
    cout << "Enter ID of the teacher to delete: ";
    while (!(cin >> id) || id <= 0) {
    	if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a positive integer for ID: ";
    }

    for (int i = 0; i < teacherCount; ++i) {
        if (teachers[i].getid() == id) {
            for (int j = i; j < teacherCount - 1; ++j) {
                teachers[j] = teachers[j + 1];
            }
            --teacherCount;
            saveTeachers();
            std::cout << "Teacher deleted.\n";
            system("pause");
            return;
        }
    }
    cout << "Teacher not found.\n";
    system("pause");
}

void admin::loadStudents() {
    ifstream file("student.dat", std::ios::binary);
    if (!file) {
        cerr << "Error: Unable to open student file.\n";
        return;
    }

    student temp;
    try {
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(student))) {
            if (studentCount == studentCapacity) {
                expandStudentArray();
            }
            students[studentCount] = temp;
            ++studentCount;
        }
    } catch (const ios_base::failure& e) {
        cerr << "File read error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred while loading students." << endl;
    }

    file.close();
}

void admin::saveStudents() const {
    ofstream file("student.dat", std::ios::binary | std::ios::trunc);
    if (!file) {
        cerr << "Error: Unable to open student file.\n";
        return;
    }

    try {
        for (int i = 0; i < studentCount; ++i) {
            file.write(reinterpret_cast<const char*>(&students[i]), sizeof(student));
            if (!file) {
                throw ios_base::failure("Error writing to file");
            }
        }
    } catch (const ios_base::failure& e) {
        cerr << "File write error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred while saving students." << endl;
    }

    file.close();
}

void admin::loadTeachers() {
    ifstream file("teacher.dat", std::ios::binary);
    if (!file) {
        cerr << "Error: Unable to open teacher file.\n";
        return;
    }

    teacher temp;
    try {
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(teacher))) {
            if (teacherCount == teacherCapacity) {
                expandTeacherArray();
            }
            teachers[teacherCount] = temp;
            ++teacherCount;
        }
    } catch (const ios_base::failure& e) {
        cerr << "File read error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred while loading teachers." << endl;
    }

    file.close();
}

void admin::saveTeachers() const {
    ofstream file("teacher.dat", std::ios::binary | std::ios::trunc);
    if (!file) {
        cerr << "Error: Unable to open teacher file.\n";
        return;
    }

    try {
        for (int i = 0; i < teacherCount; ++i) {
            file.write(reinterpret_cast<const char*>(&teachers[i]), sizeof(teacher));
            if (!file) {
                throw ios_base::failure("Error writing to file");
            }
        }
    } catch (const ios_base::failure& e) {
        cerr << "File write error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error occurred while saving teachers." << endl;
    }

    file.close();
}

admin::~admin() {
    saveStudents();
    saveTeachers();
    delete[] students;
    delete[] teachers;
}

