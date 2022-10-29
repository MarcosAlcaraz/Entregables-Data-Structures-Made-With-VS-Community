#include "secretarymenu.hpp"

using namespace std;

SecretaryMenu::SecretaryMenu() {}

// SecretaryMenu::SecretaryMenu(AgentList*) { }

void SecretaryMenu::mainMenu()
{
    AgentList* aList = new AgentList();
    int menu0;
    do
    {
        system("cls");
        cout << "MENU PRINCIPAL";
        cout << endl << endl << "[          Agentes         ]";
        cout << endl << "\t1) Agregar";
        cout << endl << "\t2) Eliminar";
        cout << endl << "\t3) Mostrar";
        cout << endl << "\t4) Ordenar";
        cout << endl << endl << "[         Clientes         ]";
        cout << endl << "\t5) Agregar";
        cout << endl << "\t6) Eliminar";
        cout << endl << "\t7) Modificar";
        cout << endl << endl << "[       Guardar/Cargar     ]";
        cout << endl << "\t8) Guardar";
        cout << endl << "\t9) Cargar.";
        cout << endl << endl << ": ";

        cin >> menu0;

        switch (menu0)
        {
        case 1:
            addAgent(aList);
            break;
        case 2:
            delAgent(aList);
            break;
        case 3:
            showAgentList(aList);
            break;
        case 4:
            sornAgentList(aList);
            break;
        case 5:
            addClientToAgent(aList);
            break;
        case 6:
            deleteClientToAgent(aList);
            break;
        case 7:
            modAtDrtnToAgent(aList);
            break;
        case 8:
            saveLists(aList);
            break;
        case 9:
            loadLists(aList);
            break;
        default:
            break;
        }
    } while (menu0 != 0);
}

void SecretaryMenu::addAgent(AgentList* aList)
{
    // AGREGAR NUEVO AGENTE
    Agent* nag = new Agent();           // nag = nEW agENT
    DoubleNode* ndn = new DoubleNode(); // nEW dOUBLE nODE
    Name* N = new Name();
    Time* T = new Time();
    string cadena;
    int o;

    // Nombre y Apellido
    system("cls");
    cout << endl <<"AGREGAR NUEVO AGENTE" << endl << endl;
    cout << "Nombre(s): ";

    cin.ignore();
    getline(cin, cadena);

    N->setName(cadena);

    system("cls");
    cout << endl <<"AGREGAR NUEVO AGENTE" << endl << endl;
    cout << "Apellidos: ";

    getline(cin, cadena);

    N->setLastName(cadena);
    nag->setName(*N);

    // Especialidad del Agente
    do
    {
        system("cls");
        cout << endl << "\tAGREGAR NUEVO AGENTE" << endl;
        cout << endl << "\tEspecialidad. ";
        cout << endl << "\t1) Servidores.";
        cout << endl << "\t2) De Escritorio.";
        cout << endl << "\t3) Portatiles.";
        cout << endl << "\t4) Linux.";
        cout << endl << "\t5) Impresoras.";
        cout << endl << "\t6) Redes."<< endl <<": ";
        cin >> o;

        switch (o)
        {
        case 1:
            cadena = "Servidores";
            break;
        case 2:
            cadena = "De Escritorio";
            break;
        case 3:
            cadena = "Portatiles";
            break;
        case 4:
            cadena = "Linux";
            break;
        case 5:
            cadena = "Impresoras";
            break;
        case 6:
            cadena = "Redes";
            break;
        default:
            system("cls");
            cout << "Escoja una opcion del menu...";
            pause();
            break;
        }
    } while (o > 6 || o < 1);

    nag->setSpeciality(cadena);

    // Numero de Extension del Agente
    system("cls");
    cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
    cout << "Numero de Extension [4 digitos]" << endl <<": ";

    cin.ignore();
    cin >> o;

    cadena = to_string(o);
    nag->setExtensionNumber(cadena);

    // Numero de empleado del Agente
    system("cls");
    cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
    cout << "Numero de empleado [9 digitos] " << endl << ": ";

    cin >> o;

    cadena = to_string(o);
    nag->setEmployeeNumber(cadena);

    // Hora de entrada
    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Hora de entrada [HH:] " << endl << ": ";
        cin >> o;
    } while (o > 24 || o < 0);
    T->setHour(o);

    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Minuto de entrada [:MM:] " << endl << ": ";
        cin >> o;
    } while (o > 59 || o < 0);
    T->setMinute(o);

    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Segundo de entrada [:SS] " << endl << ": ";
        cin >> o;
    } while (o > 59 || o < 0);
    T->setSecond(o);
    nag->setStartTime(*T);

    // Hora de salida
    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Hora de Salida [HH:] " << endl << ": ";
        cin >> o;
    } while (o > 24 || o < 0);
    T->setHour(o);

    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Minuto de Salida [:MM:] " << endl << ": ";

        cin >> o;
    } while (o > 59 || o < 0);
    T->setMinute(o);

    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Segundo de Salida [:SS] " << endl << ": ";
        cin >> o;
    } while (o > 59 || o < 0);
    T->setSecond(o);
    nag->setEndTime(*T);

    // Horas Extra
    do
    {
        system("cls");
        cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
        cout << "Horas extras [0-4] " << endl << ": ";
        cin >> o;

        if (o > 4)
        {
            cout << endl << "Por favor proporcione un n�mero de horas menor a 4." << endl << "Los trabajadores no pueden trabajar mas de 4 horas" << endl << endl;
        }
        else if (o < 0)
        {
            cout << endl << "Por favor proporcione un numero de horas mayor o igual a 0." << endl << endl;
        }
    } while (o > 4 || o < 0);

    cadena = to_string(o);
    nag->setExtraHours(cadena);
    ndn->setData(*nag);
    aList->insertAgent(*ndn);

    system("cls");
    cout << endl << "AGREGAR NUEVO AGENTE" << endl << endl;
    cout << "Agente agregado Exitosamente" << endl << endl;

    cout << "Datos del Nuevo agente" << endl << endl << nag->toString(false);

    pause();
}

