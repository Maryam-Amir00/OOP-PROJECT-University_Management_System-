**University Management System**

**Description:**

The University Management System is a robust C++ application designed to streamline the management of student and teacher records within a university environment. It offers a user-friendly interface for administrators, students, and teachers, allowing them to perform various operations and access pertinent information efficiently.

This project is developed as part of the Object-Oriented Programming (OOP) course and showcases key OOP principles such as inheritance, polymorphism, operator overloading, and file handling.

**Features:**

**Admin Panel**

Student Management:
Add new students
View existing student records
Update student information
Delete student records

Teacher Management:

Add new teachers
View existing teacher records
Update teacher information
Delete teacher records

**Student Panel**

Access personal information
View assigned courses based on department
Verify existence in the system

**Teacher Panel**

Access personal information
Verify existence in the system

**General Features:**

Date handling for accurate record-keeping

File-based storage for persistent data management

Robust input validation and error handling

Custom implementations of copy constructors, assignment operators, and equality operators

Template functions for flexible and reusable code

**Project Structure**

The project is organized into several key components:

panel_imp.h: Implements the main panels (Admin, Student, Teacher) and user interface.
admin_imp.cpp & admin_int.h: Implementation and interface for the Admin class.
student_imp.cpp & student_int.h: Implementation and interface for the Student class.
teacher_imp.cpp & teacher_int.h: Implementation and interface for the Teacher class.
person_imp.cpp & person_int.h: Implementation and interface for the base Person class.
date_imp.cpp & date_int.h: Implementation and interface for the Date class.
template_int.h: Contains template functions for generic operations, like printing records.

**Key Classes:**

Person: Base class for students and teachers, managing common personal information.
Student: Derived from Person, handles student-specific data and operations.
Teacher: Derived from Person, handles teacher-specific data and operations.
Admin: Manages administrative functions for both students and teachers.
Date: Handles date-related operations and validations.

**OOP Concepts and Features:**

**Inheritance:** The Student and Teacher classes inherit from the Person class.
**Polymorphism:** Virtual functions in the Person class are overridden in derived classes.
**Operator Overloading:** Custom implementations for assignment (=) and equality (==) operators.
**File I/O:** Binary file operations ensure data persistence across program executions.
**Templates:** Generic functions for printing records of different types.
**Error Handling:** Extensive use of try-catch blocks and custom exception handling.

**Prerequisites**

C++ compiler (e.g., GCC, Clang, MSVC)
Git (for cloning the repository)

**Installation**

_Clone the repository:_

git clone https://github.com/Maryam-Amir00/OOP-PROJECT-University_Management_System.git

_Navigate to the project directory:_

cd OOP-PROJECT-University_Management_System

_Compile the source files:_

g++ -o university_system main.cpp admin_imp.cpp student_imp.cpp teacher_imp.cpp person_imp.cpp date_imp.cpp

_Run the executable:_

./university_system

**Usage**

The system provides a command-line interface with the following panels:

**Admin Panel:**

Manage student and teacher records
Perform CRUD operations on student and teacher data

**Student Panel:**

Check personal information
View assigned courses
Verify existence in the system

**Teacher Panel:**

Check personal information
Verify existence in the system

**Data Persistence**

Student and teacher data are stored in binary files (student.dat and teacher.dat) to ensure data persistence across program executions.

**Error Handling**

**The system includes robust error handling, such as:**

Input validation for all user inputs

Exception handling for file operations

Graceful handling of end-of-file (EOF) conditions

Custom exception messages for different error scenarios

**Code Highlights**

Use of const methods and parameters for improved code safety
Implementation of copy constructors and assignment operators
Overloading of stream insertion (<<) and extraction (>>) operators
Use of friend functions for non-member operator overloading

**Future Enhancements**

Implement a graphical user interface (GUI)
Add advanced search and filter options for records
Implement a logging system to track changes
Enhance security features, including user authentication

**Contributing**

Contributions to the University Management System are welcome. Please feel free to fork the repository, make changes, and submit a pull request.
