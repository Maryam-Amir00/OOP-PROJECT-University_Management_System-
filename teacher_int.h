#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include <stdexcept>
#include"person_int.h"
using namespace std;


#ifndef teacher_int
#define teacher_int
class teacher:public Person{
	friend ostream& operator<<(ostream& os, const teacher& t);
    friend istream& operator>>(istream& is, teacher& t);
	private:
		int id;
		char course[26];
	public:
		teacher();
		bool IDExists(int t_id);
		teacher(string fn , string ln, int t_id, string t_course);
		void setData()override;
		bool isAlpha(const string& str);
		bool isNumeric(const string& str);
		int getid()const;
		const char* getcourse()const;
		void print()const override;
		void writeRecord()const;
		void checkinfo();
		void teacherexist();
		teacher& operator=(const teacher& other); // Assignment operator
    	bool operator==(const teacher& other) const; // Equality operator
    	int stringToInt(const string& str);
		~teacher();
};
#endif
