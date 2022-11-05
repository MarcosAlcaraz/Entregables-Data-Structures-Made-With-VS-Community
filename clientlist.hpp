#ifndef CLIENTLIST_HPP
#define CLIENTLIST_HPP

#include <iostream>

#include "simplynode.hpp"
#include "listexception.hpp"

class ClientList
{
private:
    SimplyNode* anchor;

public:
    ClientList();
    ClientList(const ClientList&);
    ~ClientList();

    bool isEmpty(); 
    void deleteAll();
    void deleteClient(SimplyNode*);
    void insertClient(SimplyNode*, const Client&);
    void insertOrdered(const Client&);
    bool isValidPos(const SimplyNode*) const; 
    std::string toString();

    void readFromDisk(std::string&);
    void writeToDisk(std::string&);
    
    SimplyNode* findData(const Client&) const;
    SimplyNode* getFirstPos() const;
    SimplyNode* getLastPos() const;
    SimplyNode* getPrevPos(SimplyNode*) const;
    SimplyNode* getNextPos(SimplyNode*) const;

    Client retrieve(SimplyNode*);
    SimplyNode& operator = (const ClientList&);
};

#endif // CLIENTLIST_HPP