void SecretaryMenu::delAgent(AgentList* aList)
{
    DoubleNode* aux = aList->getFirstPos();
    string myString;
    char c;
    int x;

    system("cls");
    cout << "Menu Eliminar Agente" << endl << endl;
    cout << "1) Eliminar un Agente" << endl;
    cout << "2) Eliminar todos los Agentes" << endl;

    cin >> x;

    if (x == 1)
    {
        system("cls");
        cout << "Menu Eliminar Agente" << endl << endl;
        cout << "Numero de Empelado: ";

        cin >> myString;
        do
        {
            if (aux->getData().getEmployeeNumber() == myString)
            {
                system("cls");
                cout << "Menu Eliminar Agente" << endl << endl;
                cout << "Agente encontrado" << endl;

                cout << aux->getData().toString(false);

                cout << endl << "Desea eliminar este Agente? (S/N): ";

                cin >> c;

                c = toupper(c);

                if (c == 'S')
                {
                    aList->deleteNode(aux);

                    system("cls");
                    cout << "Menu Eliminar Agente" << endl << endl;
                    cout << "Agente eliminado satisfactoriamente" << endl;
                }
                system("cls");
                cout << "Menu Eliminar Agente" << endl << endl;
                cout << "Retornando al menu principal" << endl;

                pause();

                return;
            }
            else
            {
                aux = aux->getNext();

                if (aux == nullptr)
                {
                    cout << "El Agente no ha sido encontrado" << endl;
                    cout << "Regresando al menu principal" << endl;

                    pause();
                }
            }
        } while (aux != nullptr);
    }
    else
    {
        aList->deleteAll();
    }
}

void SecretaryMenu::showAgentList(AgentList* aList)
{
    DoubleNode* aux = aList->getFirstPos();
    char op;
    bool myBool;

    do {
        system("cls");
        cout << "Menu Mostrar lista de agentes" << endl << endl;
        cout << "Mostrar Lista de llamadas?[S/N]\n: ";

        cin >> op;

        op = toupper(op);

        if (op != 'S' && op != 'N') {
            system("cls");
            cout << "Selecciona una opcion del menu";

            pause();
        }
    } while (op != 'S' && op != 'N');

    if (op == 'S') {
        myBool = true;
    }
    else {
        myBool = false;
    }

    if (aux == nullptr)
    {
        cout << "Lista Vacia" << endl;
        cout << "Retornando al menu principal" << endl;

        pause();

        return;
    }

    cout << aList->toString(myBool);

    pause();
}

