#include "calculator.hpp"
#include "keyboardHendrick.hpp"
#include "calculatorErrorHendrick.hpp"
#include <vector>
#include <cstddef>
#include <iostream>

void KeyboardHendrick::receive(Digit digit)
{
  if (this->cpu)
    this->cpu->receive(digit);
  else
    std::cerr << "Keyboard without cpu!\n";
}
void KeyboardHendrick::receive(Operator operator_)
{
  if (this->cpu)
    this->cpu->receive(operator_);
  else
    std::cerr << "Keyboard without cpu!\n";
}

void KeyboardHendrick::receive(Control control)
{
  if (this->cpu)
    this->cpu->receive(control);
  else
    std::cerr << "Keyboard without cpu!\n";
}
Key *KeyboardHendrick::getKey(Digit digit)
{
  for (Key *key : this->keys)
    if (dynamic_cast<KeyDigit *>(key) && ((KeyDigit *)key)->getDigit() == digit)
      return key;
  throw new CalculatorErrorHendrick("Key with digit not found!");
}
Key *KeyboardHendrick::getKey(Operator operator_)
{
  for (Key *key : this->keys)
    if (dynamic_cast<KeyOperator *>(key) && ((KeyOperator *)key)->getOperator() == operator_)
      return key;
  throw new CalculatorErrorHendrick("Key with operator not found!");
}
Key *KeyboardHendrick::getKey(Control control)
{
  for (Key *key : this->keys)
    if (dynamic_cast<KeyControl *>(key) && ((KeyControl *)key)->getControl() == control)
      return key;
  throw new CalculatorErrorHendrick("Key with control not found!");
}
Key *KeyboardHendrick::getKey(Symbol symbol)
{
  for (Key *key : this->keys)
    if (key->getSymbol() == symbol)
      return key;
  throw new CalculatorErrorHendrick("Key with symbol not found!");
}
void KeyboardHendrick::add(Key *key)
{
  if (key != NULL)
  {
    this->keys.push_back(key);
    key->setKeyboard(this);
  }
}
void KeyboardHendrick::setCpu(Cpu *cpu) { this->cpu = cpu; }
//