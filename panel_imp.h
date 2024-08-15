#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "admin_int.h"
#include "student_int.h"
#include "teacher_int.h"
#include "template_int.h"

using namespace std;

void mainpanel();
void adminPanel();
void studentPanel();
void teacherPanel();
int charToInt(char ch);

int charToInt(char ch) {
    if (ch < '0' || ch > '9') {
        throw invalid_argument("Invalid input. Please enter a number between 1 and 9.");
    }
    return ch - '0';
}

void mainpanel() {
    string input;
    int choice;

    while (true) {
        cout << "\n!-------------- University Management System --------------!\n";
        cout << "\t **** Superior University ****\n";
        cout << " 1- Admin\n";
        cout << " 2- Student\n";
        cout << " 3- Teacher\n";
        cout << " 4- Exit\n";
        cout << " Enter your choice (1 to 4): ";
        
        try {
            getline(cin, input);
             if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (input.length() != 1 || !isdigit(input[0])) {
                throw invalid_argument("Invalid input. Please enter a number between 1 and 4.");
            }

            choice = charToInt(input[0]); // Convert char to int

            switch (choice) {
                case 1:
                    system("cls");
                    adminPanel();
                    break;
                case 2:
                    system("cls");
                    studentPanel();
                    break;
                case 3:
                    system("cls");
                    teacherPanel();
                    break;
                case 4:
                    cout << "Exiting program...\n";
                    exit(0);
                default:
                    throw out_of_range("Choice out of range. Please enter a number between 1 and 4.");
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << '\n';
        }
        system("pause");
        system("cls");
    }
}

void adminPanel() {
    system("cls");
    admin adminInstance;
    string adminInput, passInput;
    bool authenticated = false;

    try {
        cout << "Enter Admin Username: ";
        cin >> adminInput;
        cout << "Enter Password: ";
        cin >> passInput;

        if (adminInput == "admin" && passInput == "1234") {
            authenticated = true;
            system("cls");
        } else {
            throw invalid_argument("Invalid credentials.");
        }
    } catch (const exception& e) {
        cout << "\n" << e.what() << "\n";
        cout << "Press Enter to go back to main panel...\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.get();
        system("cls");
        mainpanel();
        return;
    }

    // Clear the input buffer to avoid reading leftover newline characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while (authenticated) {
    	system("cls");
        string input;
        int choice;
        cout << "\n\t *** Welcome to Admin Section ***\n";
        cout << " 1- Add Student\n";
        cout << " 2- Remove Student\n";
        cout << " 3- Update Student Information\n";
        cout << " 4- Check Student Records\n";
        cout << " 5- Add Teacher\n";
        cout << " 6- Remove Teacher\n";
        cout << " 7- Update Teacher Information\n";
        cout << " 8- Check Teacher Records\n";
        cout << " 9- Logout\n";
        cout << " Enter your choice (1 to 9): ";

        try {
            getline(cin, input);
             if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (input.length() != 1 || !isdigit(input[0])) {
                throw invalid_argument("Invalid input. Please enter a number between 1 and 9.");
            }

            choice = charToInt(input[0]);

            switch (choice) {
                case 1:
                    system("cls");
                    adminInstance.createStudent();
                    break;
                case 2:
                    system("cls");
                    adminInstance.deleteStudent();
                    break;
                case 3:
                    system("cls");
                    adminInstance.updateStudent();
                    break;
                case 4:
                    system("cls");
                    printRecords<student>("student.dat");
                    break;
                case 5:
                    system("cls");
                    adminInstance.createTeacher();
                    break;
                case 6:
                    system("cls");
                    adminInstance.deleteTeacher();
                    break;
                case 7:
                    system("cls");
                    adminInstance.updateTeacher();
                    break;
                case 8:
                    system("cls");
                    printRecords<teacher>("teacher.dat");
                    break;
                case 9:
                    system("cls");
                    mainpanel();
                    return;
                default:
                    throw out_of_range("Choice out of range. Please enter a number between 1 and 9.");
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << '\n';
        }
        system("pause");
    }
    
}

void studentPanel() {
    system("cls");
    student studentInstance;
    string studentInput, passInput;
    bool authenticated = false;

    try {
        cout << "Enter Student Username: ";
        cin >> studentInput;
        cout << "Enter Password: ";
        cin >> passInput;

        if (studentInput == "student" && passInput == "1234") {
            authenticated = true;
            system("cls");
        } else {
            throw invalid_argument("Invalid credentials.");
        }
    } catch (const exception& e) {
        cout << "\n" << e.what() << "\n";
        cout << "Press Enter to go back to main panel...\n";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.get();
        system("cls");
        mainpanel();
        return;
    }
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (authenticated) {
        string input;
        int choice;
        cout << "\n--- Student Panel ---\n";
        cout << " 1. Check Info\n";
        cout << " 2. Check Course\n";
        cout << " 3. Is Student Exist\n";
        cout << " 4. Back to Main Menu\n";
        cout << " Enter your choice: ";
        
        try {
            getline(cin, input);
             if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (input.length() != 1 || !isdigit(input[0])) {
                throw invalid_argument("Invalid input. Please enter a number between 1 to 4.");
            }

            choice = charToInt(input[0]);

            switch (choice) {
                case 1:
                    system("cls");
                    studentInstance.checkinfo();
                    break;
                case 2:
                    system("cls");
                    studentInstance.checkcourse();
                    break;
                case 3:
                	system("cls");
                	studentInstance.studentexist();
                	break;
                case 4:
                    system("cls");
                    mainpanel();
                    return;
                default:
                    throw out_of_range("Choice out of range. Please enter a number between 1 to 4.");
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << '\n';
            system("pause");
            system("cls");
        }
    }
}

void teacherPanel() {
    system("cls");
    teacher teacherInstance;
    string teacherInput, passInput;
    bool authenticated = false;

    try {
        cout << "Enter Teacher Username: ";
        cin >> teacherInput;
        cout << "Enter Password: ";
        cin >> passInput;

        if (teacherInput == "teacher" && passInput == "1234") {
            authenticated = true;
            system("cls");
        } else {
            throw invalid_argument("Invalid credentials.");
        }
    } catch (const exception& e) {
        cout << "\n" << e.what() << "\n";
        cout << "Press Enter to go back to main panel...\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("cls");
        mainpanel();
        return;
    }
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (authenticated) {
        string input;
        int choice;
        cout << "\n--- Teacher Panel ---\n";
        cout << " 1. Check Info\n";
        cout << " 2. Is Teacher Exist\n";
        cout << " 3. Back to Main Menu\n";
        cout << " Enter your choice: ";
        
        try {
            getline(cin, input);
            if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            if (input.length() != 1 || !isdigit(input[0])) {
                throw invalid_argument("Invalid input. Please enter a number between 1 to 3.");
            }

            choice = charToInt(input[0]);

            switch (choice) {
                case 1:
                    system("cls");
                    teacherInstance.checkinfo();
                    break;
                case 2:
                	system("cls");
                	teacherInstance.teacherexist();
                	break;
                case 3:
                    system("cls");
                    mainpanel();
                    return;
                default:
                    throw out_of_range("Choice out of range. Please enter a number between 1 to 3.");
                    
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << '\n';
            system("pause");
            system("cls");
        }
    }
}

