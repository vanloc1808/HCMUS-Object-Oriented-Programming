#include <iostream>
#include <string>
#include "Student.h"

//Function used to input a student.
//Enter the full name, Literature point, Mathematics point respectively.
void Student::input() {
	std::cout << "Enter full name: ";
	std::getline(std::cin, this->fullName);

	std::cout << "Enter Literature point: ";
	std::cin >> this->literaturePoint;

	std::cout << "Enter Mathematics point: ";
	std::cin >> this->mathPoint;
}

//Function used to output a student.
//Write the full name, Literature point, Mathematics point respectively.
void Student::output() {
	std::cout << "Full name: " << this->fullName << "\n";
	std::cout << "Literature point: " << this->literaturePoint << "\n";
	std::cout << "Mathematics point: " << this->mathPoint << "\n";
}

//Function used to get the full name of the current student.
std::string Student::getFullName() {
	return this->fullName;
}

//Function used to get the Literature point of the current student.
double Student::getLiteraturePoint() {
	return this->literaturePoint;
}

//Function used to get the Mathematics point of the current student.
double Student::getMathPoint() {
	return this->mathPoint;
}

//Function used to assign a new full name to the current student.
void Student::assignFullName(std::string newFullName) {
	this->fullName = newFullName;
}

//Function used to assign a new Literature point to the current student.
void Student::assignLiteraturePoint(double newLiteraturePoint) {
	this->literaturePoint = newLiteraturePoint;
}

//Function used to assign a new Mathematics point to the current student.
void Student::assignMathPoint(double newMathPoint) {
	this->mathPoint = newMathPoint;
}

//Function used to calculate the average point of the current student.
//Formula: (Literature point + Mathematics point) / 2.
double Student::countAveragePoint() {
	double averagePoint = (this->literaturePoint + this->mathPoint) / 2;
	return averagePoint;
}

//Function used to classify the current student.
//Return 1 if he/she is excellent.
//Return 2 if he/she is good.
//Return 3 if he/she is average.
//Return 4 if he/she is below average.
int Student::classify() {
	double averagePoint = this->countAveragePoint();

	if (averagePoint >= 8.00) {
		return 1;
	}

	if (averagePoint >= 7.00) {
		return 2;
	}

	if (averagePoint >= 5.00) {
		return 3;
	}

	return 4;
}