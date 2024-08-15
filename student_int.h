#include<iostream>
#include<string>
#include<cstring>
#include"person_int.h"
#include"date_int.h"
using namespace std;

#ifndef student_int
#define student_int
class student:public Person
{
	friend ostream& operator<<(ostream& os, const student& s);
    friend istream& operator>>(istream& is, student& s);
	private:
	    int rollno;
		char depart[9];
		date birthdate;
	public:
		student();
		bool rollExists(int rollno);
		student(string fn, string ln,int roll,string dep, date birth);
		void setData()override;
		bool isAlpha(const string& str);
		bool isNumeric(const string& str);
		int getroll()const;
		const char* getdepart()const;
		void print()const override;
		void writeRecord()const;
		void checkinfo();
		void checkcourse();
		void studentexist();
		student& operator=(const student& other); // Assignment operator
    	bool operator==(const student& other) const; // Equality operator
    	int stringToInt(const string& str);
		~student();
};
#endif
