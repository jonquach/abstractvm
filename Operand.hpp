#ifndef __OPERAND_HPP__
#define __OPERAND_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "IOperand.hpp"
#include "Exception.hpp"

template <typename T>
class Operand : public IOperand 
{
private:
  eOperandType	_type;
  int		_precision;
  std::string	valueS;
  T		_value;

public:
  explicit Operand(eOperandType type, const double &value) 
  {
    std::stringstream ss;

    _type = type;
    _precision = type;
    if (value < std::numeric_limits<T>::min())
      throw SyntaxException("[LimitException] : Underflow");
    else if (value > std::numeric_limits<T>::max())
      throw SyntaxException("[LimitException] : Overflow");
    _value = value;
    if (type == INT8)
      ss << value;
    else
      ss << _value;
    ss >> valueS;
  }

  virtual std::string const &toString() const 
  {
    return valueS;
  }

  virtual int getPrecision() const {
    return (_precision);
  }

  virtual eOperandType getType() const {
    return (_type);
  }

  virtual T getValue() const {
    return (_value);
  }

  virtual IOperand *operator+(const IOperand &rhs) const {
    IOperand		*operand = NULL;
    eOperandType	type;
    std::stringstream           ss;
    double                      nb;

    ss << rhs.toString();
    ss >> nb;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value + nb);
      break;
    case INT16:
      operand = new Operand<short>(type, _value + nb);
      break;
    case INT32:
      operand = new Operand<int>(type, _value + nb);
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value + nb);
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value + nb);
      break;
    }
    return (operand);
  }

  virtual IOperand *operator-(const IOperand &rhs) const
  {
    IOperand		*operand = NULL;
    eOperandType	type;
    std::stringstream           ss;
    double                      nb;

    ss << rhs.toString();
    ss >> nb;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value - nb);
      break;
    case INT16:
      operand = new Operand<short>(type, _value - nb);
      break;
    case INT32:
      operand = new Operand<int>(type, _value - nb);
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value - nb);
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value - nb);
      break;
    }
    return (operand);
  }

  virtual IOperand *operator*(const IOperand &rhs) const
  {
    IOperand		*operand = NULL;
    eOperandType	type;
    std::stringstream           ss;
    double                      nb;

    ss << rhs.toString();
    ss >> nb;

    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value * nb);
      break;
    case INT16:
      operand = new Operand<short>(type, _value * nb);
      break;
    case INT32:
      operand = new Operand<int>(type, _value * nb);
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value * nb);
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value * nb);
      break;
    }
    return (operand);
  }

  virtual IOperand *operator/(const IOperand &rhs) const
  {
    IOperand		         *operand = NULL;
    eOperandType	         type;
    std::stringstream           ss;
    double                      nb;

    //get Nb
    ss << rhs.toString();
    ss >> nb;
    if (nb == 0)
      throw SyntaxException("[DivException] : Division by zero.");
    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    switch (type) {
    case INT8:
      operand = new Operand<char>(type, _value / nb);
      break;
    case INT16:
      operand = new Operand<short>(type, _value / nb);
      break;
    case INT32:
      operand = new Operand<int>(type, _value / nb);
      break;
    case FLOAT:
      operand = new Operand<float>(type, _value / nb);
      break;
    case DOUBLE:
      operand = new Operand<double>(type, _value / nb);
      break;
    }
    return (operand);
  }

  virtual IOperand *operator%(const IOperand &rhs) const
  {
    IOperand                  *operand = NULL;
    eOperandType              type;    
    std::stringstream           ss;
    double                      nb;
    int                         i;

    //get Nb
    ss >> nb;
    ss >> i;
    type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
    if (_type == FLOAT)
      throw SyntaxException("[ModException] : Modulo with float.");
    else if (_type == DOUBLE)
      throw SyntaxException("[ModException] : Modulo with double.");
    operand = new Operand(type, (int)_value % i);
    return (operand);
  }

  std::ostream &operator<<(std::ostream &os) 
  {
    os << this->getValue();
    return (os);
  }
};

std::ostream		&operator<<(std::ostream &os, IOperand const &rhs);

#endif /*__OPERAND_HPP */
