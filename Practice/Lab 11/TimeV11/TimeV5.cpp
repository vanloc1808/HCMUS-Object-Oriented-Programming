#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "TimeV5.h"

//Reference from https://topdev.vn/blog/date-va-time-trong-c/

//default constructor
//constructs a time object with the current time
Time::Time() {
    time_t now = time(0);

    tm *ltm = localtime(&now);

    this->_hour = ltm->tm_hour;
    this->_minute = ltm->tm_min;
    this->_second = ltm->tm_sec;
}

Time::Time(int hour, int minute, int second) {
    if (Time::isValidTime(hour, minute, second)) {       
        this->_hour = hour;
        this->_minute = minute;
        this->_second = second;
    } else {
        std::cout << "Invalid time!!\n";
    }
}

 int Time::getHour() const {
    return this->_hour;
 }

 int Time::getMinute() const {
    return this->_minute;
 }

 int Time::getSecond() const {
    return this->_second;
 }

 void Time::setHour(int hour) {
     if (hour >= 0 && hour <= 23) {
         this->_hour = hour;
     } else {
         std::cout << "Invalid hour!\n";
     }
 }

 void Time::setMinute(int minute) {
     if (minute >= 0 && minute <= 59) {
         this->_minute = minute;
     } else { 
        std::cout << "Invalid minute!\n";
     }
 }

 void Time::setSecond(int second) {
     if (second >= 0 && second <= 59) {
         this->_second = second;
     } else { 
        std::cout << "Invalid second!\n";
     }
} 

void Time::addHour(int h) {
    if (h < 0) {
        std::cout << "Invalid parameter\n";
    } else {
        this->_hour += h;
        this->_hour %= 24;
    }
}

void Time::addMinute(int m) {
    if (m < 0) {
        std::cout << "Invalid parameter\n";
    } else {
        int h = m / 60;
        m = m % 60;

        this->addHour(h);

        this->_minute += m;
        this->_minute %= 60;
    }
}

void Time::addSecond(int s) {
    if (s < 0) {
        std::cout << "Invalid parameter\n";
    } else {
        int m = s / 60;
        s = s % 60;

        this->addMinute(m);

        this->_second += s;
        this->_second %= 60;
    }
}

void Time::decreaseHour(int h) {
    if (h < 0) {
        std::cout << "Invalid parameter\n";
    } else {
        if (this->_hour - h >= 0) {
            this->_hour -= h;
        } else {
            int temp = this->_hour - h;
            temp = (temp % 24 + 24) % 24;
            this->_hour = temp;
        }
    }
}

void Time::decreaseMinute(int m) {
    if (m < 0) {
        std::cout << "Invalid parameter\n";
    } else {
        int h = m / 60;
        m = m % 60;

        this->decreaseHour(h);

        if (this->_minute - m >= 0) {
            this->_minute -= m;
        } else {
            int temp = this->_minute - m;
            temp = (temp % 60 + 60) % 60;
            this->_minute = temp;
            this->decreaseHour(1);
        }
    }
}

void Time::decreaseSecond(int s) {
    if (s < 0) {
        std::cout << "Invalid parameter\n";
    } else {
        int h = s / 3600;
        s = s % 3600;
        
        int m = s / 60;
        s = s % 60;

        this->decreaseHour(h);
        this->decreaseMinute(m);

        if (this->_second - s >= 0) {
            this->_second -= s;
        } else {
            int temp = this->_second - s;
            temp = (temp % 60 + 60) % 60;

            this->_second = temp;
            this->decreaseMinute(1);
        }
    }
}

bool Time::isValidTime(int hour, int minute, int second) {
    bool h = (hour >= 0) && (hour <= 23);
    if (!h) {
        return false;
    }

    bool m = (minute >= 0) && (minute <= 59);

    if (!m) {
        return false;
    }

    bool s = (second >= 0) && (second <= 59);

    if (!s) {
        return false;
    }

    return true;
}

std::string Time::toString() const {
    std::stringstream ss;

    ss << this->_hour << ":" << this->_minute << ":" << this->_second;

    return ss.str();
}

std::istream& operator>>(std::istream& inDev, Time& t) {
    int h, m, s;
    inDev >> h >> m >> s;
    
    if (Time::isValidTime(h, m, s)) {
        t._hour = h;
        t._minute = m;
        t._second = s;
    } else {
        std::cout << "Invalid time!\n";
    }

    return inDev;
}

std::ostream& operator<<(std::ostream& outDev, const Time& t) {
    outDev << t.toString();

    return outDev;
}

Time* Time::Parse(std::string line) {
    std::string delim = ":";

    std::vector<int> times;

    int startPos = 0;
    size_t foundPos = line.find(delim, startPos);

    while (foundPos != std::string::npos) {
        int cnt = foundPos - startPos;
        std::string token = line.substr(startPos, cnt);

        int x = std::stoi(token);
        if (times.size() == 0) {
            if (x >= 0 || x <= 23) {
                times.push_back(x);
            }
        } else {
            if (x >= 0 || x <= 59) {
                times.push_back(x);
            }
        }

        startPos = foundPos + delim.length();
        foundPos = line.find(delim, startPos);
    }

    int cnt = line.length() - startPos;
    std::string token = line.substr(startPos, cnt);

    int x = std::stoi(token);
    if (times.size() == 0) {
        if (x >= 0 || x <= 23) {
            times.push_back(x);
        }
    } else {
        if (x >= 0 || x <= 59) {
            times.push_back(x);
        }
    }

    if (times.size() == 3) {
        Time* t = new Time(times[0], times[1], times[2]);
        return t;
    } else {
        return nullptr;
    }
}

std::string GMTTime::toString(int gmt) const {
    Time temp = *this;
    if (gmt < 0) {
        temp.decreaseHour(gmt);
    } else if (gmt > 0) {
        temp.addHour(gmt);
    }

    return temp.toString();
}