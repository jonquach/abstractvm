//
// Exception.cpp for  in /home/quach_a/Dropbox/EPITECH PROJET/TEK2/lin_c/Abstract_VM
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sun Mar  1 19:39:13 2015 Jonathan Quach
// Last update Sun Mar  1 19:39:43 2015 Jonathan Quach
//

#include "Exception.hpp"

SyntaxException::SyntaxException(std::string const &msg) throw()
{
  _msg = msg;
}

SyntaxException::~SyntaxException() throw()
{

}

const char *SyntaxException::what() const throw()
{
  return (_msg.c_str());
}
