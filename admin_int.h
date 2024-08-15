#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include <stdexcept>
#include"person_int.h"
#include"student_int.h"
#include"teacher_int.h"
using namespace std;

#ifndef admin_int
#define admin_int
class admin
{
	public:
    	admin();
    	admin(const admin& other); // Copy constructor
    	admin& operator=(const admin& other); // Assignment operator
    	bool operator==(const admin& other) const; // Equality operator
    	
    	void createStudent();
    	void readStudent() const;
    	void updateStudent();
    	void deleteStudent();

    	void createTeacher();
    	void readTeacher() const;
    	void updateTeacher();
    	void deleteTeacher();
		 ~admin();
	private:
    	student* students;
    	int studentCount;
    	int studentCapacity;
    	teacher* teachers;
    	int teacherCount;
    	int teacherCapacity;

    	void loadStudents();
    	void saveStudents() const;

    	void loadTeachers();
    	void saveTeachers() const;

    	void expandStudentArray();
    	void expandTeacherArray();
};
#endif
