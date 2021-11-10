#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "DateV5.h"

//Reference from https://topdev.vn/blog/date-va-time-trong-c/

//default constructor
//constructs a time object with the current time
Date::Date() {
    time_t now = time(0);

    tm *ltm = localtime(&now);

    this->_year = ltm->tm_year + 1900;
    this->_month = ltm->tm_mon + 1;
    this->_day = ltm->tm_mday;
}

Date::Date(int year, int month, int day) {
    if (Date::isValidDate(year, month, day)) {       
        this->_year = year;
        this->_month = month;
        this->_day = day;
    } else {
        std::cout << "Invalid date!!\n";
    }
}

 int Date::getYear() const {
    return this->_year;
 }

 int Date::getMonth() const {
    return this->_month;
 }

 int Date::getDay() const {
    return this->_day;
 }

 void Date::setDate(int year, int month, int day) {
    if (Date::isValidDate(year, month, day)) {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    } else {
        std::cout << "Invalid date!!\n";
    }
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << this->_day << "/" << this->_month << "/" << this->_year;
    return ss.str();
}

bool Date::isLeapYear(int year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

//here we don't define the condition year >= 0,
//because I define that when year is negative, 
//it is the year Before Christ (BC)
bool Date::isValidDate(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }
    }
    return true;
}