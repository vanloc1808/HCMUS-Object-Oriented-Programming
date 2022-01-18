#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
        this->_year = 2021;
        this->_month = 1;
        this->_day = 1;
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
        this->_year = 2021;
        this->_month = 1;
        this->_day = 1;
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

std::istream& operator>>(std::istream& inDev, Date& d) {
    int day, m, y;
    inDev >> day >> m >> y;
    if (Date::isValidDate(y, m, day)) {
        d.setDate(y, m, day);
    } else {
        std::cout << "Invalid date!";
    }

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Date& d) {
    outDev << d.toString();

    return outDev;
}

Date* Date::Parse(std::string line) {
    std::string delim = "/";

    int startPos = 0;
    size_t foundPos = line.find(delim, startPos);

    std::vector<int> numbers;

    while (foundPos != std::string::npos) {
        int cnt = foundPos - startPos;

        std::string token = line.substr(startPos, cnt);

        numbers.push_back(std::stoi(token));

        startPos = foundPos + delim.length();
        foundPos = line.find(delim, startPos);
    }

    int cnt = line.length() - startPos;
    std::string token = line.substr(startPos, cnt);
    numbers.push_back(std::stoi(token));

    if (Date::isValidDate(numbers[2], numbers[1], numbers[0])) {
        return new Date(numbers[2], numbers[1], numbers[0]);
    } else {
        return nullptr;
    }
}

//do not check the validity of the date inside, other functions will do that
bool isValidStringDate(std::string line) {
    if (line.length() < 8 || line.length() > 10) {
        return false;
    }

    for (int i = 0; i < line.length(); i++) {
        if ((line[i] < '0' || line[i] > '9') && line[i] != '/') {
            return false;
        }
    }
    
    return true;
}

Date* Date::TryParse(std::string line) {
    try {
        if (!isValidStringDate(line)) {
            throw "Invalid string!\n";
        } else {
            return Date::Parse(line);
        }


    } catch (const char* message) {
        std::cout << message << "\n";
        return nullptr;
    }
}