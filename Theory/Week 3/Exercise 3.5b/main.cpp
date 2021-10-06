/*I googled and found singleton pattern; they told me that I need to changed all the constructors to private.
After that, write a static function, this return a pointer of type Fraction*.
I tried to return Fraction but it bugged, when I changed to Fraction*, it runned correctly.*/

#include <iostream>
#include "Fraction.h"

int main() {
	Fraction* fr1 = Fraction::getInstance(1, 2);
	fr1->output();

	Fraction* fr2 = Fraction::getInstance(2, 3);
	fr2->output();

	return 0;
}