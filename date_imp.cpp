#include <iostream>
#include <stdexcept>
#include <limits>
#include "date_int.h"

using namespace std;

// Constructor
date::date(int m, int d, int y) {
    setDate(m, d, y);
}

// Getters
int date::getDay() const {
    return dDay;
}

int date::getMonth() const {
    return dMonth;
}

int date::getYear() const {
    return dYear;
}

// Print date
void date::printDate() const {
    cout << dMonth << "-" << dDay << "-" << dYear;
}

// Check if the year is a leap year
bool date::isLeapYear() const {
    if (dYear % 400 == 0)
        return true;
    if (dYear % 100 == 0)
        return false;
    return dYear % 4 == 0;
}

// Unified setDate method for user input and validation
void date::setDate() {
    int m, d, y;

    while (true) {
        try {
            cout << "Enter month, day, and year (mm dd yyyy): ";

            if (!(cin >> m)) {
                throw invalid_argument("Invalid month input. Please enter numeric values.");
            }

            if (!(cin >> d)) {
                throw invalid_argument("Invalid day input. Please enter numeric values.");
            }

            if (!(cin >> y)) {
                throw invalid_argument("Invalid year input. Please enter numeric values.");
            }

            // Validate and set the date
            setDate(m, d, y);

            break; // Exit loop if input is valid

        } catch (const invalid_argument &e) {
            cerr << "Error: " << e.what() << endl;

            // Clear input stream state
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Method to set date with given parameters
void date::setDate(int m, int d, int y) {
    // Validate month
    if (m < 1 || m > 12) {
        throw invalid_argument("Invalid month value.");
    }

    // Validate year
    if (y < 1990 || y > 2024) {
        throw invalid_argument("Invalid year value.");
    }

    // Validate day based on month and leap year status
    bool validDay = false;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        validDay = (d >= 1 && d <= 31);
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        validDay = (d >= 1 && d <= 30);
    } else if (m == 2) {
        // Temporarily set dYear to y for leap year check
        int tempYear = dYear;
        dYear = y;
        if (isLeapYear()) {
            validDay = (d >= 1 && d <= 29);
        } else {
            validDay = (d >= 1 && d <= 28);
        }
        dYear = tempYear; // Restore dYear
    }

    if (!validDay) {
        throw invalid_argument("Invalid day value for the given month/year.");
    }

    // Set the date
    dMonth = m;
    dDay = d;
    dYear = y;
}

bool date::operator==(const date& other) const {
    return dMonth == other.dMonth && dDay == other.dDay && dYear == other.dYear;
}


ostream& operator<<(ostream& os, const date& dt) {
    os << dt.dMonth << "/" << dt.dDay << "/" << dt.dYear;
    return os;
}


istream& operator>>(istream& is, date& d) {
        is >> d.dMonth >> d.dDay >> d.dYear;
        return is;
    }
