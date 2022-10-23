//Librerias de compilador
#include<iostream>
//Librerias de Usuarioa
#include"client.hpp"

using namespace std;

//Constructor Normal
Client::Client() {}  // E4

//Constructor Copia
Client::Client(const Client& c) {}  // E4

//Getters
//Get de Hora de Atenci�n
Time Client::getTimeAtention() const { // E4
    return timeAtention;
}

//Get de Duraci�n de Llamada
Time Client::getAtentionDuration() const { // E4
    return atentionDuration;
}

//Setters
//Set de Peimer Nombre
void Client::setTimeAtention(const Time& ta) { // E4
    timeAtention = ta;
}

//Set de Minuto
void Client::setAtentionDuration(const Time& ad) { // E4
    atentionDuration = ad;
}

//Impresi�n de Tiempo
string Client::toString() const {  // E4
    string cadena;
    cadena += "\nHora de llamada: " + getTimeAtention().toString() + "\nDuracion de la llamada: " + getAtentionDuration().toString();
    return cadena;
}

//Operador Asignaci�n
Client& Client::operator = (const Client& c) {
    timeAtention = c.timeAtention;
    atentionDuration = c.atentionDuration;

    return *this;
}

//Operador Igualdad
bool Client::operator == (const Client& t) const {
    return toString() == t.toString();
}

//Operador Es Diferente
bool Client::operator != (const Client& t) const {
    return toString() != t.toString();
}

//Operador Menor Que
bool Client::operator < (const Client& t) const {
    return toString() < t.toString();
}

//Operador Menor o Igual
bool Client::operator <= (const Client& t) const {
    return *this < t || *this == t;
}

//Operador Mayor Que
bool Client::operator > (const Client& t) const {
    return !(*this <= t);
}

//Operador Mayor o Igual
bool Client::operator >= (const Client& t) const {
    return !(*this < t);
}
