#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee {
private:
    std::string _fullname;
public:
    std::string FullName() { return _fullname; }
    void SetFullName(std::string value) { _fullname = value; }
public: 
    Employee() {

    }
    
    Employee(std::string fullname){
        _fullname = fullname;
    }

    virtual int CalcSalary() = 0;

    virtual int CalcBonus() = 0;

    virtual int CalcPenalty() = 0;

};

#endif // _EMPLOYEE_H_