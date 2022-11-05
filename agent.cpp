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

// TESTEAR (NO es posible almacenar Llamadas)
ClientList Agent::getClientList() const {
    return clientList;
}

// TESTEAR (NO es posible almacenar Llamadas)
string Agent::toString(bool myBool) const {
    string result;

    result += "\nNombre: " + getName().toString();
    result += "\nEspecialidad: " + getSpecialty();
    result += "\nNumero de Empleado: " + getEmployeeNumber();
    result += "\nNumero de Extension: " + getExtensionNumber();
    result += "\nHora de Entrada: " + getStartTime().toString();
    result += "\nHora de Salida: " + getEndTime().toString();
    result += "\nHoras Extra: " + getExtraHours() + "\n";

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

ostream& operator << (ostream& os, const Agent& a)
{
    string x = a.getEmployeeNumber();
    os << a.getExtensionNumber() << endl;
    os << a.getSpecialty() << endl;
    os << a.getEmployeeNumber() << endl;
    os << a.getExtraHours() << endl;
    os << a.getName() << endl;
    os << a.getStartTime() << endl;
    os << a.getEndTime() << endl;
    a.getClientList().writeToDisk(x);
    return os;
}

istream& operator >> (istream& is, Agent& a)
{
    string x = a.getEmployeeNumber();
    is >> a.extensionNumber;
    is >> a.specialty;
    is >> a.employeeNumber;
    is >> a.extraHours;
    is >> a.name;
    is >> a.startTime;
    is >> a.endTime;
    a.getClientList().readFromDisk(x);
    return is;
}
