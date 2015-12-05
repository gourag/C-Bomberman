#include "MyException.hh"

MyException::MyException(const std::string &error) throw()
{
  _error = error;
}
MyException::~MyException() throw()
{
}

const char	*MyException::what() const throw()
{
  return _error.c_str();
}
