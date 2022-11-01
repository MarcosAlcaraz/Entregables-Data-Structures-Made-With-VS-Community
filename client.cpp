#include<iostream>

#include"client.hpp"

using namespace std;

// TESTEAR
Client::Client() {}  

// TESTEAR
Client::Client(const Client& c) : timeAtention(c.timeAtention), atentionDuration(c.atentionDuration) {}  // E4

// TESTEAR
Time Client::getTimeAtention() const { // E4
    return timeAtention;
}

// TESTEAR
Time Client::getAtentionDuration() const { // E4
    return atentionDuration;
}

// TESTEAR
void Client::setTimeAtention(const Time& ta) { // E4
    timeAtention = ta;
}

// TESTEAR
void Client::setAtentionDuration(const Time& ad) { // E4
    atentionDuration = ad;
}

// TESTEAR
string Client::toString() const {  // E4
    string result;
    result += "\nHora de llamada: " + getTimeAtention().toString() + "\nDuracion de la llamada: " + getAtentionDuration().toString();
    return result;
}

// TESTEAR
Client& Client::operator = (const Client& c) {
    timeAtention = c.timeAtention;
    atentionDuration = c.atentionDuration;

    return *this;
}

// TESTEAR
bool Client::operator == (const Client& t) const {
    return toString() == t.toString();
}

// TESTEAR
bool Client::operator != (const Client& t) const {
    return toString() != t.toString();
}

// TESTEAR
bool Client::operator < (const Client& t) const {
    return toString() < t.toString();
}

// TESTEAR
bool Client::operator <= (const Client& t) const {
    return *this < t || *this == t;
}

// TESTEAR
bool Client::operator > (const Client& t) const {
    return !(*this <= t);
}

// TESTEAR
bool Client::operator >= (const Client& t) const {
    return !(*this < t);
}

std::ostream& operator << (std::ostream& os, const Client& c)
{
    os << c.getAtentionDuration() << endl;
    os << c.getTimeAtention() << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Client& c)
{
    is >> c.atentionDuration;
    is >> c.timeAtention;
    return is;
}
