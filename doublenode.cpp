//Librerias de compilador
#include<iostream>
//Librerias de Usuario
#include "doublenode.hpp"

using namespace std;

//Constructor Normal
DoubleNode::DoubleNode() : next(nullptr), prev(nullptr) {}

//Constructor Menos Normal
DoubleNode::DoubleNode(const Agent& sn) : next(nullptr), prev(nullptr), data(sn) {}

//Getters
//Get de Datos de Agente
Agent DoubleNode::getData() const {
    return data;
}

//Get de Nodo Anterior
DoubleNode* DoubleNode::getprev() {
    return prev;
}

//Get de Siguiente Nodo
DoubleNode* DoubleNode::getNext() {
    return next;
}

//Setters
//Set de Datos de Agente
void DoubleNode::setData(const Agent& a) {
    data = a;
}

//Set del Nodo Anterior
void DoubleNode::setNext(DoubleNode* p) {
    next = p;
}

bool DoubleNode::operator == (const DoubleNode& p) const
{
    return data.getEmployeeNumber() == p.data.getEmployeeNumber();
}

bool DoubleNode::operator != (const DoubleNode& p) const
{
    return !(*this == p);

}

bool DoubleNode::operator < (const DoubleNode& p) const
{
    bool x = false;
    return data.toString(x) < p.data.toString(x);
}

bool DoubleNode::operator <= (const DoubleNode& p) const
{
    return *this < p || *this == p;
}

bool DoubleNode::operator > (const DoubleNode& p) const
{
    return !(*this <= p);
}

bool DoubleNode::operator >= (const DoubleNode& p) const
{
    return !(*this < p);
}
