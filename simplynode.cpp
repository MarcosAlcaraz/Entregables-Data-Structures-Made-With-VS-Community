#include<iostream>

#include "simplynode.hpp"

using namespace std;

// TESTEAR
SimplyNode::SimplyNode() : next(nullptr) {}

// TESTEAR
SimplyNode::SimplyNode(const Client& sn) : next(nullptr), data(sn) {}

// TESTEAR
SimplyNode::~SimplyNode() { }

// TESTEAR
Client SimplyNode::getData() const {
    return data;
}

// TESTEAR
SimplyNode* SimplyNode::getNext() {
    return next;
}
/*
// PENDIENTE
SimplyNode* SimplyNode::getPreviousPos(const SimplyNode&)
{
    return nullptr;
}
*/
/*
// TESTEAR
bool SimplyNode::nextIsNullptr(const SimplyNode& c)
{
    return c.next == nullptr;
}
*/
// TESTEAR
void SimplyNode::setData(const Client& c) {
    data = c;
}

// TESTEAR
void SimplyNode::setNext(SimplyNode* p) {
    if (p != nullptr) {
        next = p;
    }
}

// TESTEAR
SimplyNode& SimplyNode::operator=(const SimplyNode& c)
{
    data = c.data;
    next = c.next;

    return *this;
}

// TESTEAR
bool SimplyNode::operator == (const SimplyNode& t) const
{
    return data.toString() == t.data.toString();
}

// TESTEAR
bool SimplyNode::operator != (const SimplyNode& t) const
{
    return data.toString() != t.data.toString();
}

// TESTEAR
bool SimplyNode::operator < (const SimplyNode& t) const
{
    return data.toString() < t.data.toString();
}

// TESTEAR
bool SimplyNode::operator <= (const SimplyNode& t) const
{
    return *this < t || *this == t;
}

// TESTEAR
bool SimplyNode::operator > (const SimplyNode& t) const
{
    return !(*this <= t);
}

// TESTEAR
bool SimplyNode::operator >= (const SimplyNode& t) const
{
    return !(*this < t);
}
