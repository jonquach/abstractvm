//
//  parse.cpp
//  
//
//  Created by Jason Lin on 10/02/2015.
//
//

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "Parse.hpp"
#include "Exception.hpp"

Parser::Parser()
{
  nbArguments = 0;
}

Parser::~Parser()
{}

void Parser::parse(std::string content)
{
  std::stringstream ss;
  std::vector<std::string> words;
  int i = 0;

  ss << content;   
  while (ss)
    {
      std::string tmp;
      ss >> tmp;
      words.push_back(tmp);
      i++;
    }
  setVector(words);
  setNbArguments(i);
}

std::vector<std::string> Parser::getVector() const
{
  return this->words;
}

int Parser::getNbArguments() const
{
  return this->nbArguments;
}

void Parser::setVector(std::vector<std::string> vector)
{
  this->words = vector;
}

void Parser::setNbArguments(int i)
{
  this->nbArguments = i;
}
