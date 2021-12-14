#include <iostream>
#include <vector>
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

std::string Student::toString() {
    return this->getFullName();
}

Student* Student::Parse(std::string line) {
    std::string delim = " ";

    int startPos = 0;
    size_t foundPos = line.find(delim, startPos);

    std::vector<std::string> words;

    while (foundPos != std::string::npos) {
        std::string token = line.substr(startPos, foundPos - startPos);
        words.push_back(token);
        startPos = foundPos + delim.length();
        foundPos = line.find(delim, startPos);
    }

    int cnt = line.length() - startPos;
    std::string token = line.substr(startPos, cnt);
    words.push_back(token);

    std::string lastName = words[0];
    std::string firstName = words[words.size() - 1];

    std::string middlename = "";
    for (int i = 1; i < words.size() - 1; i++) {
        middlename += words[i];
        
        if (i != words.size() - 2) {
            middlename += " ";
        }        
    }

    return new Student(lastName, middlename, firstName);
}