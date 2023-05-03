#pragma once
#include "calculator.hpp"

class Stack
{
  int topo;
  char *vector;
  int tam;

public:
  Stack(int tam);
  void push(char valor);
  char pop();
  int getTopo();
  int getTam();
  char *getVet();
  void setTopo(int topo);
  void setTam(int tam);
  void setVet(char *vector);
  void inverte();
};

class DisplayHendrick : public Display
{
public:
  void add(Digit digit);
  void setSignal(Signal);
  void addDecimalSeparator();
  void clear();
};

class CpuHendrick : public Cpu
{
  Display *display;
  Stack *register01;
  Stack *register02;
  Operator* op;

public:
  CpuHendrick();
  void receive(Digit);
  void receive(Operator);
  void receive(Control);
  void setDisplay(Display *);
};

#include <vector>
class KeyboardHendrick : public Keyboard
{
  std::vector<Key *> keys;
  char keysCount = 0;
  Cpu *cpu;

public:
  void receive(Digit);
  void receive(Operator);
  void receive(Control);
  Key *getKey(Digit);
  Key *getKey(Operator);
  Key *getKey(Control);
  Key *getKey(Symbol);
  void add(Key *);
  void setCpu(Cpu *);
};

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

class CalculatorHendrick : public Calculator
{
  Display *display;
  Cpu *cpu;
  Keyboard *keyboard;

public:
  void setDisplay(Display *);
  Display *getDisplay();
  void setCpu(Cpu *);
  Cpu *getCpu();
  void setKeyboard(Keyboard *);
  Keyboard *getKeyboard();
};

class CalculatorErrorHendrick : public CalculatorError
{
  char const *message;

public:
  CalculatorErrorHendrick(char const *message);
  char const *getMessage();
};