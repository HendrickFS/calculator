#include "keyHendrick.hpp"

KeyDigitHendrick::KeyDigitHendrick(Symbol symbol, Digit digit)
{
  this->symbol = symbol;
  this->digit = digit;
}
void KeyDigitHendrick::press()
{
  if (this->keyboard != NULL)
    this->keyboard->receive(this->digit);
}
Symbol KeyDigitHendrick::getSymbol() { return this->symbol; }
void KeyDigitHendrick::setKeyboard(Keyboard *keyboard)
{
  this->keyboard = keyboard;
}
Digit KeyDigitHendrick::getDigit() { return this->digit; }

KeyControlHendrick::KeyControlHendrick(Symbol symbol, Control control)
{
  this->symbol = symbol;
  this->control = control;
}
void KeyControlHendrick::press()
{
  if (this->keyboard != NULL)
    this->keyboard->receive(this->control);
}
Symbol KeyControlHendrick::getSymbol() { return this->symbol; }
void KeyControlHendrick::setKeyboard(Keyboard *keyboard)
{
  this->keyboard = keyboard;
}
Control KeyControlHendrick::getControl() { return this->control; }

KeyOperatorHendrick::KeyOperatorHendrick(Symbol symbol, Operator operator_)
{
  this->symbol = symbol;
  this->operator_ = operator_;
}
void KeyOperatorHendrick::press()
{
  if (this->keyboard != NULL)
    this->keyboard->receive(this->operator_);
}
Symbol KeyOperatorHendrick::getSymbol() { return this->symbol; }
void KeyOperatorHendrick::setKeyboard(Keyboard *keyboard)
{
  this->keyboard = keyboard;
}
Operator KeyOperatorHendrick::getOperator() { return this->operator_; }