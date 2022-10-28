#ifndef CLIENTLIST_HPP
#define CLIENTLIST_HPP

#include <iostream>
#include "simplynode.hpp"

class ClientList
{
private:
    // ARTRIBUTOS
    SimplyNode* anchor;

public:
    // CONSTRUCTOR
    ClientList(); // E4
    ClientList(const ClientList&); // E4
    ~ClientList(); // (READY) E5

    bool isEmpty();  // E4
    void deleteAll(); // (READY) E5 E6
    void deleteClient(); // (READY) E5 E6
    void insertOrdered(SimplyNode&); // E4 E6
    bool isValidPos(SimplyNode&); //(READY) Test
    std::string toString();  // E4

    void readFromDisk(const std::string&);
    void writeToDisk(const std::string&);

    SimplyNode* getFirstPos() const;
    SimplyNode* getLastPos() const;
    SimplyNode* getPrevPos(const SimplyNode&);
    SimplyNode* getNextPos(SimplyNode&) const;

    std::string findData(const Client&) const; // (READY) E5

    Client retrieve(SimplyNode&); // (READY)

    void deleteClientList();
};

#endif // CLIENTLIST_HPP
