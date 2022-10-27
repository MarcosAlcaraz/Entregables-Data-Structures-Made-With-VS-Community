#include <iostream>
#include "agentlist.hpp"

using namespace std;


AgentList::AgentList() : anchor(nullptr) { } // E7

AgentList::AgentList(const AgentList&) : anchor(nullptr) { }

AgentList::~AgentList()
{
    deleteAll();
}

void AgentList::insertAgent(DoubleNode& nuevoAgente) // E7
{
    nuevoAgente.setNext(anchor); //nuevoAgente apunta a lo que apunta anchor
    anchor = &nuevoAgente;
}

bool AgentList::isEmpty() // E7
{
    return anchor == nullptr;
}

bool AgentList::isValidPos(DoubleNode& p)
{
    if (&p == nullptr)
    {
        return false;
    }
    else {
        return true;
    }
}

string AgentList::toString(bool myBool) // E7
{
    DoubleNode* aux = anchor;
    int i = 0;
    string result;

    do {
        i++;

        result += "\n(" + to_string(i) + ") " + aux->getData().toString(myBool);
        aux = aux->getNext();
    } while (aux != nullptr);
    return result;
}

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

void AgentList::deleteNode(DoubleNode* del)
{
    delete del;
}

// void AgentList::sortByName(DoubleNode* leftEdge, DoubleNode* rightEdge) {
//     if(leftEdge == 'rightedge') { //En caso de haber un solo elemento
//         return;
//     }
//     if(leftEdge->getNext() == rightEdge) { // si hay solo dos elementos
//         if(leftEdge->getData().getName() > rightEdge->getData().getName()) {
//             swapPtr(leftEdge, rightEdge);
//         }
//         return;
//     }

//     //particion de la lista
//     StudentNode* i(leftEdge);
//     StudentNode* j(rightEdge);

//     while (i != j)
//     {
//         while (i != j && i ->getData().getName() <= rightEdge->getData().getName())
//         {
//             i = i->getNext();
//         }
//     }
//     while(i != j && j->getData().getName() >= rightEdge->getData().getName())
//     {
//         j = j->getPrev();
//         if(i != j)
//         {
//             swapPtr(i, j);
//         }
//     }
//     if(i != rightEdge)
//     {
//         swapPtr(i, rightEdge);
//     }

//     //Divide Y vencer�s
//     if(leftEdge != i) {
//         sortByName(leftEdge, i->getPrev());
//     }
//     if(rightEdge != i) {
//         sortByName(i->getNext(), rightEdge);
//     }
// }

// void StudentList::sortByGrade() {
//     sortByGrade(header->getNext(), header->getPrev());
// }

// void StudentList::SortByGrade() {
//     if(leftEdge == 'rightedge') { //En caso de haber un solo elemento
//         return;
//     }
//     if(leftEdge->getNext() == rightEdge) { // si hay solo dos elementos
//         if(leftEdge->getData().getGrade() > rightEdge->getData().getGrade()) {
//             swapPtr(leftEdge, rightEdge);
//         }
//         return;
//     }

//     //particion de la lista
//     StudentNode* i(leftEdge);
//     StudentNode* j(rightEdge);

//     while (i != j)
//     {
//         while (i != j && i ->getData().getGrade() <= rightEdge->getData().getGrade())
//         {
//             i = i->getNext();
//         }
//     }
//     while(i != j && j->getData().getGrade() >= rightEdge->getData().getGrade())
//     {
//         j = j->getPrev();
//         if(i != j)
//         {
//             swapPtr(i, j);
//         }
//     }
//     if(i != rightEdge)
//     {
//         swapPtr(i, rightEdge);
//     }

//     //Divide Y vencer�s
//     if(leftEdge != i) {
//         sortByName(leftEdge, i->getPrev());
//     }
//     if(rightEdge != i) {
//         sortByName(i->getNext(), rightEdge);
//     }
// }

// void StudentList::swapPtr(StudentNodet* a, StudentNode* b) {
//     Student* aux(a->getDataPtr());
//     a->setDataPtr(b->getDataPtr());
//     b->sedDataPtr(aux);
// }

void AgentList::readFromDisk(const std::string&)
{
    //Lee de un archivo
}

void AgentList::writeToDisk(const std::string&)
{
    //Escribe en un archivo
}

DoubleNode* AgentList::getFirstPos() const
{
    return anchor;
}

DoubleNode* AgentList::getLastPos() const
{
    if (anchor == nullptr)
    {
        return nullptr;
    }

    DoubleNode* aux = anchor;

    do
    {
        if (aux->getNext() == nullptr)
        {
            return aux;
        }
        aux = aux->getNext();
    } while (aux->getNext() == nullptr);

}

DoubleNode* AgentList::getNextPos(DoubleNode& p) const
{
    return p.getNext();
}

DoubleNode* AgentList::getPreviousPos(DoubleNode& p) const
{
    return p.getprev();
}

DoubleNode* AgentList::findData(DoubleNode& p)
{
    if (!(isValidPos(p)))
    {
        return nullptr;
    }

    DoubleNode* aux = anchor;

    do {
        if (aux->getData().getEmployeeNumber() == p.getData().getEmployeeNumber())
        {
            return aux;
        }
        else {
            aux = aux->getNext();
        }
    } while (aux->getData().getEmployeeNumber() != p.getData().getEmployeeNumber());
}

Agent AgentList::retrieve(DoubleNode& p)
{
    if (!(isValidPos(p)))
    {
        Agent aux;
        return aux;
    }
    return p.getData();
}
