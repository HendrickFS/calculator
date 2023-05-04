#include "calculatorHendrick.hpp"

class KeyDigitHendrick : public KeyDigit
{
  Symbol symbol;
  Digit digit;
  Keyboard *keyboard;

public:
  KeyDigitHendrick(Symbol, Digit);
  void press();
  Symbol getSymbol();
  void setKeyboard(Keyboard *);
  Digit getDigit();
};

class KeyControlHendrick : public KeyControl
{
  Symbol symbol;
  Control control;
  Keyboard *keyboard;

public:
  KeyControlHendrick(Symbol, Control);
  void press();
  Symbol getSymbol();
  void setKeyboard(Keyboard *);
  Control getControl();
};

class KeyOperatorHendrick : public KeyOperator
{
  Symbol symbol;
  Operator operator_;
  Keyboard *keyboard;

public:
  KeyOperatorHendrick(Symbol, Operator);
  void press();
  Symbol getSymbol();
  void setKeyboard(Keyboard *);
  Operator getOperator();
};
