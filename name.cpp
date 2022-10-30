#include<iostream>
#include<string>

#include "name.hpp"

using namespace std;

// EXITO
Name::Name() {}

// EXITO
Name::Name(const Name& n) : name(n.name), lastName(n.lastName) {}

// EXITO
Name::~Name() {}

// EXITO
string Name::getName() const {
    return name;
}

// EXITO
string Name::getLastName() const {
    return lastName;
}

// EXITO
void Name::setName(const string& n) {
    name = n;
}

// EXITO
void Name::setLastName(const string& ln) {
    lastName = ln;
}

// EXITO
string Name::toString() const {
    string cadena;
    cadena += getLastName() + " " + getName();
    return cadena;
}

// EXITO
Name& Name::operator = (const Name& n) {
    name = n.name;
    lastName = n.lastName;

    return *this;
}

// TESTEAR
bool Name::operator == (const Name& t) const {
    return toString() == t.toString();
}

// TESTEAR
bool Name::operator != (const Name& t) const {
    return toString() != t.toString();
}

// TESTEAR
bool Name::operator < (const Name& t) const {
    return toString() < t.toString();
}

// TESTEAR
bool Name::operator <= (const Name& t) const {
    return *this < t || *this == t;
}

// TESTEAR
bool Name::operator > (const Name& t) const {
    return !(*this <= t);
}

// TESTEAR
bool Name::operator >= (const Name& t) const {
    return !(*this < t);
}
