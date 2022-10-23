//Librerias de compilador
#include<iostream>
//Librerias de Usuario
#include "simplynode.hpp"

using namespace std;

//Constructor Normal
SimplyNode::SimplyNode() : next(nullptr) {}

//Constructor Menos Normal
SimplyNode::SimplyNode(const Client& sn) : next(nullptr), data(sn) {}

SimplyNode::~SimplyNode() { }

//Getters
//Get de Datos de Cliente
Client SimplyNode::getData() const {
    return data;
}

//Get de Siguiente Nodo
SimplyNode* SimplyNode::getNext() {
    return next;
}

bool SimplyNode::nextIsNullptr(const SimplyNode& c)
{
    return c.next == nullptr;
}

//Setters
//Set de Datos de Cliente
void SimplyNode::setData(const Client& c) {
    data = c;
}

//Set Siguiente Nodo
void SimplyNode::setNext(SimplyNode* p) {
    next = p;
}

SimplyNode& SimplyNode::operator=(const SimplyNode& c)
{
    data = c.data;
    next = c.next;

    return *this;
}

bool SimplyNode::operator == (const SimplyNode& t) const
{
    return data.toString() == t.data.toString();
}

bool SimplyNode::operator != (const SimplyNode& t) const
{
    return data.toString() != t.data.toString();
}

bool SimplyNode::operator < (const SimplyNode& t) const
{
    return data.toString() < t.data.toString();
}

bool SimplyNode::operator <= (const SimplyNode& t) const
{
    return *this < t || *this == t;
}

bool SimplyNode::operator > (const SimplyNode& t) const
{
    return !(*this <= t);
}

bool SimplyNode::operator >= (const SimplyNode& t) const
{
    return !(*this < t);
}
