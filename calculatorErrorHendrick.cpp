#include "calculatorErrorHendrick.hpp"
#include <iostream>

CalculatorErrorHendrick::CalculatorErrorHendrick(char const *message)
{
  this->message = message;
}
char const *CalculatorErrorHendrick::getMessage() { return this->message; }