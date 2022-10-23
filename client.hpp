#ifndef CLIENT_HPP
#define CLIENT_HPP

//Librerias de compilador
#include <iostream>
#include <string>
//Librerias de usuario
#include "time.hpp"

class Client
{
private:
    //ATTRIBUTES
    Time timeAtention;
    Time atentionDuration;

public:
    //CONSTRUCTOR
    Client(); // E4 (READY)
    Client(const Client&); // E4 (READY)

    //Getters
    Time getTimeAtention() const; // E4 (READY)
    Time getAtentionDuration() const; // E4 (READY)

    //Setters
    void setTimeAtention(const Time&); // E4 (READY)
    void setAtentionDuration(const Time&); // E4 (READY)

    //Build and Show Client Data
    std::string toString() const;

    //OPERATORs
    Client& operator=(const Client&);

    bool operator == (const Client&) const;
    bool operator != (const Client&) const;
    bool operator < (const Client&) const;
    bool operator <= (const Client&) const;
    bool operator > (const Client&) const;
    bool operator >= (const Client&) const;

    friend std::ostream& operator << (std::ostream&, const Client&);
    friend std::ostream& operator >> (std::ostream&, Client&);
};

#endif // CLIENT_HPP
