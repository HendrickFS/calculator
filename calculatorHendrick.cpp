#include "calculatorHendrick.hpp"
#include <iostream>
#include <cmath>


void CalculatorHendrick::setDisplay(Display *display) { this->display = display; }
Display *CalculatorHendrick::getDisplay() { return this->display; }
void CalculatorHendrick::setCpu(Cpu *cpu) { this->cpu = cpu; }
Cpu *CalculatorHendrick::getCpu() { return this->cpu; }
void CalculatorHendrick::setKeyboard(Keyboard *keyboard) { this->keyboard = keyboard; }
Keyboard *CalculatorHendrick::getKeyboard() { return this->keyboard; }