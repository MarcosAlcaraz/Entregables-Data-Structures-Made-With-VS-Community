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
    void insertOrdered(SimplyNode&);
    bool isValidPos(SimplyNode&);
    std::string toString();
    std::string findData(const Client&) const;

    void readFromDisk(std::string&);
    void writeToDisk(std::string&);

    SimplyNode* getFirstPos() const;
    SimplyNode* getLastPos() const;
    SimplyNode* getPrevPos(const SimplyNode&);
    SimplyNode* getNextPos(SimplyNode&) const;

    Client retrieve(SimplyNode&);
};

#endif // CLIENTLIST_HPP
