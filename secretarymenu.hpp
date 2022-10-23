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
public:
    //CONSTRUCTOR
    SecretaryMenu();
    //SecretaryMenu(AgentList*);

    //MAIN MENU
    void mainMenu();

    //AGENT MENUs MANAGER
    void addAgent(AgentList*); // (READY) E9
    void delAgent(AgentList*); // (READY) E9
    void showAgentList(AgentList*); // (READY) E9
    void sornAgentList(AgentList*);
    void findAgent(AgentList*); // (READY) E9
    void modAgent(AgentList*); // (READY) E9

    //CLIENT MENUs MANAGER
    void addClientToAgent(AgentList*); // (READY)
    void deleteClientToAgent(AgentList*); // (READY)
    void modAtDrtnToAgent(AgentList*); // (READY) E6

    //DISK MENUs
    void saveLists(AgentList*);
    void loadLists(AgentList*);

    void pause();

};

#endif // SECRETARYMENU_HPP
