#include<iostream>

#include "doublenode.hpp"

using namespace std;

// EXITO
DoubleNode::DoubleNode() : next(nullptr), prev(nullptr) {}

// EXITO
DoubleNode::DoubleNode(const Agent& sn) : next(nullptr), prev(nullptr), data(sn) {}

// EXITO
Agent DoubleNode::getData() const {
    return data;
}

// EXITO
DoubleNode* DoubleNode::getPrev() {
    return prev;
}

// EXITO
DoubleNode* DoubleNode::getNext() {
    return next;
}

// EXITO
void DoubleNode::setData(const Agent& a) {
    data = a;
}

// EXITO
void DoubleNode::setNext(DoubleNode* p) {
    if (p != nullptr) {
        next = p;
    }
}

// EXITO
void DoubleNode::setPrev(DoubleNode* p) {
    if (p != nullptr) {
        prev = p;
    }
}

// EXITO
DoubleNode& DoubleNode::operator = (const DoubleNode& d) {
    data = d.data;
    next = d.next;
    prev = d.prev;

    return *this;
}

// TESTEAR
bool DoubleNode::operator == (const DoubleNode& p) const
{
    return data.getEmployeeNumber() == p.data.getEmployeeNumber();
}

// TESTEAR
bool DoubleNode::operator != (const DoubleNode& p) const
{
    return !(*this == p);

}

// TESTEAR
bool DoubleNode::operator < (const DoubleNode& p) const
{
    bool x = false;
    return data.toString(x) < p.data.toString(x);
}

// TESTEAR
bool DoubleNode::operator <= (const DoubleNode& p) const
{
    return *this < p || *this == p;
}

// TESTEAR
bool DoubleNode::operator > (const DoubleNode& p) const
{
    return !(*this <= p);
}

// TESTEAR
bool DoubleNode::operator >= (const DoubleNode& p) const
{
    return !(*this < p);
}
