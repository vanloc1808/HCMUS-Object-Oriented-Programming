#include <iostream>
#include <string>
#include "Student.h"

int main() {
    Student s("Nguyen", "Van", "Loc");
    
    std::cout << "Full name: " << s.getFullName() << "\n";
    std::cout << "Last name: " << s.getLastName() << "\n";
    std::cout << "Middle name: " << s.getMiddleName() << "\n";
    std::cout << "First name: " << s.getFirstName() << "\n";

    s.setFirstName("Tran");
    s.setMiddleName("Huyen");
    s.setLastName("Le Nguyen");

    std::cout << "New full name: " << s.getFullName() << "\n"; 
    std::cout << "New last name: " << s.getLastName() << "\n";
    std::cout << "New middle name: " << s.getMiddleName() << "\n";
    std::cout << "New first name: " << s.getFirstName() << "\n";

    return 0;
}