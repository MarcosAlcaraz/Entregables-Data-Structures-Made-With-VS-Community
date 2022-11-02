#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_H_INCLUDED

#include <iostream>
#include <exception>

class ListException : public std::exception {
private:
	std::string msg;

public:
	explicit ListException(const char* message);
	explicit ListException(const std::string& message);
	virtual ~ListException() throw ();
	virtual const char* what() const throw ();

};

#endif // !LISTEXCEPTION_HPP_INCLUDED
