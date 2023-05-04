#pragma once
#include "calculator.hpp"

class DisplayHendrick : public Display
{
public:
  void add(Digit digit);
  void setSignal(Signal);
  void addDecimalSeparator();
  void clear();
};
