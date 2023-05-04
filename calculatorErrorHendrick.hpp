#include "calculator.hpp"

class CalculatorErrorHendrick : public CalculatorError
{
  char const *message;

public:
  CalculatorErrorHendrick(char const *message);
  char const *getMessage();
};