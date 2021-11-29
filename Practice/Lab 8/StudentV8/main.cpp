#include <iostream>
#include <string>
#include "Student.h"

int main() {
    Student* s1 = Student::Parse("Nguyen Van Loc");
    std::cout << s1->getFullName() << "\n";
    delete s1;

    Student* s2 = Student::Parse("Le Nguyen Huyen Tran");
    std::cout << s2->getFullName() << "\n";
    delete s2;

    return 0;
}