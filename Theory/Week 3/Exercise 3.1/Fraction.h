#pragma once

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction();

	Fraction(int num, int den);

	Fraction(int givenInt);

	Fraction(const Fraction& fr);

	void output();
};

#endif // !_FRACTION_H