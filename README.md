# University Management System

## Description

The University Management System is a robust C++ application designed to streamline the management of student and teacher records within a university environment. It provides a user-friendly interface for administrators, students, and teachers, allowing them to perform various operations and access pertinent information efficiently.

Developed as part of the Object-Oriented Programming (OOP) course, this project showcases key OOP principles such as inheritance, polymorphism, operator overloading, and file handling.

## Features

### Admin Panel
- **Student Management:**
  - Add new students
  - View existing student records
  - Update student information
  - Delete student records

- **Teacher Management:**
  - Add new teachers
  - View existing teacher records
  - Update teacher information
  - Delete teacher records

### Student Panel
- Access personal information
- View assigned courses based on department
- Verify existence in the system

### Teacher Panel
- Access personal information
- Verify existence in the system

### General Features
- **Date handling** for accurate record-keeping
- **File-based storage** for persistent data management
- **Robust input validation** and error handling
- Custom implementations of copy constructors, assignment operators, and equality operators
- **Template functions** for flexible and reusable code

## Project Structure

The project is organized into several key components:

- **`panel_imp.h`**: Implements the main panels (Admin, Student, Teacher) and user interface.
- **`admin_imp.cpp` & `admin_int.h`**: Implementation and interface for the Admin class.
- **`student_imp.cpp` & `student_int.h`**: Implementation and interface for the Student class.
- **`teacher_imp.cpp` & `teacher_int.h`**: Implementation and interface for the Teacher class.
- **`person_imp.cpp` & `person_int.h`**: Implementation and interface for the base Person class.
- **`date_imp.cpp` & `date_int.h`**: Implementation and interface for the Date class.
- **`template_int.h`**: Contains template functions for generic operations, like printing records.

## Key Classes

- **Person**: Base class for students and teachers, managing common personal information.
- **Student**: Derived from Person, handles student-specific data and operations.
- **Teacher**: Derived from Person, handles teacher-specific data and operations.
- **Admin**: Manages administrative functions for both students and teachers.
- **Date**: Handles date-related operations and validations.

## OOP Concepts and Features

- **Inheritance**: The Student and Teacher classes inherit from the Person class.
- **Polymorphism**: Virtual functions in the Person class are overridden in derived classes.
- **Operator Overloading**: Custom implementations for assignment (`=`) and equality (`==`) operators.
- **File I/O**: Binary file operations ensure data persistence across program executions.
- **Templates**: Generic functions for printing records of different types.
- **Error Handling**: Extensive use of `try-catch` blocks and custom exception handling.

## Prerequisites

- C++ compiler (e.g., GCC, Clang, MSVC)
- Git (for cloning the repository)

## Installation

**Clone the repository:**

git clone https://github.com/Maryam-Amir00/OOP-PROJECT-University_Management_System.git

**Navigate to the project directory:**

cd OOP-PROJECT-University_Management_System

**Compile the source files:**

g++ -o university_system main.cpp admin_imp.cpp student_imp.cpp teacher_imp.cpp person_imp.cpp date_imp.cpp

Run the executable:

./university_system


## Usage

The system provides a command-line interface with the following panels:

### Admin Panel
- Manage student and teacher records
- Perform CRUD operations on student and teacher data

### Student Panel
- Check personal information
- View assigned courses
- Verify existence in the system

### Teacher Panel
- Check personal information
- Verify existence in the system


## Data Persistence

Student and teacher data are stored in binary files (`student.dat` and `teacher.dat`) to ensure data persistence across program executions.

## Error Handling

The system includes robust error handling mechanisms, including:

- **Input Validation:** Ensures all user inputs are valid before processing.
- **Exception Handling:** Manages file operations and other critical processes.
- **EOF Handling:** Gracefully handles end-of-file (EOF) conditions during file read/write operations.
- **Custom Exception Messages:** Provides specific error messages for different error scenarios, aiding in debugging and user guidance.


## Code Highlights

- **Const Methods & Parameters:** Utilized for enhanced code safety and immutability.
- **Copy Constructors & Assignment Operators:** Implemented to ensure proper copying and assignment of objects.
- **Operator Overloading:** Overloaded stream insertion (`<<`) and extraction (`>>`) operators for easy input/output.
- **Friend Functions:** Used for non-member operator overloading to access private/protected class members.

## Future Enhancements

- **GUI Implementation:** Develop a graphical user interface to improve user experience.
- **Advanced Search & Filter:** Add functionality to search and filter records more effectively.
- **Logging System:** Implement a system to track changes and user actions within the application.
- **Enhanced Security:** Introduce user authentication and other security features.

## Contributing

Contributions to the University Management System are welcome. Feel free to fork the repository, make your changes, and submit a pull request. Please ensure that your code adheres to the existing style and is well-documented.

