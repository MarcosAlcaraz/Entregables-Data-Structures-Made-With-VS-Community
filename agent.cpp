//Librer�as del compilador
#include <iostream>
//Librer�as de usuario
#include "agent.hpp"

using namespace std;

//Constructor normalito
Agent::Agent() { }

Agent::~Agent() { }

//Constructor un poco menos normalito
Agent::Agent(const Agent& a) : extensionNumber(a.extensionNumber), specialty(a.specialty), employeeNumber(a.employeeNumber), extraHours(a.extraHours), name(a.name), startTime(a.startTime), endTime(endTime) {}

//Getters
//Get De N�mero de empleado
string Agent::getEmployeeNumber() const {
    return employeeNumber;
}

//Get de N�mero de Extensi�n
string Agent::getExtensionNumber() const {
    return extensionNumber;
}

//Get de Especialidad
string Agent::getSpecialty() const {
    return specialty;
}

//Get de Horas Extra
string Agent::getExtraHours() const {
    return extraHours;
}

//Get de la clase Nombre
Name Agent::getName() const {
    return name;
}

//Get de la clase Tiempo para conseguir la hora de Entrada
Time Agent::getStartTime() const {
    return startTime;
}

//Get de la clase Tiempo para conseguir la hora de Salida
Time Agent::getEndTime() const {
    return endTime;
}

//Get de la lista de clientes
ClientList Agent::getClientList() const {
    return clientList;
}

//Impresi�n de toda la informaci�n del Agente
string Agent::toString(bool myBool) const {
    string cadena;

    cadena += "Nombre: " + getName().toString() + "\nEspecialidad: " + getSpecialty() + "\nNumero de Empleado: " + getEmployeeNumber() + "\nNumero de Extension: " + getExtensionNumber() + "\nHora de Entrada: " + getStartTime().toString() + "\nHora de Salida: " + getEndTime().toString() + "\nHoras Extra: " + getExtraHours() + "\n";

    if (myBool == true) {
        cadena += "\n\tLista de Clientes Atendidos:\n" + getClientList().toString() + "\n\n";
    }
    return cadena;
}

//Set de N�mero de Extensi�n
void Agent::setExtensionNumber(const string& exn) {
    extensionNumber = exn;
}

//Set de Especialidad
void Agent::setSpeciality(const string& s) {
    specialty = s;
}

//Set de Nombre
void Agent::setName(const Name& n) {
    name = n;
}

//Set de N�mero de Empleado
void Agent::setEmployeeNumber(const string& en) {
    employeeNumber = en;
}

//Set de Horas Extras
void Agent::setExtraHours(const string& exh) {
    extraHours = exh;
}

//Set de Hora de inicio
void Agent::setStartTime(const Time& st) {
    startTime = st;
}

//Set de Hora de salida
void Agent::setEndTime(const Time& et) {
    endTime = et;
}

//Operador Asignaci�n
Agent& Agent::operator = (const Agent& a) {
    extensionNumber = a.extensionNumber;
    specialty = a.specialty;
    employeeNumber = a.employeeNumber;
    extraHours = a.extraHours;
    name = a.name;
    startTime = a.startTime;
    endTime = a.endTime;

    return *this;
}

//Operador Igualdad
bool Agent::operator == (const Agent& a) const {
    return employeeNumber == a.employeeNumber;
}

//Operador Es Diferente
bool Agent::operator != (const Agent& a) const {
    return !(*this == a);
}

//Operador Menor Que
bool Agent::operator < (const Agent& a) const {
    return employeeNumber < a.employeeNumber;
}

//Operador Menor o Igual
bool Agent::operator <= (const Agent& a) const {
    return *this < a || *this == a;
}

//Operador Mayor Que
bool Agent::operator > (const Agent& a) const {
    return !(*this <= a);
}

//Operador Mayor o Igual
bool Agent::operator >= (const Agent& a) const {
    return !(*this < a);
}
