#pragma once

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
private:
	int m_numerator;
	int m_denominator;

	Fraction();

	Fraction(int num, int den);

	Fraction(int givenInt);

	Fraction(const Fraction& fr);

public:

	static Fraction* getInstance(int a, int b) {
		static Fraction fr(a, b);

		return &fr;
	}

	void output();
};

#endif // !_FRACTION_H