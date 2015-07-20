//
//  lexer.h
//  
//
//  Created by Jason Lin on 11/02/2015.
//
//

#ifndef ____Lexer__
#define ____Lexer__

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

class Lexer
{
private:
  //func  list[2];
  //void   (*func)(const std::string &);
protected:
  std::string tab[11];
  std::string type;
  std::string value;
  std::string command;
  int NbCommand;
public:
  Lexer();
  ~Lexer();
  void TabInit();
  void executeAction();
  void execute(std::vector<std::string> words, int i);
  void setCommand(std::string command);
  void setNbCommand(int j);
  void setValue(std::string value);
  std::string getCommand() const;
  int getNbCommand() const;
  std::string getValue() const;
    
    
};

#endif /* defined(____lexer__) */

