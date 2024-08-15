#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include <stdexcept>
#include"person_int.h"
#include"student_int.h"
#include"date_int.h"
#include"teacher_int.h"
using namespace std;

#ifndef template_int
#define template_int
template <typename T>
void printRecords(const string& filePath) {
    ifstream file(filePath.c_str(), ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filePath);
    }

    T record;
    while (file.read(reinterpret_cast<char*>(&record), sizeof(T))) {
        record.print();
        cout <<"--------------------------------------------------------------"<< endl;
    }

    file.close();
}

#endif
