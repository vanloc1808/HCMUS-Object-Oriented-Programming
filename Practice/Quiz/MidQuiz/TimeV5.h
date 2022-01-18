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

    Time(const Time& t);

    ~Time() {

    }

    Time& operator=(const Time& t);

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setHour(int hour);

    void setMinute(int minute);

    void setSecond(int second);

    void decreaseHour(int h);

    void decreaseMinute(int m);

    void decreaseSecond(int s);

    static bool isValidTime(int hour, int minute, int second);

    std::string toString() const;

    friend std::istream& operator>>(std::istream& inDev, Time& t);

    friend std::ostream& operator<<(std::ostream& outDev, const Time& t);

    friend void print(const Time& t);
};

#endif