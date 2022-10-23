#ifndef SIMPLYNODE_HPP
#define SIMPLYNODE_HPP

#include <iostream>
#include <string>
#include "client.hpp"

class SimplyNode
{
private:
    //ATTRIBUTES
    Client data;
    SimplyNode* next;

public:
    //Constructores y destructor
    SimplyNode();
    SimplyNode(const Client&);
    ~SimplyNode();

    //Getters
    Client getData() const;
    SimplyNode* getNext();
    SimplyNode* getPreviousPos(const SimplyNode&);

    bool nextIsNullptr(const SimplyNode& c);

    //Setters
    void setData(const Client&);
    void setNext(SimplyNode*);

    //OPERATORs
    SimplyNode& operator=(const SimplyNode&);

    bool operator == (const SimplyNode&) const;
    bool operator != (const SimplyNode&) const;
    bool operator < (const SimplyNode&) const;
    bool operator <= (const SimplyNode&) const;
    bool operator > (const SimplyNode&) const;
    bool operator >= (const SimplyNode&) const;
};

#endif // SIMPLYNODE_HPP
