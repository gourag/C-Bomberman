#ifndef _MYEXCEPTION_H_
# define _MYEXCEPTION_H_

#include <exception>
#include <string>

class MyException : public std::exception
{
private:
  std::string	_error;

public:
  MyException(const std::string &error = "") throw();
  virtual ~MyException() throw();

  const char	*what() const throw();
};


#endif /* _MYEXCEPTION_H_ */
