#include "calculator.hpp"

class Stack{
    int topo;
    char* vector;
    int tam;
    public:
        Stack(int tam);
        void push(int valor);
        char pop();
        int getTopo();
        int getTam();
        char* getVet();
        void setTopo(int topo);
        void setTam(int tam);
        void setVet(char* vector);
};


class DisplayHendrick : public Display{
    public:
        void add(Digit digit);
        void addDecimalSeparator();
        void clear();
};


class CpuHendrick : public Cpu{
  Stack* register01;
  Stack* register02;
  Operator op;
  CalculatorHendrick* calculator; //para saber a calculadora que a cpu esta associada
  public:
    CpuHendrick();
    void setCalculator(CalculatorHendrick*); //para associar uma calculadora a cpu
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
};


class KeyboardHendrick : public Keyboard{
  KeyHendrick* keys[23];
  CalculatorHendrick* calculator; //para saber a calculadora que o teclado esta associado
  public:
    KeyboardHendrick();
    void setCalculator(CalculatorHendrick*); //para associar uma calculadora ao teclado
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    KeyHendrick* getKey(Digit);
    KeyHendrick* getKey(Operator);
    KeyHendrick* getKey(Control);
    void add(KeyHendrick*);
};


class KeyHendrick : public Key{
  char const* symbol;
  KeyboardHendrick* keyboard;
  public:
    KeyHendrick(char const* symbol);
    void press();
    char const* getSymbol();
    void setKeyboard(KeyboardHendrick*);
};


class KeyDigitHendrick: public KeyDigit{
  Digit digit;
  public:
    KeyDigitHendrick(Digit digit);
    Digit getDigit();
};


class KeyOperatorHendrick: public KeyOperator{
  Operator op;
  public:
    KeyOperatorHendrick(Operator op);
    Operator getOperator();
};


class KeyControlHendrick: public KeyControl{
  Control control;
  public:
    KeyControlHendrick(Control control);
    Control getControl();
};


class CalculatorHendrick : public Calculator{
    public:
        DisplayHendrick* display;
        CpuHendrick* cpu;
        KeyboardHendrick* keyboard;
        CalculatorHendrick();
        void setDisplay(DisplayHendrick*);
        DisplayHendrick* getDisplay();
        void setCpu(CpuHendrick*);
        CpuHendrick* getCpu();
        void setKeyboard(KeyboardHendrick*);
        KeyboardHendrick* getKeyboard();
};


class CalculatorErrorHendrick : public CalculatorError{
  char const* message;
  public:
    CalculatorErrorHendrick(char const* message);
    char const* getMessage();
};