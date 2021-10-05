#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

class Student {
private:
    std::string _lastName;
    std::string _middleName;
    std::string _firstName;

public:
    //default constructor
    Student();

    //fully-parameterized constructor
    Student(std::string l, std::string m, std::string f);

    //copy constructor
    Student(const Student& s);

    //getter for full name and each parts of the name
    //use the order in English
    //for example, my name is Nguyen Van Loc
    //Nguyen: last name
    //Van: middle name
    //Loc: first name
    std::string getFullName();

    std::string getLastName();

    std::string getMiddleName();

    std::string getFirstName();

    //setter for name;
    void setFullName(std::string  l, std::string m, std::string f);
    
    void setLastName(std::string l);

    void setMiddleName(std::string m);

    void setFirstName(std::string f);
};
#endif