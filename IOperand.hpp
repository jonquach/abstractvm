#ifndef __IOPERAND_HPP__
#define __IOPERAND_HPP__

#include <string>
#include <iostream>

int     my_atoi(std::string);
double  my_atof(std::string);

enum eOperandType
{
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
};

class IOperand {
public:
  virtual std::string const& toString() const = 0;

  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;

  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {
  }
};

#endif /*__IOPERAND_HPP__ */

