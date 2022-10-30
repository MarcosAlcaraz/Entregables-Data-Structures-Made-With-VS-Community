#include <iostream>

#include "agent.hpp"

using namespace std;

// EXITO
Agent::Agent() {}

// EXITO
Agent::~Agent() { }

// EXITO
Agent::Agent(const Agent& a) : extensionNumber(a.extensionNumber), specialty(a.specialty), employeeNumber(a.employeeNumber), extraHours(a.extraHours), name(a.name), startTime(a.startTime), endTime(a.endTime), clientList(a.clientList) {}

// EXITO
string Agent::getEmployeeNumber() const {
    return employeeNumber;
}

// EXITO
string Agent::getExtensionNumber() const {
    return extensionNumber;
}

// EXITO
string Agent::getSpecialty() const {
    return specialty;
}

// EXITO
string Agent::getExtraHours() const {
    return extraHours;
}

// EXITO
Name Agent::getName() const {
    return name;
}

// EXITO
Time Agent::getStartTime() const {
    return startTime;
}

// EXITO
Time Agent::getEndTime() const {
    return endTime;
}

// ERROR
ClientList Agent::getClientList() const {
    return clientList;
}

// ERROR
string Agent::toString(bool myBool) const {
    string result;
    result += "Nombre: " + getName().toString() + "\nEspecialidad: " + getSpecialty() + "\nNumero de Empleado: " + getEmployeeNumber() + "\nNumero de Extension: " + getExtensionNumber() + "\nHora de Entrada: " + getStartTime().toString() + "\nHora de Salida: " + getEndTime().toString() + "\nHoras Extra: " + getExtraHours() + "\n";

    if (myBool == true) {
        result += "\n\tLista de Clientes Atendidos:\n" + getClientList().toString() + "\n\n";
    }
    return result;
}

// EXITO
void Agent::setExtensionNumber(const string& exn) {
    extensionNumber = exn;
}

// EXITO
void Agent::setSpeciality(const string& s) {
    specialty = s;
}

// EXITO
void Agent::setName(const Name& n) {
    name = n;
}

// EXITO
void Agent::setEmployeeNumber(const string& en) {
    employeeNumber = en;
}

// EXITO
void Agent::setExtraHours(const string& exh) {
    extraHours = exh;
}

// EXITO
void Agent::setStartTime(const Time& st) {
    startTime = st;
}

// EXITO
void Agent::setEndTime(const Time& et) {
    endTime = et;
}

// EXITO
Agent& Agent::operator = (const Agent& a) {
    extensionNumber = a.extensionNumber;
    specialty = a.specialty;
    employeeNumber = a.employeeNumber;
    extraHours = a.extraHours;
    name = a.name;
    startTime = a.startTime;
    endTime = a.endTime;
    clientList = a.clientList;

    return *this;
}

// TESTEAR
bool Agent::operator == (const Agent& a) const {
    return employeeNumber == a.employeeNumber;
}

// TESTEAR
bool Agent::operator != (const Agent& a) const {
    return !(*this == a);
}

// TESTEAR
bool Agent::operator < (const Agent& a) const {
    return employeeNumber < a.employeeNumber;
}

// TESTEAR
bool Agent::operator <= (const Agent& a) const {
    return *this < a || *this == a;
}

// TESTEAR
bool Agent::operator > (const Agent& a) const {
    return !(*this <= a);
}

// TESTEAR
bool Agent::operator >= (const Agent& a) const {
    return !(*this < a);
}

/*
std::ostream& operator<<(std::ostream&, const Agent&)
{
    // TODO: Insertar una instrucción "return" aquí
}

std::istream& operator>>(std::istream&, Agent&)
{
    // TODO: Insertar una instrucción "return" aquí
}
*/