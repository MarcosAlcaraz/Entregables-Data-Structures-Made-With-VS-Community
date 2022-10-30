#include<iostream>
#include<string>
#include<chrono>

#include "time.hpp"

using namespace std;

// EXITO
Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

// EXITO
Time::Time(const Time& t) : hour(t.hour), minute(t.minute), second(t.second) {}

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

// EXITO
void Time::setHour(const int& h) {
    hour = h;
}

// EXITO
void Time::setMinute(const int& m) {
    minute = m;
}

// EXITO
void Time::setSecond(const int& s) {
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
bool Time::operator == (const Time& t) const {
    return toString() == t.toString();
}

// TESTEAR
bool Time::operator != (const Time& t) const {
    return toString() != t.toString();
}

// TESTEAR
bool Time::operator < (const Time& t) const {
    return toString() < t.toString();
}

// TESTEAR
bool Time::operator <= (const Time& t) const {
    return *this < t || *this == t;
}

// TESTEAR
bool Time::operator > (const Time& t) const {
    return !(*this <= t);
}

// TESTEAR
bool Time::operator >= (const Time& t) const {
    return !(*this < t);
}
