#include "calculator.hpp"
#include "stack.hpp"

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

class CpuHendrick : public Cpu
{
  Display *display;
  Stack *register01;
  Stack *register02;
  Stack *register03;
  Operator op;
  bool hasOperator = false;
  bool readyToClearMemory = false;

public:
  CpuHendrick();
  void receive(Digit);
  void receive(Operator);
  void receive(Control);
  void setDisplay(Display *);
};