void SecretaryMenu::sornAgentList(AgentList* aList)
{
    int myInt;

        do {
            system("cls");
            cout << "ORDENAR LISTA DE AGENTES" << endl;
            cout << endl << "1) Ordenar por Nombre.";
            cout << endl << "2) Ordenar por Especialidad." << endl << ": ";

            cin >> myInt;
        } while (myInt < 3 && myInt > 0);

    // Ordenar por Nombre
    if (myInt == 1) {
        
    }
    else {
        // Ordenar por especialidad

    }
}

void SecretaryMenu::findAgent(AgentList* aList)
{
    DoubleNode* aux = aList->getFirstPos();
    string myString;
    int x;

    system("cls");
    cout << "Menu Buscar Agente" << endl << endl;
    cout << "Numero de Empelado: ";

    cin >> x;

    myString = to_string(x);

    do
    {
        if (aux->getData().getEmployeeNumber() == myString)
        {
            cout << "Agente encontrado" << endl;
            cout << aux->getData().toString(true);

            pause();
        }
        else
        {
            aux = aux->getNext();

            if (aux == nullptr)
            {
                cout << "El Agente no ha sido encontrado" << endl;
                cout << "Regresando al menu principal" << endl;

                pause();
            }
        }
    } while (aux != nullptr);
}

void SecretaryMenu::modAgent(AgentList* aList)
{
    Name n;
    Time t;
    DoubleNode* aux = aList->getFirstPos();
    string myString;
    int x;

    system("cls");
    cout << "Menu Modificar Agente" << endl << endl;
    cout << "Numero de Empelado: ";

    cin >> x;

    myString = to_string(x);

    do
    {
        if (aux->getData().getEmployeeNumber() == myString)
        {
            system("cls");
            cout << "MENU MODIFICAR AGENTE" << endl;
            cout << endl << "Agente encontrado";
            cout << endl << "Datos del Agente" << endl << aux->getData().toString(true) << endl;

            cout << endl << "Escoja el dato a modificar: ";
            cout << endl << "1) Numero de Extension";
            cout << endl << "2) Especialidad";
            cout << endl << "3) Numero de Empleado";
            cout << endl << "4) Horas Extra";
            cout << endl << "5) Nombre";
            cout << endl << "6) Hora de Entrada";
            cout << endl << "7) Hora de salida";
            cout << endl << ": ";
            cin >> x;

            system("cls");
            cout << "Menu Modificar Agente" << endl;
            cout << "Escriba el nuevo dato: " << endl;

            switch (x)
            {
            case 1:
            {
                cout << "Numero de Extension [4 digitos]\n: ";

                cin.ignore();
                cin >> x;

                myString = to_string(x);
                aux->getData().setExtensionNumber(myString);            }
            break;
            case 2:
            {
                cout << endl << "\tEspecialidad: ";
                cout << endl << "\t1) Servidores.";
                cout << endl << "\t2) De Escritorio.";
                cout << endl << "\t3) Portatiles.";
                cout << endl << "\t4) Linux.";
                cout << endl << "\t5) Impresoras.";
                cout << endl << "\t6) Redes.";
                cout << ": ";

                cin >> x;

                switch (x)
                {
                case 1:
                    myString = "Servidores";
                    break;
                case 2:
                    myString = "De Escritorio";
                    break;
                case 3:
                    myString = "Portatiles";
                    break;
                case 4:
                    myString = "Linux";
                    break;
                case 5:
                    myString = "Impresoras";
                    break;
                case 6:
                    myString = "Redes";
                    break;
                default:
                    system("cls");
                    cout << "Escoja una opcion del menu...";

                    pause();
                    break;
                }
                while (x > 6 || x < 1);

                aux->getData().setSpeciality(myString);
            }
            break;
            case 3:
            {
                cout << endl << "Numero de Empleado: ";

                cin >> x;

                myString = to_string(x);
                aux->getData().setEmployeeNumber(myString);
            }
            break;
            case 4:
            {
                cout << endl << "Horas Extra: ";

                cin >> x;

                myString = to_string(x);
                aux->getData().setExtraHours(myString);
            }
            break;
            case 5:
            {
                cout << endl << "Nombre(s): ";

                cin.ignore();
                getline(cin, myString);
                n.setName(myString);

                cout << endl << "Apellidos: ";

                cin.ignore();
                getline(cin, myString);
                n.setLastName(myString);
                aux->getData().setName(n);
            }
            break;
            case 6:
            {
                do
                {
                    cout << endl << "Hora: ";

                    cin >> x;
                } while (x > 24 || x < 0);
                t.setHour(x);

                do
                {
                    cout << endl << "Minuto: ";

                    cin >> x;
                } while (x > 59 || x < 0);
                t.setMinute(x);

                do
                {
                    cout << endl << "Segundo: ";

                    cin >> x;
                } while (x > 59 || x < 0);
                t.setSecond(x);
                aux->getData().setStartTime(t);
            }
            break;
            case 7:
            {
                do
                {
                    cout << endl << "Hora: ";

                    cin >> x;
                } while (x > 24 || x < 0);
                t.setHour(x);

                do
                {
                    cout << endl << "Minuto: ";

                    cin >> x;
                } while (x > 59 || x < 0);
                t.setMinute(x);

                do
                {
                    cout << endl << "\Segundo: ";

                    cin >> x;
                } while (x > 59 || x < 0);
                t.setSecond(x);
                aux->getData().setEndTime(t);
            }
            break;
            default:
                break;
            }
            cout << endl << endl << "Dato modificado correctamente" << endl << endl;
            cout << aux->getData().toString(true);

            pause();
        }
        else
        {
            aux = aux->getNext();
            if (aux == nullptr)
            {
                cout << "\nEl Agente no ha sido encontrado" << endl;
                cout << "\nRegresando al menu principal" << endl;

                pause();
            }
        }
    } while (aux != nullptr);
}

