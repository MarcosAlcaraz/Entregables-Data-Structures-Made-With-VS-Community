#ifndef TIME_HPP
#define TIME_HPP

#include<iostream>

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    Time(const Time&);
    ~Time();

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void setHour(const int&);
    void setMinute(const int&);
    void setSecond(const int&);

    std::string toString() const;

    Time& operator = (const Time&);

    bool operator == (const Time&) const;
    bool operator != (const Time&) const;
    bool operator < (const Time&) const;
    bool operator <= (const Time&) const;
    bool operator > (const Time&) const;
    bool operator >= (const Time&) const;

    friend std::ostream& operator << (std::ostream&, const Time&);
    friend std::istream& operator >> (std::istream&, Time&);
};

#endif // TIME_HPP
