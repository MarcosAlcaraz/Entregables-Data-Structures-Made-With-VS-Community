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

// TESTEAR (Sin Uso)
string ClientList::findData(const Client&) const  //E5
{
    string myString;
    SimplyNode* aux = anchor;
    Time t;
    /*int h, m, s;

    cout << "\nEscribe la hora de Atencion del cliente que desea buscar:\n\Escriba la hora (hh:): ";
    cin >> h;
    cout << "\nEscriba el minuto (:mm:): ";
    cin >> m;
    cout << "\nEscriba el segundo (:ss): ";
    cin >> s;

    t.setHour(h);
    t.setMinute(m);
    t.setSecond(s);*/

    do
    {
        if (aux->getData().getTimeAtention() == t)
        {
            myString += "Cliente / Llamada encontrada: \n" + aux->getData().toString();
            break;
        }
        else
        {
            aux = aux->getNext();
        }
    } while (aux != nullptr);
    return myString;
}

// TESTEAR (Sin Uso)
Client ClientList::retrieve(SimplyNode& p)
{
    if (!(isValidPos(p)))
    {
        Client aux;
        return aux;
    }
    return p.getData();
}

// TESTEAR (Esperanzador)
string ClientList::toString() // E6
{
    SimplyNode* aux = anchor;
    string result;
    int i = 0;
    do {
        i++;
        result += "\n\t(Llamada " + to_string(i) + ")\n" + aux->getData().toString();
        aux = aux->getNext();
    } while (aux != nullptr);
    return result;
}

// TESTEAR (Reconstruido)
SimplyNode* ClientList::getPrevPos(const SimplyNode& p)
{
    SimplyNode* aux = anchor;
    while (aux->getNext()->getData().getTimeAtention() != p.getData().getTimeAtention()) {
        aux = aux->getNext();
    }
    return aux;
}

// EXITO
SimplyNode* ClientList::getFirstPos() const {
    return anchor;
}

// TESTEAR (Reconstruido)
SimplyNode* ClientList::getLastPos() const
{
    if(anchor == nullptr) {
        return nullptr;
    }

    SimplyNode* aux = anchor;

    while (aux->getNext() != nullptr) {
        aux = aux->getNext();
    }
    return aux;
}

// EXITO (Sin Uso)
SimplyNode* ClientList::getNextPos(SimplyNode& d) const
{
    return d.getNext();
}

// TESTEAR (Reconstruido)
void ClientList::deleteClient(SimplyNode* del) // E5 E6
{
    getPrevPos(*del)->setNext(del->getNext());
    delete del;
}

// TESTEAR (Reconstruido)
void ClientList::insertOrdered(SimplyNode& call)
{
    SimplyNode* i = anchor;
    Client aux = Client();
    int myInt = 0;
    bool flag = false;

    call.setNext(anchor);
    if (anchor == nullptr)
    {
        anchor = &call;
    }
    else
    {
        SimplyNode* j = anchor->getNext();
        // Insertando al inicio
        call.setNext(anchor);
        anchor = &call;

        // Calculando tamaño de la lista
        do {
            myInt++;
            i = i->getNext();
        } while (i != nullptr);
        i = anchor;

        // Ejecutando ordenamiento [BoobleSort]

        do {
            i = anchor;
            j = anchor->getNext();
            flag = false;

            for (int k = 0; k < myInt; k++) {
                if (i > j) {
                    // Swap
                    aux = i->getData();
                    i->setData(j->getData());
                    j->setData(aux);
                    flag = true;
                }
                j = j->getNext();
                i = i->getNext();
            }
        } while (flag);
    }
}

// EXITO
bool ClientList::isValidPos(SimplyNode& p)
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
void ClientList::deleteAll()
{
    SimplyNode* aux = nullptr;

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
