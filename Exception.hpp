#ifndef __EXCEPTION_HPP__
#define	__EXCEPTION_HPP__

#include <string>
#include <exception>

class SyntaxException : public std::exception
{
public:
  SyntaxException(std::string const &) throw();
  virtual ~SyntaxException() throw();

  virtual const char* what() const throw();

private:
  std::string   _msg;
};

#endif	/* __EXCEPTION_HPP__ */

