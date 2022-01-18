#pragma once

#ifndef _STUDENT_H
#define _STUDENT_H

class Student {
private:
	char* m_fullName;
	float m_literature;
	float m_math;

public:
	Student(const char* name, float lit, float mat);

	Student(const char* name);

	Student(const Student& st);

	~Student();

	void output();
};

#endif // !_STUDENT_H