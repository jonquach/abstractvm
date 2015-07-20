#ifndef __ACTION_HPP__
#define	__ACTION_HPP__

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

typedef	std::list<IOperand *> opStack;

class	Action
{
private:
  typedef IOperand *(Action::*funcPtr)(const std::string &);

private:
  funcPtr		_funcList[5];
  opStack		_stack;
  eOperandType          type;
  int                   NbType;
  std::string            tab[5];
  std::vector<std::string>  dumpTab;

private:
  IOperand		*createInt8(const std::string &value);
  IOperand		*createInt16(const std::string &value);
  IOperand		*createInt32(const std::string &value);
  IOperand		*createFloat(const std::string &value);
  IOperand		*createDouble(const std::string &value);

public:
  Action();
  ~Action();
  void                 executeAction(int NbCommand, std::string value);
  IOperand		*createOperand(eOperandType type, const std::string &value);

  void			push(IOperand *rhs);
  void                  pop();
  void                  dump();
  void                  exit();
  void                  print();
  void                  assert(IOperand *rhs);
  IOperand		*get();
  IOperand		*add();
  IOperand		*sub();
  IOperand		*mul();
  IOperand		*div();
  IOperand		*mod();
    
  //getters & setters

  void                  exec_func(int NbCommand,IOperand *op);
  bool                  getIntType(const std::string &value);
  bool                  findNbType(const std::string &tmp);
  void                  setNbType(int i);
  void                  setVector(std::string);
  std::vector<std::string>        getDump() const;
};


#endif	/* __CALCULATOR_HPP__ */