void SecretaryMenu::addClientToAgent(AgentList* aList)
{
    SimplyNode* node = new SimplyNode();
    DoubleNode* aux = aList->getFirstPos();
    Client* call = new Client();
    Time* t = new Time();
    string cadena;
    int x;

    // Busqueda de cliente por numero de empleado
    do
    {
        if (aux->getData().getEmployeeNumber() == cadena)
        {
            system("cls");
            cout << "AGREGAR CLIENTE A UN AGENTE";
            cout << endl << "Numero de empleado [9 digitos]" << endl << ": ";

            cin >> cadena;

            // Hora de atencion
            do
            {
                system("cls");
                cout << "AGREGAR CLIENTE A UN AGENTE";
                cout << endl << "Hora de atencion [HH:] " << endl << ": ";

                cin >> x;
            } while (x > 24 || x < 0);
            t->setHour(x);

            do
            {
                system("cls");
                cout << "AGREGAR CLIENTE A UN AGENTE";
                cout << endl << "Minuto de atencion [:MM:] " << endl << ": ";

                cin >> x;
            } while (x > 59 || x < 0);
            t->setMinute(x);

            do
            {
                system("cls");
                cout << "AGREGAR CLIENTE A UN AGENTE";
                cout << endl << "Segundo de atencion [:SS]" << endl << ": ";

                cin >> x;
            } while (x > 59 || x < 0);
            t->setSecond(x);
            call->setTimeAtention(*t);

            // Duracion de la llamada
            do
            {
                system("cls");
                cout << "AGREGAR CLIENTE A UN AGENTE";
                cout << endl << "Hora de la Duracion de la llamada [HH:]" << endl << ": ";

                cin >> x;

            } while (x > 24 || x < 0);
            t->setHour(x);

            do
            {
                system("cls");
                cout << "AGREGAR CLIENTE A UN AGENTE";
                cout << endl << "Minuto de la duracion de la llamada [:MM:] " << endl << ": ";

                cin >> x;

            } while (x > 59 || x < 0);
            t->setMinute(x);

            do
            {
                system("cls");
                cout << "AGREGAR CLIENTE A UN AGENTE";
                cout << endl << "Segundo de la duracion de la llamada [:SS]" << endl << ": ";

                cin >> x;
            } while (x > 59 || x < 0);
            t->setSecond(x);

            call->setAtentionDuration(*t);
            node->setData(*call);
            aux->getData().getClientList().insertOrdered(*node);
        }
        else
        {
            aux = aux->getNext();

            if (aux == nullptr) {
                system("cls");
                cout << "Agente no encontrado" << endl;
                cout << cadena << " no fue localizado." << endl << endl;

                pause();
            }
        }
    } while (aux != nullptr);
}

