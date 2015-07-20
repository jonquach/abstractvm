//
// Operand.cpp for  in /home/quach_a/Dropbox/EPITECH PROJET/TEK2/lin_c/Abstract_VM
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sun Mar  1 20:02:15 2015 Jonathan Quach
// Last update Sun Mar  1 20:02:25 2015 Jonathan Quach
//

#include "Operand.hpp"

std::ostream &operator<<(std::ostream &os, IOperand const &rhs)
{
  os << rhs.toString();
  return (os);
}
