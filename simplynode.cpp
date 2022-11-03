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

// TESTEAR
void SimplyNode::setData(const Client& c) {
    data = c;
}

// TESTEAR
void SimplyNode::setNext(SimplyNode* p) {
    if (isValid(p)) {
        next = p;
    }
}

// TESTEAR
SimplyNode& SimplyNode::operator = (const SimplyNode& c)
{
    data = c.data;
    next = c.next;

    return *this;
}

// TESTEAR
bool SimplyNode::isValid(const SimplyNode* s) const
{
    return s != nullptr;
}

// TESTEAR
bool SimplyNode::operator == (const SimplyNode& t) const
{
    return data == t.data;
}

// TESTEAR
bool SimplyNode::operator != (const SimplyNode& t) const
{
    return data != t.data;
}

// TESTEAR
bool SimplyNode::operator < (const SimplyNode& t) const
{
    return data < t.data;
}

// TESTEAR
bool SimplyNode::operator <= (const SimplyNode& t) const
{
    return data <= t.data;
}

// TESTEAR
bool SimplyNode::operator > (const SimplyNode& t) const
{
    return data > t.data;
}

// TESTEAR
bool SimplyNode::operator >= (const SimplyNode& t) const
{
    return data >= t.data;
}