void SecretaryMenu::deleteClientToAgent(AgentList* aList)
{
    int x;
    string myString;
    SimplyNode* s = nullptr;
    DoubleNode* aux = aList->getFirstPos();

    system("cls");
    cout << "ELIMINAR LLAMADA\n";
    cout << "\n1) Eliminar una Llamada.";
    cout << "\n2) Eliminar Todas las Llamadas.\n: ";
    cin >> x;

    if (x == 1)
    {
        system("cls");
        cout << "ELIMINAR LLAMADA\n";
        cout << "Numero de Empelado [9 digitos]: ";

        cin >> x;

        myString = to_string(x);

        do
        {
            if (aux->getData().getEmployeeNumber() == myString)
            {
                system("cls");
                cout << "ELIMINAR LLAMADA\n";
                cout << "\nSelecciona una Llamada.\n\n";

                s = aux->getData().getClientList().getFirstPos();

                cout << "\n: ";
                cin >> x;

                for (int i = 0; i < x; i++)
                {
                    s = s->getNext();
                }

                delete s;
            }
            else
            {
                aux = aux->getNext();

                if (aux == nullptr)
                {
                    cout << "El Agente no ha sido encontrado" << endl;
                    cout << "Regresando al menu principal" << endl;

                    pause();
                }
            }
        } while (aux != nullptr);
    }
    else
    {
        system("cls");
        cout << "ELIMINAR TODAS LAS LLAMADAS\n";
        cout << "\nSelecciona un Agente.\n\n";
        aList->toString(false);
        cout << "\n: ";
        cin >> x;

        for (int i = 0; i < x; i++)
        {
            aux = aux->getNext();
        }
        aux->getData().getClientList().deleteAll();
    }
}

void SecretaryMenu::modAtDrtnToAgent(AgentList* aList) // E6
{
    Time* t = new Time();
    DoubleNode* a = aList->getFirstPos();
    SimplyNode* s;
    int x;

    system("cls");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    if (aList->getFirstPos() == nullptr)
    {
        cout << "Lista Vacia\nRegresando al menu principal\n\n";
        pause();
        return;
    }
    cout << "\nSelecciona un Agente.\n\n";
    aList->toString(false);
    cout << "\n: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        a = a->getNext();
    }

    system("cls");
    cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
    if (a->getData().getClientList().getFirstPos() == nullptr)
    {
        cout << "Lista Vacia\nRegresando al menu principal\n\n";
        pause();
        return;
    }
    cout << "\nSelecciona una Llamada.\n\n";
    s = a->getData().getClientList().getFirstPos();
    cout << "\n: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        s = s->getNext();
    }

    do
    {
        system("cls");
        cout << "MODOFICAR HORA DE ATENCION DE LLAMADA\n";
        cout << "NUEVA HORA PARA EL CLIENTE SELECCIONADO";
        cout << "\nHH: ";
        cin >> x;
    } while (x > 24 || x < 0);
    t->setHour(x);

    do
    {
        system("cls");
        cout << "\nMM: ";
        cin >> x;
    } while (x > 59 || x < 0);
    t->setMinute(x);

    do
    {
        system("cls");
        cout << "\nSS: ";
        cin >> x;
    } while (x > 59 || x < 0);
    t->setSecond(x);
    s->getData().setTimeAtention(*t);
}

void SecretaryMenu::saveLists(AgentList* aList)
{
}

void SecretaryMenu::loadLists(AgentList* aList)
{
}

void SecretaryMenu::pause()
{
    cout << "\nEnter para continuar...";
    cin.ignore();
}
