// Librerias de compilador
#include <iostream>

// Librerias de Usuario
#include "clientlist.hpp"
#include "doublenode.hpp"

using namespace std;

// Constructor Normalito
ClientList::ClientList() : anchor(nullptr) {}

// Constructor Copia
ClientList::ClientList(const ClientList&) : anchor(nullptr) {}

ClientList::~ClientList()  //E5
{
    deleteAll();
    anchor = nullptr;
}

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

Client ClientList::retrieve(SimplyNode& p)
{
    if (!(isValidPos(p)))
    {
        Client aux;
        return aux;
    }
    return p.getData();
}

string ClientList::toString() // E6
{
    SimplyNode* node = anchor;
    string cadena;
    int i = 0;
    do {
        i++;
        cadena += "\n\t(Llamada " + to_string(i) + ")\n" + node->getData().toString();
        node = node->getNext();
    } while (node != nullptr);
    return cadena;
}

SimplyNode* ClientList::getPreviousPos(const SimplyNode& p)
{
    SimplyNode* aux = anchor;
    do
    {
        if (aux->getNext()->getData().getTimeAtention() == p.getData().getTimeAtention())
        {
            return aux;
        }
        aux = aux->getNext();
    } while (aux->getNext()->getData().getTimeAtention() != p.getData().getTimeAtention());
    return nullptr;
}

SimplyNode* ClientList::getFirstPos() const {
    return anchor;
}

void ClientList::deleteClient() // E5 E6
{
    SimplyNode* del = anchor;
    int opcion = NULL;

    cout << "\nSelecciona el Cliente/Llamada a eliminar.\n";
    toString();
    cout << "Respuesta : ";
    cin >> opcion;

    for (int i = 0; i < opcion; i++)
    {
        del = del->getNext();
    }
    delete del;
}

void ClientList::insertOrdered(SimplyNode& call) // E6
{
    //SimplyNode* call = new SimplyNode();
    // Inserci�n ordenado del dato
    if (anchor == nullptr)
    {
        anchor = &call;
    }
    else
    {
        // Insertando al inicio
        call.setNext(anchor);
        anchor = &call;

        SimplyNode* aux = anchor;
        SimplyNode* temp = anchor->getNext();
        SimplyNode* last = &*anchor;

        // Ejecutando ordenamiento [BoobleSort]
        do
        {
            if (aux->getData().getTimeAtention() > aux->getNext()->getData().getTimeAtention())
            {
                temp = aux->getNext();
                aux->setNext(aux->getNext()->getNext());
                temp->setNext(aux);
                last->setNext(temp);
            }
            else
            {
                last = aux;
                aux = aux->getNext();
            }
        } while (aux != nullptr);
    }
}

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

bool ClientList::isEmpty()
{
    return anchor == nullptr;
}
