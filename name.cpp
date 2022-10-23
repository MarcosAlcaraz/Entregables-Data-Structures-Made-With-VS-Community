//Librerias de compilador
#include<iostream>
#include<string>
//Librerias de Usuario
#include "name.hpp"

using namespace std;

//Constructor Normal
Name::Name() {}

//Constructor Menos Normal
Name::Name(const Name& n) : name(n.name), lastName(n.lastName) {}

Name::~Name() {}

//Getters
//Get de Nombre
string Name::getName() const {
    return name;
}

//Get de Apellidos
string Name::getLastName() const {
    return lastName;
}

//Setters
//Set de Nombre(s)
void Name::setName(const string& n) {
    name = n;
}

//Set de Apellidos
void Name::setLastName(const string& ln) {
    lastName = ln;
}

//Impresi�n de Nombre
string Name::toString() const {
    string cadena;
    cadena += getLastName() + " " + getName();
    return cadena;
}

//Operador Asignaci�n
Name& Name::operator = (const Name& n) {
    name = n.name;
    lastName = n.lastName;

    return *this;
}

//Operador Igualdad
bool Name::operator == (const Name& t) const {
    return toString() == t.toString();
}

//Operador Es Diferente
bool Name::operator != (const Name& t) const {
    return toString() != t.toString();
}

//Operador Menor Que
bool Name::operator < (const Name& t) const {
    return toString() < t.toString();
}

//Operador Menor o Igual
bool Name::operator <= (const Name& t) const {
    return *this < t || *this == t;
}

//Operador Mayor Que
bool Name::operator > (const Name& t) const {
    return !(*this <= t);
}

//Operador Mayor o Igual
bool Name::operator >= (const Name& t) const {
    return !(*this < t);
}
