//
//  main.cpp
//  
//
//  Created by Jason Lin on 09/02/2015.
//
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Action.hpp"
#include "Parse.hpp"
#include "Lexer.hpp"


void    checkEndFile(Lexer b,Action c)
{
  if (b.getNbCommand() != 8)
    std::cout << "The last command should be exit" << std::endl;
  if (!c.getDump().empty())
    {
      for (std::vector<std::string>::iterator it = c.getDump().begin(); it != c.getDump().end(); ++it)
	std::cout << *it << std::endl;
    }
}

void    execute_cin(Parser a, Lexer b, Action c)
{
  std::string end(";;");
  int i = 0;
  int status = 0;
  char buffer[4096];
  while (1)
    {
      std::cin.getline(buffer,4096);
      if (!end.compare(buffer))
	break;
      i++;
      if (status == 0)
        {
	  a.parse(buffer);
	  b.execute(a.getVector(),a.getNbArguments());
	  if (b.getNbCommand() == 8)
	    status = 1;
	  if (b.getValue() != "skip")
	    c.executeAction(b.getNbCommand(),b.getValue());
	  b.setValue("");
	}
    }
  checkEndFile(b,c);
}

void    exec(Parser a, Lexer b, Action c, std::string file)
{
  std::string line = "";
  std::ifstream flux(file.data());
  if (flux.is_open())
    {
      while (getline(flux,line))
        {
	  a.parse(line);
	  b.execute(a.getVector(),a.getNbArguments());
	  if (b.getNbCommand() == 8)
	    break;
	  if (b.getValue() != "skip")
	    c.executeAction(b.getNbCommand(),b.getValue());
	  b.setValue("");
        }
      checkEndFile(b,c);
    }
}

int main(int ac, char **av)
{
  Parser a;
  Lexer  b;
  Action c;
  std::string file;

  try {
    if (ac == 2)
      {
	file = av[1];
	exec(a, b, c, file);
      }
    else
      execute_cin(a, b, c);
  } catch (SyntaxException &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}

