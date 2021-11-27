#include <iostream>
#include <string>
#include "Student.h"

Student::Student() {
    this->_lastName = "";
    this->_middleName = "";
    this->_firstName = "";
}

Student::Student(std::string l, std::string m, std::string f) {
    this->_lastName = l;
    this->_middleName = m;
    this->_firstName = f;    
}

Student::Student(const Student& s) {
    this->_lastName = s._lastName;
    this->_middleName = s._middleName;
    this->_firstName = s._firstName;
}

Student::~Student() {
    
}

std::string Student::getFullName() {
    std::string ans = this->_lastName + " " + this->_middleName + " " + this->_firstName;

    return ans;
}

std::string Student::getLastName() {
    std::string ans = this->_lastName;
    
    return ans;
}

std::string Student::getMiddleName() {
    std::string ans = this->_middleName;
    
    return ans;
}

std::string Student::getFirstName() {
    std::string ans = this->_firstName;
    
    return ans;
}

void Student::setFullName(std::string  l, std::string m, std::string f) {
    this->_lastName = l;
    this->_middleName = m;
    this->_firstName = f;
}

void Student::setLastName(std::string l) {
    this->_lastName = l;
}

void Student::setMiddleName(std::string m) {
    this->_middleName = m;
}

void Student::setFirstName(std::string f) {
    this->_firstName = f;
}