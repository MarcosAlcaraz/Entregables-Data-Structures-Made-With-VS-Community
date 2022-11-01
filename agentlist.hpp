#ifndef __AGENTLIST_H__
#define __AGENTLIST_H__

//Librerias de usuario
#include<iostream>
#include"doublenode.hpp"

class AgentList
{
private:
    //ARTRIBUTES
    DoubleNode* anchor;

public:
    //CONSTRUCTOR
    AgentList(); // (READY) E7
    AgentList(const AgentList&); // (READY)  E7
    ~AgentList(); // (READY) E8

    void insertAgent(DoubleNode&); // (READY) E7
    bool isEmpty(); // (READY) E7
    bool isValidPos(DoubleNode&); // (READY)
    std::string toString(bool); // (READY) E7
    void deleteAll(); // (READY) E8
    void deleteNode(DoubleNode*); // (READY) E8
    void sortByName(DoubleNode*, DoubleNode*);
    void sortBySpeciality(DoubleNode*, DoubleNode*);

    Agent retrieve(DoubleNode&);

    DoubleNode* getFirstPos() const; // (READY)
    DoubleNode* getLastPos() const; // (READY)
    DoubleNode* getNextPos(DoubleNode&) const; //(READY) E8
    DoubleNode* getPreviousPos(DoubleNode&) const; //(READY) E8

    DoubleNode* findData(DoubleNode&); // (READY) E8 E9

    bool readFromDisk();
    bool writeToDisk();
};

#endif // __AGENTLIST_H__