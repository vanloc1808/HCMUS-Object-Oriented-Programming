#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Student.h"

//fully-parameterized constructor with full name, Literature point and Mathematics point.
Student::Student(const char* name, float lit, float mat) {
	//set the full name.
	int len = strlen(name);
	this->m_fullName = new char[len + 1];
	strcpy(this->m_fullName, name);

	//set the points.
	this->m_literature = lit;
	this->m_math = mat;
}

//partly parameterized constructor with name only.
Student::Student(const char* name) {
	int len = strlen(name);
	this->m_fullName = new char[len + 1];
	strcpy(this->m_fullName, name);

	this->m_literature = 0;
	this->m_math = 0;
}

//copy constructor.
Student::Student(const Student& st) {
	//copy the name.
	int len = strlen(st.m_fullName);
	this->m_fullName = new char[len + 1];
	strcpy(this->m_fullName, st.m_fullName);

	//copy the points
	this->m_literature = st.m_literature;
	this->m_math = st.m_math;
}

//destructor, free the pointer.
Student::~Student() {
	delete[]this->m_fullName;
	this->m_fullName = NULL;
}

//function used to output a student.
void Student::output() {
	std::cout << "Name: " << this->m_fullName << "\n";
	std::cout << "Literature point: " << this->m_literature << "\n";
	std::cout << "Mathematics point: " << this->m_math << "\n";
}