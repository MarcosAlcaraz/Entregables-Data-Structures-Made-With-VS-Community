#ifndef SECRETARYMENU_HPP
#define SECRETARYMENU_HPP

#include<iostream>
#include<string>

#include "agentlist.hpp"
#include "clientlist.hpp"
#include "agent.hpp"
#include "client.hpp"
#include "name.hpp"
#include "time.hpp"

class SecretaryMenu
{
private:
    AgentList* aList;

    void mainMenu();
    
    void addAgentMenu();
    void delAgentMenu();
    void modAgentMenu();
    void sornAgentListMenu();

    void showAgentListMenu();
    void findAgentMenu();
    
    void addClientToAgentMenu();
    void deleteClientToAgentMenu();
    void modAtDrtnToAgentMenu();

    void saveListsMenu();
    void loadListsMenu();

    void pause();

public:
    SecretaryMenu(AgentList*);
};

#endif // SECRETARYMENU_HPP
