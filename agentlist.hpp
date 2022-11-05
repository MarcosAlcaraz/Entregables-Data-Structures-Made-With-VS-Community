#ifndef __AGENTLIST_H__
#define __AGENTLIST_H__

#include<iostream>

#include"doublenode.hpp"
#include "listexception.hpp"

class AgentList
{
private:
    DoubleNode* anchor;

public:
    AgentList();
    AgentList(const AgentList&);
    ~AgentList();

    bool isEmpty();
    bool isValidPos(DoubleNode*);

    void insertAgent(DoubleNode&);
    void deleteAll();
    void deleteNode(DoubleNode*);
    //void sortByName(DoubleNode*, DoubleNode*);
    //void sortBySpeciality(DoubleNode*, DoubleNode*);

    std::string toString(bool);

    Agent retrieve(DoubleNode*);

    DoubleNode* getFirstPos() const;
    DoubleNode* getLastPos() const;
    DoubleNode* getNextPos(DoubleNode&) const;
    DoubleNode* getPreviousPos(DoubleNode&) const;
    DoubleNode* findData(const Agent&) const;

    bool readFromDisk();
    bool writeToDisk();
};

#endif // __AGENTLIST_H__