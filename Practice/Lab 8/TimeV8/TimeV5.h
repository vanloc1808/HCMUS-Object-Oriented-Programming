#ifndef _TIMEV5_H
#define _TIMEV5_H

#include <string>

class Time {
private:
    int _hour;
    int _minute;
    int _second;

public:
    Time();

    Time(int hour, int minute, int second);

    //we don't need to define the copy constructor because we don't use pointer
    //the same to assigning operator

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setHour(int hour);

    void setMinute(int minute);

    void setSecond(int second);

    static bool isValidTime(int hour, int minute, int second);

    std::string toString() const;

    friend std::istream& operator>>(std::istream& inDev, Time& t);

    friend std::ostream& operator<<(std::ostream& outDev, const Time& t);

    static Time* Parse(std::string line);
};

#endif