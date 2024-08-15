#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cctype>
#include <limits>
#include "person_int.h"
using namespace std;

Person::Person()
{
    try {
        strcpy(FirstName, "");
        strcpy(LastName, "");
    } catch (...) {
        cerr << "An error occurred during the initialization of the default constructor." << endl;
    }
}

Person::Person(string fn, string ln)
{
    try {
        if (fn.length() > 25 || ln.length() > 25) {
            throw length_error("Name length exceeds buffer size.");
        }
        strncpy(FirstName, fn.c_str(), 25);
        FirstName[25] = '\0'; 
        strncpy(LastName, ln.c_str(), 25);
        LastName[25] = '\0';

        for (size_t i = 0; i < strlen(FirstName); ++i) {
            if (!isalpha(FirstName[i])) {
                throw invalid_argument("First name contains non-alphabet characters.");
            }
        }
        for (size_t i = 0; i < strlen(LastName); ++i) {
            if (!isalpha(LastName[i])) {
                throw invalid_argument("Last name contains non-alphabet characters.");
            }
        }
    } catch (length_error& e) {
        cerr << "Exception caught: " << e.what() << endl;
        strncpy(FirstName, "", 25);
        FirstName[25] = '\0';
        strncpy(LastName, "", 25);
        LastName[25] = '\0';
    } catch (invalid_argument& e) {
        cerr << "Exception caught: " << e.what() << endl;
        strncpy(FirstName, "", 25);
        FirstName[25] = '\0';
        strncpy(LastName, "", 25);
        LastName[25] = '\0';
    }
}

// Copy constructor
Person::Person(const Person& other) {
    strncpy(FirstName, other.FirstName, 25);
    FirstName[25] = '\0';
    strncpy(LastName, other.LastName, 25);
    LastName[25] = '\0';
}

// Assignment operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        strncpy(FirstName, other.FirstName, 25);
        FirstName[25] = '\0';
        strncpy(LastName, other.LastName, 25);
        LastName[25] = '\0';
    }
    return *this;
}

// Equality operator
bool Person::operator==(const Person& other) const {
    return strcmp(FirstName, other.FirstName) == 0 && strcmp(LastName, other.LastName) == 0;
}


void Person::setData() {
    bool validFirstName = false;
    bool validLastName = false;

    while (!validFirstName) {
        try {
            cout << "Enter first name: ";
            cin.getline(FirstName, 26);
			if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            // Check if input failed, is too long, or is empty
            if (cin.fail() || strlen(FirstName) == 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
                throw invalid_argument("First name input failed, too long, or empty.");
            }

            // Validate that the input only contains alphabetic characters
            for (size_t i = 0; i < strlen(FirstName); ++i) {
                if (!isalpha(FirstName[i])) {
                    throw invalid_argument("First name contains non-alphabet characters.");
                }
            }
            validFirstName = true;

        } catch (invalid_argument& e) {
            cerr << "Exception caught: " << e.what() << endl;
            cout << "First name should only contain alphabetic characters, be less than 26 characters long, and not be empty." << endl;
            cout<<"\nPress Enter To Input Again:\n";
            // Clear the buffer before retrying
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            strncpy(FirstName, "", 25);
            FirstName[25] = '\0';
        }
    }

    while (!validLastName) {
        try {
            cout << "Enter last name: ";
            cin.getline(LastName, 26);
			if (cin.eof()) {
                cout << "\nEnd-of-file reached. Exiting program gracefully." << endl;
                return;  // Exit the method or handle as necessary
            }
            // Check if input failed, is too long, or is empty
            if (cin.fail() || strlen(LastName) == 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
                throw invalid_argument("Last name input failed, too long, or empty.");
            }

            // Validate that the input only contains alphabetic characters
            for (size_t i = 0; i < strlen(LastName); ++i) {
                if (!isalpha(LastName[i])) {
                    throw invalid_argument("Last name contains non-alphabet characters.");
                }
            }
            validLastName = true;

        } catch (invalid_argument& e) {
            cerr << "Exception caught: " << e.what() << endl;
            cout << "Last name should only contain alphabetic characters, be less than 26 characters long, and not be empty." << endl;
            cout<<"\nPress Enter To Input Again:\n";
            // Clear the buffer before retrying
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            strncpy(LastName, "", 25);
            LastName[25] = '\0';
        }
    }
}

void Person::getData() const
{
    try {
        cout << "First Name: " << FirstName << endl;
        cout << "Last Name: " << LastName << endl;
    } catch (...) {
        cerr << "An error occurred during getData." << endl;
    }
}

Person::~Person() {}


ostream& operator<<(ostream& os, const Person& p) {
    os << "First Name: " << p.FirstName << endl;
    os << "Last Name: " << p.LastName << endl;
    return os;
}

istream& operator>>(istream& is, Person& p) {
    cout << "Enter first name: ";
    is >> p.FirstName;
    cout << "Enter last name: ";
    is >> p.LastName;
    return is;
}
