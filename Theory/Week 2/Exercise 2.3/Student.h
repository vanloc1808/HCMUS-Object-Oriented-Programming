#pragma once
#include <string>

class Student {
private:
	std::string fullName;
	double literaturePoint;
	double mathPoint;
public:
	void input();

	void output();

	std::string getFullName();

	double getLiteraturePoint();

	double getMathPoint();

	void assignFullName(std::string newFullName);

	void assignLiteraturePoint(double newLiteraturePoint);

	void assignMathPoint(double newMathPoint);

	double countAveragePoint();

	int classify();
};
