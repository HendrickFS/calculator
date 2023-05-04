#pragma once
#include "calculator.hpp"
#include <cstddef>

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
