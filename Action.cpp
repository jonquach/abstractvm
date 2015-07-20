//
// Action.cpp for  in /home/quach_a/Dropbox/EPITECH PROJET/TEK2/lin_c/Abstract_VM
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sun Mar  1 21:25:32 2015 Jonathan Quach
// Last update Sun Mar  1 22:52:39 2015 Jonathan Quach
//

#include "Action.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Exception.hpp"

Action::Action()
{
  _funcList[0] = &Action::createInt8;
  _funcList[1] = &Action::createInt16;
  _funcList[2] = &Action::createInt32;
  _funcList[3] = &Action::createFloat;
  _funcList[4] = &Action::createDouble;
  tab[0] = "INT8";
  tab[1] = "INT16";
  tab[2] = "INT32";
  tab[3] = "FLOAT";
  tab[4] = "DOUBLE";
}

Action::~Action()
{}

bool Action::findNbType(const std::string &tmp)
{
  for (int i = 0; i < 5 ; i++)
    {
      if (tmp.compare(tab[i]) == 0)
        {
	  setNbType(i);
	  return true;
        }
    }
  throw SyntaxException("[SyntaxException] : type not found");
}

bool Action::getIntType(const std::string &value)
{
  std::string tmp;
  int end = value.find('(');
  tmp.append(value, 0, end);
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), toupper);

  if (findNbType(tmp) == false)
    return false;
  switch (this->NbType)
    {
    case 0:
      type = INT8;
      break;
    case 1:
      type = INT16;
      break;
    case 2:
      type = INT32;
      break;
    case 3:
      type = FLOAT;
      break;
    case 4:
      type =  DOUBLE;
    }
  return true;
}

void Action::exec_func(int NbCommand, IOperand *op)
{
  switch(NbCommand)
    {
    case 0:
      print();
      break;
    case 1:
      pop();
      break;
    case 2:
      dump();
      break;
    case 3:
      add();
      break;
    case 4:
      sub();
      break;
    case 5:
      mul();
      break;
    case 6:
      div();
      break;
    case 7:
      mod();
      break;
    case 8:
      exit();
      break;
    case 9:
      push(op);
      break;
    case 10:
      assert(op);
      break;
    }
}

void Action::executeAction(int NbCommand, std::string value)
{
  if (value == "" && NbCommand >= 9)
    throw SyntaxException("[SyntaxException] : Syntax Error");
  std::string tmp;
  IOperand *op;

  if (value != "")
    {
      if (getIntType(value) == false)
	return;
      int end = value.find(')');
      int start = value.find('(');
      int a = value.length();
      if (end != a - 1)
	throw SyntaxException("[SyntaxException] : Missing end of parenthesis");
      tmp.append(value,start + 1,end - start - 1);
      int i = 0;
      if (tmp == "")
	throw SyntaxException("[SyntaxException] : The value isn't valid");
      while (tmp[i])
	{
	  if (isdigit(tmp[i]) || tmp[i] == '.')
	    i++;
	  else
	    throw SyntaxException("[SyntaxException] : The value isn't valid");
	}
      op = createOperand(type, tmp);
    }
  exec_func(NbCommand,op);
}

IOperand		*Action::createInt8(const std::string &value)
{
  IOperand		*operand;
  std::stringstream           ss;
  double                      nb;
    
  ss << value;
  ss >> nb;

  operand = new Operand<char>(INT8, nb);
  return (operand);
}

IOperand		*Action::createInt16(const std::string &value)
{
  IOperand		*operand;
  std::stringstream           ss;
  double                      nb;
    
  ss << value;
  ss >> nb;

  operand = new Operand<short>(INT16, nb);
  return (operand);
}

IOperand		*Action::createInt32(const std::string &value)
{
  IOperand		*operand;
  std::stringstream           ss;
  double                      nb;
    
  ss << value;
  ss >> nb;
  operand = new Operand<int>(INT32, nb);
  return (operand);
}

IOperand		*Action::createFloat(const std::string &value)
{
  IOperand		*operand;
  std::stringstream           ss;
  double                      nb;
    
  ss << value;
  ss >> nb;
  operand = new Operand<float>(FLOAT, nb);
  return (operand);
}

IOperand		*Action::createDouble(const std::string &value)
{
  IOperand		*operand;
  std::stringstream           ss;
  double                      nb;
    
  ss << value;
  ss >> nb;
  operand = new Operand<double>(DOUBLE, nb);
  return (operand);
}

IOperand		*Action::createOperand(eOperandType type, const std::string &value)
{
  return ((this->*_funcList[type])(value));
}

void			Action::push(IOperand *rhs)
{
  _stack.push_front(rhs);
}

void			Action::pop()
{
  if (_stack.size() == 0)
    throw SyntaxException("[PopException] : Pop on empty stack.");
  _stack.pop_front();
}

void                    Action::dump()
{
  if (_stack.size() == 0)
    throw SyntaxException("[DumpException] : Dump on empty stack.");
  for (std::list<IOperand *>::iterator it = _stack.begin(); it != _stack.end(); ++it)
    std::cout << (*it)->toString() << std::endl;
}

IOperand		*Action::get()
{
  if (_stack.size() == 0)
    throw SyntaxException("[StackException] : Empty Stack");
  return (_stack.front());
}

IOperand		*Action::add()
{
  if (_stack.size() < 2)
    throw SyntaxException("[AddException] : Need at least two elements to add.");
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a + *b);
  return (get());
}

IOperand		*Action::sub()
{
  if (_stack.size() < 2)
    throw SyntaxException("[SubException] : Need at least two elements to sub.");
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a - *b);
  return (get());
}

IOperand		*Action::mul()
{
  if (_stack.size() < 2)
    throw SyntaxException("[MulException] : Need at least two elements to mul.");
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a * *b);
  return (get());
}

IOperand		*Action::div()
{
  if (_stack.size() < 2)
    throw SyntaxException("[DivException] : Need at least two elements to div.");
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a / *b);
  return (get());
}

IOperand		*Action::mod()
{
  if (_stack.size() < 2)
    throw SyntaxException("[ModException] : Need at least two elements to mod.");
  IOperand		*a = get();
  pop();
  IOperand		*b = get();
  pop();

  push(*a % *b);
  return (get());
}

void Action::assert(IOperand *rhs)
{
  if (_stack.size() < 1)
    throw SyntaxException("[AssertException] : Need at least a element to assert");
  if (rhs->toString().compare(_stack.front()->toString()))
    throw SyntaxException("[AssertException]: Value to assert isn't the same than the first element on the stack");
}

void Action::print()
{
  std::stringstream           ss;
  int                         tmp;
  char                        c;

  if (_stack.size() < 1)
    throw SyntaxException("[PrintException] : Need at least a element to print");
  if (type == INT8)
    {
      ss << _stack.front()->toString();
      std::cout << ss.str() << std::endl;
      ss >> tmp;
      c = tmp;
      std::cout << c << std::endl;
    }
  else
    throw SyntaxException("[PrintTypeException] : Element to print need to be a INT8");
}

void Action::exit()
{
  return;
}

// getters & setters

void        Action::setVector(std::string content)
{
  dumpTab.push_back(content);
}

void        Action::setNbType(int i)
{
  this->NbType = i;
}

std::vector<std::string>        Action::getDump() const
{
  return dumpTab;
}
