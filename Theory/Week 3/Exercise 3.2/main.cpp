#include <iostream>
#include "Student.h"

int main()
{
    Student st1("Lionel Messi");
    Student st2("Lionel Messi", 10, 10);
    Student st3(st2);

    st1.output();
    st2.output();
    st3.output();

    return 0;
}