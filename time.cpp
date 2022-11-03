#include<iostream>
#include<string>
#include<chrono>

#include "time.hpp"

using namespace std;

// EXITO
Time::Time() {
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t (today);

    struct tm* timeinfo = localtime(&tt);

    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;
}

// EXITO
Time::Time(const Time& t) : hour(t.hour), minute(t.minute), second(t.second) {}

// TESTEAR
Time::Time(const int& h, const int& m, const int& s) : Time()
{
    if (isValid(h, m, s)) {
        hour = h;
        minute = m;
        second = s;
    }
}

// EXITO
Time::~Time() { }

// EXITO
int Time::getHour() const {
    return hour;
}

// EXITO
int Time::getMinute() const {
    return minute;
}

// EXITO
int Time::getSecond() const {
    return second;
}

// TESTEAR
int Time::toInt() const
{
    return  (hour * 100) + (minute * 10) + second;
}

// EXITO
void Time::setHour(const int& h) {
    if(isValid(h, minute, second))
        hour = h;
}

// EXITO
void Time::setMinute(const int& m) {
    if (isValid(hour, m, second))
        minute = m;
}

// EXITO
void Time::setSecond(const int& s) {
    if (isValid(hour, minute, s))
        second = s;
}

// EXITO
string Time::toString() const {
    string cadena;
    if (getHour() < 10) {
        cadena += "0" + to_string(getHour());
    }
    else {
        cadena += to_string(getHour());
    }
    cadena += ":";
    if (getMinute() < 10) {
        cadena += "0" + to_string(getMinute());
    }
    else {
        cadena += to_string(getMinute());
    }
    cadena += ":";
    if (getSecond() < 10) {
        cadena += "0" + to_string(getSecond());
    }
    else {
        cadena += to_string(getSecond());
    }
    return cadena;
}

// EXITO
Time& Time::operator = (const Time& t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;

    return *this;
}

// TESTEAR
bool Time::isValid(const int& h, const int& m, const int& s) const
{
    return h <= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
}

// TESTEAR
bool Time::operator == (const Time& t) const {
    return toInt() == t.toInt();
}

// TESTEAR
bool Time::operator != (const Time& t) const {
    return toInt() != t.toInt();
}

// TESTEAR
bool Time::operator < (const Time& t) const {
    return toInt() < t.toInt();
}

// TESTEAR
bool Time::operator <= (const Time& t) const {
    return toInt() <= t.toInt();
}

// TESTEAR
bool Time::operator > (const Time& t) const {
    return toInt() > t.toInt();
}

// TESTEAR
bool Time::operator >= (const Time& t) const {
    return toInt() >= t.toInt();
}

// TESTEAR
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << to_string(t.getHour()) << endl;
    os << to_string(t.getMinute()) << endl;
    os << to_string(t.getSecond()) << endl;
    return os;
}

// TESTEAR
std::istream& operator>>(std::istream& is, Time& t)
{
    string myString;

    getline(is, myString);
    t.hour = stoi(myString);

    getline(is, myString);
    t.minute = stoi(myString);

    getline(is, myString);
    t.second = stoi(myString);

    return is;
}
