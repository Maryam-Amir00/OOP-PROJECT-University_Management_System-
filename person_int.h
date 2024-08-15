#include<iostream>
#include<string>
#include<cstring>
using namespace std;

#ifndef person_int
#define  person_int
class Person{
	friend ostream& operator<<(ostream& os, const Person& p);
    friend istream& operator>>(istream& is, Person& p);
	private:
     	char FirstName[26];
     	char LastName[26];
    public:
    	Person();
    	Person(string fn , string ln);
    	Person(const Person& other); // Copy constructor
        Person& operator=(const Person& other); // Assignment operator
        bool operator==(const Person& other) const; // Equality operator
    	virtual void setData();
    	virtual void getData()const;
    	virtual void print()const = 0;
    	virtual ~Person();
};
#endif
