#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>

#include "time.hpp"

class Client
{
private:
    Time timeAtention;
    Time atentionDuration;

public:
    Client();
    Client(const Client&);

    Time getTimeAtention() const;
    Time getAtentionDuration() const;

    void setTimeAtention(const Time&);
    void setAtentionDuration(const Time&);

    std::string toString() const;

    Client& operator=(const Client&);

    bool operator == (const Client&) const;
    bool operator != (const Client&) const;
    bool operator < (const Client&) const;
    bool operator <= (const Client&) const;
    bool operator > (const Client&) const;
    bool operator >= (const Client&) const;

    friend std::ostream& operator << (std::ostream&, const Client&);
    friend std::istream& operator >> (std::istream&, Client&);
};

#endif // CLIENT_HPP
