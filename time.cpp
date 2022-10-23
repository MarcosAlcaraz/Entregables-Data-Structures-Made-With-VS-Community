//Librerias de compilador
#include<iostream>
#include<string>
#include<chrono>
//Librerias de Usuario
#include "time.hpp"

using namespace std;

//Constructor Normal
Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

//Constructor Menos Normal
Time::Time(const Time& t) : hour(t.hour), minute(t.minute), second(t.second) {}

Time::~Time() { }

//Getters
//Get de Hora
int Time::getHour() const {
    return hour;
}

//Get de Minuto
int Time::getMinute() const {
    return minute;
}

//Get de Segundo
int Time::getSecond() const {
    return second;
}

//Setters
//Set de Hora
void Time::setHour(const int& h) {
    hour = h;
}

//Set de Minuto
void Time::setMinute(const int& m) {
    minute = m;
}

//Set de segundo
void Time::setSecond(const int& s) {
    second = s;
}

//Impresi�n de Tiempo
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

//Operador Asignaci�n
Time& Time::operator = (const Time& t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;

    return *this;
}

//Operador Igualdad
bool Time::operator == (const Time& t) const {
    return toString() == t.toString();
}

//Operador Es Diferente
bool Time::operator != (const Time& t) const {
    return toString() != t.toString();
}

//Operador Menor Que
bool Time::operator < (const Time& t) const {
    return toString() < t.toString();
}

//Operador Menor o Igual
bool Time::operator <= (const Time& t) const {
    return *this < t || *this == t;
}

//Operador Mayor Que
bool Time::operator > (const Time& t) const {
    return !(*this <= t);
}

//Operador Mayor o Igual
bool Time::operator >= (const Time& t) const {
    return !(*this < t);
}
