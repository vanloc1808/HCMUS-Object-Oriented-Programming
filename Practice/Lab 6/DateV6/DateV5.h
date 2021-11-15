#ifndef _DATEV5_H
#define _DATEV5_H

#include <string>

class Date {
private:
    int _year;
    int _month;
    int _day;

public:
    Date();

    Date(int year, int month, int day);

    //we don't need to define the copy constructor because we don't use pointer
    //the same to assigning operator

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    void setDate(int year, int month, int day);

    std::string toString() const;

    static bool isLeapYear(int year);

    static bool isValidDate(int year, int month, int day);

    friend std::istream& operator>>(std::istream& inDev, Date& d);

    friend std::ostream& operator<<(std::ostream& outDev, const Date& d);
};

#endif