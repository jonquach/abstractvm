//
//  Parse.h
//  
//
//  Created by Jason Lin on 10/02/2015.
//
//

#ifndef _Parse_h
#define _Parse_h

#include <string>
#include <vector>
#include <iostream>

class Parser
{
protected:
  std::string content;
  std::vector<std::string> words;
  int nbArguments;

public:
  Parser();
  ~Parser();
  void parse(std::string);
  std::vector<std::string> getVector() const;
  int getNbArguments() const;
  void setVector(std::vector<std::string> vector);
  void setNbArguments(int i);
};
#endif
