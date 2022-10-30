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
    nuevoAgente.setNext(anchor); //nuevoAgente apunta a lo que apunta anchor
    anchor = &nuevoAgente;
}

// EXITO
bool AgentList::isEmpty() // E7
{
    return anchor == nullptr;
}

// EXITO
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

// EXITO
string AgentList::toString(bool myBool) // E7
{
    DoubleNode* aux = anchor;
    int i = 0;
    string result;

    do {
        i++;

        result += "\n(" + to_string(i) + ")\n" + aux->getData().toString(myBool);
        aux = aux->getNext();
    } while (aux != nullptr);
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

// ERROR (TESTEAR)
void AgentList::deleteNode(DoubleNode* del)
{
    del->getPrev()->setNext(del->getNext());
    del->getNext()->setPrev(del->getPrev());
    delete del;
}

void AgentList::sortByName(DoubleNode*, DoubleNode*)
{
}

void AgentList::sortBySpeciality(DoubleNode*, DoubleNode*)
{
}

// PENDIENTE
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

// PENDIENTE
//     //Divide Y vencer�s
//     if(leftEdge != i) {
//         sortByName(leftEdge, i->getPrev());
//     }
//     if(rightEdge != i) {
//         sortByName(i->getNext(), rightEdge);
//     }
// }

// PENDIENTE
// void StudentList::sortByGrade() {
//     sortByGrade(header->getNext(), header->getPrev());
// }

// PENDIENTE
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

// PENDIENTE
// void StudentList::swapPtr(StudentNodet* a, StudentNode* b) {
//     Student* aux(a->getDataPtr());
//     a->setDataPtr(b->getDataPtr());
//     b->sedDataPtr(aux);
// }

// PENDIENTE
void AgentList::readFromDisk()
{
    //Lee de un archivo
}

// PENDIENTE
void AgentList::writeToDisk()
{
    ofstream file;

    file.open("backup.agentlist");


}

// EXITO
DoubleNode* AgentList::getFirstPos() const
{
    return anchor;
}

// TESTEAR (Reconstruido)
DoubleNode* AgentList::getLastPos() const
{
    if (anchor == nullptr)
    {
        return nullptr;
    }

    DoubleNode* aux = anchor;

    while (aux->getNext() != nullptr) {
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

// TESTEAR
Agent AgentList::retrieve(DoubleNode& p)
{
    if (!(isValidPos(p)))
    {
        Agent aux;
        return aux;
    }
    return p.getData();
}
