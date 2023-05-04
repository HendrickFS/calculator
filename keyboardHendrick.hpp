#include "calculator.hpp"
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