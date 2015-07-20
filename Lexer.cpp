//
//  lexer.cpp
//  
//
//  Created by Jason Lin on 11/02/2015.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "Lexer.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Action.hpp"
#include "Exception.hpp"

Lexer::Lexer()
{
  TabInit();
  command = "";
  value = "";
}

Lexer::~Lexer()
{
    
}

void Lexer::TabInit()
{
  tab[0] = "print";
  tab[1] = "pop";
  tab[2] = "dump";
  tab[3] = "add";
  tab[4] = "sub";
  tab[5] = "mul";
  tab[6] = "div";
  tab[7] = "mod";
  tab[8] = "exit";
  tab[9] = "push";
  tab[10] = "assert";
}

void Lexer::execute(std::vector<std::string> words, int i)
{
  std::vector<std::string>::iterator it = words.begin();
  std::string command = *it;
  std::string tmp;
  int j = 0;

  if (command[0] == ';' || command[0] == '\0')
    {
      setValue("skip");
      return;
    }
  while (j <= 10)
    {
      if (command.compare(tab[j]) == 0)
        {
	  if (i > 2 && j <= 8)
            {
	      tmp = words.at(1);
	      if (tmp.find(";") != 0)
		throw SyntaxException("[SyntaxException] : Wrong syntax.");
            }
	  else if (i > 3 && j >= 9)
            {
	      tmp = words.at(2);
	      if (tmp.find(";") != 0)
		throw SyntaxException("[SyntaxException] : Wrong syntax.");
            }
	  if (j >= 9)
            {
	      std::string value = words.at(1);
	      setValue(value);
            }
	  setCommand(command);
	  setNbCommand(j);
	  return;
	}
      j++;
    }
  throw SyntaxException("[SyntaxException] : Command not found");
}

void  Lexer::setCommand(std::string command)
{
  this->command = command;
}

void Lexer::setNbCommand(int j)
{
  this->NbCommand = j;
}

void   Lexer::setValue(std::string value)
{
  this->value = value;
}

std::string Lexer::getCommand() const
{
  return command;
}

std::string Lexer::getValue() const
{
  return value;
}

int Lexer::getNbCommand() const{
  return NbCommand;
}
