#ifndef __AGENT_HPP__
#define __AGENT_HPP__

//Librerias de Compilador
#include <iostream>
#include <string>

//Librerias de Usuario
#include "clientlist.hpp"
#include "name.hpp"
#include "time.hpp"

//Clase
class Agent
{
private:
    //Atributos

    std::string extensionNumber;
    std::string specialty;

    std::string employeeNumber;
    std::string extraHours;

    Name name;
    Time startTime;
    Time endTime;

    ClientList clientList;

public:
    //Constructores
    Agent();
    Agent(const Agent&);

    ~Agent();

    //Getters
    std::string getEmployeeNumber() const;
    std::string getExtraHours() const;

    Name getName() const;

    std::string getExtensionNumber() const;
    std::string getSpecialty() const;

    Time getStartTime() const;
    Time getEndTime() const;

    ClientList getClientList() const;

    std::string toString(bool) const;

    //Setters
    void setExtensionNumber(const std::string&);
    void setSpeciality(const std::string&);
    void setName(const Name&);
    void setEmployeeNumber(const std::string&);
    void setExtraHours(const std::string&);
    void setStartTime(const Time&);
    void setEndTime(const Time&);

    //Operadores relacionales
    Agent& operator = (const Agent&);

    bool operator == (const Agent&) const;
    bool operator != (const Agent&) const;
    bool operator < (const Agent&) const;
    bool operator <= (const Agent&) const;
    bool operator > (const Agent&) const;
    bool operator >= (const Agent&) const;

    //Operadores de flujo
    friend std::ostream& operator << (std::ostream&, const Agent&);
    friend std::istream& operator >> (std::istream&, Agent&);
};

#endif // __AGENT_HPP__