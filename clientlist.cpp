#include <iostream>
#include <fstream>

#include "clientlist.hpp"
#include "doublenode.hpp"

using namespace std;

// EXITO
ClientList::ClientList() : anchor(nullptr) {}

// EXITO
ClientList::ClientList(const ClientList&) : anchor(nullptr) {}

// EXITO
ClientList::~ClientList()  //E5
{
    deleteAll();
}

// TESTEAR (Esperanzador)
SimplyNode* ClientList::findData(const Client& client) const  //E5
{
    SimplyNode* aux(anchor);

    while (aux != nullptr && aux->getData() != client)
    {
        aux = aux->getNext();
    }

    return aux;
}

// TESTEAR (Esperanzador)
Client ClientList::retrieve(SimplyNode* p)
{    
    if (!isValidPos(p))
    {
        throw ListException("La posicion es Invalida - retrieve");
    }

    return p->getData();
}

// TESTEAR (Esperanzador)
SimplyNode& ClientList::operator = (const ClientList& list)
{
    deleteAll();
    SimplyNode* aux(list.anchor);
    SimplyNode* aux1(nullptr);
    SimplyNode* node;

    while (aux != nullptr)
    {
        node = new SimplyNode(aux->getData());

        if (node == nullptr)
        {
            throw ListException("Memoria insuficiente - operator = ");
        }

        if (aux1 == nullptr)
        {
            anchor = node;
        }
        else
        {
            aux1 = node;
            aux = aux->getNext();
        }
    }
}

// TESTEAR (Esperanzador)
string ClientList::toString() // E6
{
    SimplyNode* aux(anchor);
    string result;

    int i = 0;

    while (aux != nullptr)
    {
        i++;

        result += "\n\t(Llamada " + to_string(i) + ")\n" + aux->getData().toString();
        
        aux = aux->getNext();
    }

    return result;
}

// TESTEAR (Esperanzador)
SimplyNode* ClientList::getPrevPos(SimplyNode* p) const
{
    if (p == anchor || !isValidPos(p))
    {
        return nullptr;
    }

    SimplyNode* aux(anchor);

    while (aux->getNext() != p)
    {
        aux = aux->getNext();
    }

    return aux;
}

// EXITO
SimplyNode* ClientList::getFirstPos() const {
    return anchor;
}

// TESTEAR (Esperanzador)
SimplyNode* ClientList::getLastPos() const
{
    if (isEmpty)
    {
        return nullptr;
    }

    SimplyNode* aux = anchor;

    while (aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }

    return aux;
}

// TESTEAR (Esperanzador)
SimplyNode* ClientList::getNextPos(SimplyNode* d) const
{
    if (isValidPos(d))
    {
        return d->getNext();
    }
}

// TESTEAR (Esperanzador)
void ClientList::deleteClient(SimplyNode* del)
{
    if (!isValidPos(del))
    {
        throw ListException("La Posicion es Invalida - deleteClient");
    }

    if (del == anchor)
    {
        anchor = del->getNext();
    }
    else
    {
        getPrevPos(del)->setNext(del->getNext());
    }

    delete del;
}

// TESTEAR (Esperazador)
void ClientList::insertClient(SimplyNode* node, const Client& client)
{
    if (node != nullptr && !isValidPos(node)) {
        throw ListException("La Posición es Invalida - insertOrdered");
    }

    SimplyNode* aux(new SimplyNode(client));

    if (aux == nullptr) {
        throw ListException("Memoria Insuficiente para la Operación - insertOrdered");
    }

    if (node == nullptr) {
        aux->setNext(anchor);
        anchor = aux;
    }
    else
    {
        aux->setNext(node->getNext());
        node->setNext(aux);
    }
}

// TESTEAR (Esperanzador)
void ClientList::insertOrdered(const Client& c)
{
    SimplyNode* aux(anchor);
    SimplyNode* aux1(nullptr);

    while (aux != nullptr && c > aux->getData()) {
        aux1 = aux;
        aux = aux->getNext();
    }

    insertClient(aux1, c);
}

// TESTEAR (Esperanzador)
bool ClientList::isValidPos(const SimplyNode* p) const
{
    SimplyNode* aux(anchor);

    while (aux != nullptr) {
        if (aux == p) {
            return true;
        }

        aux = aux->getNext();
    }

    return false;
}

// EXITO
void ClientList::deleteAll()
{
    SimplyNode* aux(nullptr);
    while (anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

// EXITO
bool ClientList::isEmpty()
{
    return anchor == nullptr;
}

// TESTEAR 
void ClientList::writeToDisk(string& employeeNumber)
{
    SimplyNode* aux = anchor;
    ofstream file;
    string fileName;

    fileName += employeeNumber + ".clientlist";
    file.open("backup.agentlist");

    if (file) {
        while (aux != nullptr) {
            file << aux->getData();
            aux = aux->getNext();
        }
    }
    file.close();
}

void ClientList::readFromDisk(string& employeeNumber)
{
    SimplyNode* ndn = new SimplyNode();
    Client* ncall = new Client();
    ifstream file;
    string fileName;

    int myInt = 0;

    fileName += employeeNumber + ".clientlist";

    if (file) {
        file >> *ncall;
    }
    
}
