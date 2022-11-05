#include <iostream>
#include <fstream>

#include "agentlist.hpp"

using namespace std;

// EXITO
AgentList::AgentList() : anchor(nullptr) {}

// EXITO
AgentList::AgentList(const AgentList&) : anchor(nullptr) {}

// EXITO
AgentList::~AgentList()
{
    deleteAll();
}

// EXITO
void AgentList::insertAgent(DoubleNode& nuevoAgente) // E7
{
    nuevoAgente.setNext(anchor);
    anchor = &nuevoAgente;
}

// EXITO
bool AgentList::isEmpty() // E7
{
    return anchor == nullptr;
}

// TESTEAR
bool AgentList::isValidPos(DoubleNode* p)
{
    DoubleNode* aux(anchor);

    while (aux != nullptr)
    {
        if (aux == p)
        {
            return true;
        }

        aux = aux->getNext();
    }

    return false;
}

// TESTEAR
string AgentList::toString(bool myBool) // E7
{
    if (isEmpty)
    {
        return "La lista esta vacia.";
    }

    DoubleNode* aux = anchor;

    int i = 0;

    string result;

    while (aux != nullptr)
    {
        i++;

        result += "\n(" + to_string(i) + ")\n" + aux->getData().toString(myBool);

        aux = aux->getNext();
    }

    return result;
}

// TESTEAR
void AgentList::deleteAll()
{
    DoubleNode* aux = nullptr;

    while (anchor != nullptr)
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

// TESTEAR
void AgentList::deleteNode(DoubleNode* del)
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
        del->getPrev()->setNext(del->getNext());
        del->getNext()->setPrev(del->getPrev());
    }

    delete del;
}

// Reconstruir Sort By Name (URGENTE)
/*
void AgentList::sortByName(DoubleNode* leftEdge, DoubleNode* rightEdge)
{
     if(leftEdge == rightEdge)
     { //En caso de haber un solo elemento
         return;
     }
     if (leftEdge->getNext() == rightEdge)
     { // si hay solo dos elementos
         if(leftEdge->getData().getName() > rightEdge->getData().getName())
         {
             swapPtr(leftEdge, rightEdge);
         }
         return;
     }

     //particion de la lista
     DoubleNode* i(leftEdge);
     DoubleNode* j(rightEdge);

     while (i != j)
     {
         while (i != j && i ->getData().getName() <= rightEdge->getData().getName())
         {
             i = i->getNext();
         }
     }
     while(i != j && j->getData().getName() >= rightEdge->getData().getName())
     {
         j = j->getPrev();

         if(i != j)
         {
             swapPtr(i, j);
         }
     }
     if(i != rightEdge)
     {
         swapPtr(i, rightEdge);
     }

// PENDIENTE
     //Divide Y venceras
     if(leftEdge != i)
     {
         sortByName(leftEdge, i->getPrev());
     }
     if(rightEdge != i)
     {
         sortByName(i->getNext(), rightEdge);
     }
 }
*/

//Reconstruir Sort by Specialty (URGENTE)
/*
 void AgentList::sortBySpeciality()
 {
     sortByGrade(header->getNext(), header->getPrev());
 }

//Reconstruir
 void AgentList::sortBySpeciality()
 {
     if(leftEdge == rightEdge)
     { //En caso de haber un solo elemento
         return;
     }
     if(leftEdge->getNext() == rightEdge)
     { // si hay solo dos elementos
         if(leftEdge->getData().getGrade() > rightEdge->getData().getGrade())
         {
             swapPtr(leftEdge, rightEdge);
         }
         return;
     }

     //particion de la lista
     StudentNode* i(leftEdge);
     StudentNode* j(rightEdge);

     while (i != j)
     {
         while (i != j && i ->getData().getGrade() <= rightEdge->getData().getGrade())
         {
             i = i->getNext();
         }
     }
     while(i != j && j->getData().getGrade() >= rightEdge->getData().getGrade())
     {
         j = j->getPrev();
         if(i != j)
         {
             swapPtr(i, j);
         }
     }
     if(i != rightEdge)
     {
         swapPtr(i, rightEdge);
     }

     //Divide Y venceras
     if(leftEdge != i) {
         sortByName(leftEdge, i->getPrev());
     }

     if(rightEdge != i) {
         sortByName(i->getNext(), rightEdge);
     }
 }
 
// Reconstruir SwapPtr (URGENTE)
 void AgentList::swapPtr(DoubleNode* a, DoubleNode* b)
 {
     Student* aux(a->getDataPtr());
     a->setDataPtr(b->getDataPtr());
     b->sedDataPtr(aux);
 }
*/  

// Reconstruir
bool AgentList::readFromDisk()
{
    DoubleNode* ndn = new DoubleNode();
    Agent* nag = new Agent();
    ifstream file;
    string myString;
    int myInt = 0;

    file.open("backup.agentlist");
    if (!file)
    {
        return false;
    }
    //while (getline(file, myString)) { }
    file >> *nag;
}
    
// Reconstruir
bool AgentList::writeToDisk()
{
    DoubleNode* aux = anchor;
    ofstream file;

    if (anchor == nullptr) {
        file.open("backup.agentlist", file.trunc);
        if (!file.is_open()) {
            return false;
        }
        while (aux != nullptr)
        {
            file << aux->getData() << endl;
            aux = aux->getNext();
        }
        file.close();
        return true;
    }
    else {
        file.close();
        return false;
    }
}

// EXITO
DoubleNode* AgentList::getFirstPos() const
{
    return anchor;
}

// TESTEAR
DoubleNode* AgentList::getLastPos() const
{
    if (isEmpty)
    {
        return nullptr;
    }

    DoubleNode* aux = anchor;

    while (aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }

    return aux;
}

// EXITO
DoubleNode* AgentList::getNextPos(DoubleNode& p) const
{
    return p.getNext();
}

// EXITO
DoubleNode* AgentList::getPreviousPos(DoubleNode& p) const
{
    return p.getPrev();
}

// TESTEAR
DoubleNode* AgentList::findData(const Agent& a) const
{
    DoubleNode* aux(anchor);

    while (aux != nullptr && aux->getData() != a)
    {
        aux = aux->getNext();
    }

    return aux;
}

// TESTEAR
Agent AgentList::retrieve(DoubleNode* p)
{
    if (!isValidPos(p))
    {
        throw ListException("La posicion es Invalida - retrieve");
    }

    return p->getData();
}
