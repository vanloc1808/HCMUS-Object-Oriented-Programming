#include <iostream>
#include <string>
#include "Student.h"
#include "DemoProcess.h"

using namespace std;

void showMenu() {
	cout << "Here is the menu of the program.\n";
	cout << "1. Get full name.\n";
	cout << "2. Get Literature point.\n";
	cout << "3. Get Mathematics point.\n";
	cout << "4. Assign a new full name.\n";
	cout << "5. Assign a new Literature point.\n";
	cout << "6. Assign a new Mathematics point.\n";
	cout << "7. Calculate the average point.\n";
	cout << "8. Classify a student.\n";
}

void getFullNameProcess() {
	Student student;

	student.input();

	string fullName = student.getFullName();

	cout << "Full name is: " << fullName << "\n";
}

void getLiteratureProcess() {
	Student student;

	student.input();

	double literaturePoint = student.getLiteraturePoint();

	cout << "Literature point is: " << literaturePoint << "\n";
}

void getMathProcess() {
	Student student;

	student.input();

	double mathPoint = student.getMathPoint();

	cout << "Literature point is: " << mathPoint << "\n";
}

void newNameProcess() {
	Student student;

	student.input();

	string newFullName;
	cout << "Enter new full name: ";
	getline(cin, newFullName);
	student.assignFullName(newFullName);

	cout << "After changing name\n: ";
	student.output();
	cout << "\n";
}

void newLiteratureProcess() {
	Student student;

	student.input();

	double newLiteraturePoint;
	cout << "Enter new Literature point: ";
	cin >> newLiteraturePoint;
	student.assignLiteraturePoint(newLiteraturePoint);

	cout << "After changing Literature point\n: ";
	student.output();
	cout << "\n";
}

void newMathProcess() {
	Student student;

	student.input();

	double newMathPoint;
	cout << "Enter new Mathematics point: ";
	cin >> newMathPoint;
	student.assignLiteraturePoint(newMathPoint);

	cout << "After changing Mathematics point\n: ";
	student.output();
	cout << "\n";
}

void averageProcess() {
	Student student;

	student.input();

	double averagePoint = student.countAveragePoint();

	cout << "The average point is: " << averagePoint << "\n";
}

void classifyProcess() {
	Student student;

	student.input();

	int type = student.classify();

	cout << "This student is: ";

	switch (type)
	{
	case 1:
		cout << "excellent.\n";
		break;

	case 2:
		cout << "good.\n";
		break;

	case 3:
		cout << "average.\n";
		break;

	case 4:
		cout << "below average.\n";
		break;
	}
}
