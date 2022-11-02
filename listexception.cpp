#include "listexception.hpp"

ListException::ListException(const char* message)
{
	msg = message;
}

ListException::ListException(const std::string& message)
{
	msg = message;
}

ListException::~ListException() throw() {}

const char* ListException::what() const throw()
{
	return msg.c_str();
}
