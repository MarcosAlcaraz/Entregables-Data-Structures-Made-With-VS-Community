#ifndef DOUBLENODE_HPP
#define DOUBLENODE_HPP

#include<iostream>
#include"agent.hpp"

class DoubleNode
{
private:
    Agent data;
    DoubleNode* prev;
    DoubleNode* next;

public:
    DoubleNode();
    DoubleNode(const Agent&);

    Agent getData() const;
    DoubleNode* getNext();
    DoubleNode* getPrev();

    void setData(const Agent&);
    void setNext(DoubleNode*);
    void setPrev(DoubleNode*);

    //Operadores relacionales
    DoubleNode& operator = (const DoubleNode&);

    bool operator == (const DoubleNode&) const;
    bool operator != (const DoubleNode&) const;
    bool operator < (const DoubleNode&) const;
    bool operator <= (const DoubleNode&) const;
    bool operator > (const DoubleNode&) const;
    bool operator >= (const DoubleNode&) const;
};

#endif // DOUBLENODE_HPP
