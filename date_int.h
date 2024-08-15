#include<iostream>
using namespace std;

#ifndef  date_int
#define  date_int
class date {
	friend ostream& operator<<(ostream& os, const date& dt); // Output operator
	friend istream& operator>>(std::istream& is, date& d);
private:
    int dMonth;
    int dDay;
    int dYear;

public:
    date(int month = 1, int day = 1, int year = 1990); // Constructor

    void setDate(); // Unified method to handle input and setting date
    void setDate(int month, int day, int year); // Method to set date with given parameters

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void printDate() const;
    bool isLeapYear() const;
     bool operator==(const date& other) const;
};

#endif
