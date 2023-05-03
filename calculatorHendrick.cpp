#include "calculatorHendrick.hpp"
#include <iostream>
#include <cmath>

CalculatorErrorHendrick::CalculatorErrorHendrick(char const *message)
{
  this->message = message;
}
char const *CalculatorErrorHendrick::getMessage() { return this->message; }

void DisplayHendrick::add(Digit digit)
{
  switch (digit)
  {
  case ZERO:
    std::cout << "0";
    break;
  case ONE:
    std::cout << "1";
    break;
  case TWO:
    std::cout << "2";
    break;
  case THREE:
    std::cout << "3";
    break;
  case FOUR:
    std::cout << "4";
    break;
  case FIVE:
    std::cout << "5";
    break;
  case SIX:
    std::cout << "6";
    break;
  case SEVEN:
    std::cout << "7";
    break;
  case EIGHT:
    std::cout << "8";
    break;
  case NINE:
    std::cout << "9";
    break;
  default:
    std::cout << "E";
    throw new CalculatorErrorHendrick("Digit not implemented!!!");
  }
}

//
void DisplayHendrick::setSignal(Signal signal) { std::cout << (signal == NEGATIVE ? "-" : ""); }

void DisplayHendrick::addDecimalSeparator() { std::cout << "."; }

void DisplayHendrick::clear() { std::cout << "\n"; }
//

CpuHendrick ::CpuHendrick()
{
  register01 = new Stack(8);
  register02 = new Stack(8);
  op = NULL;
}

//
void CpuHendrick::receive(Digit digit)
{
  if (op)
  {
    if (register01->getTopo() < 7)
    {
      if (digit == ONE)
      {
        register01->push(1);
        this->display->add(ONE);
      }
      else if (digit == TWO)
      {
        register01->push(2);
        this->display->add(TWO);
      }
      else if (digit == THREE)
      {
        register01->push(3);
        this->display->add(THREE);
      }
      else if (digit == FOUR)
      {
        register01->push(4);
        this->display->add(FOUR);
      }
      else if (digit == FIVE)
      {
        register01->push(5);
        this->display->add(FIVE);
      }
      else if (digit == SIX)
      {
        register01->push(6);
        this->display->add(SIX);
      }
      else if (digit == SEVEN)
      {
        register01->push(7);
        this->display->add(SEVEN);
      }
      else if (digit == EIGHT)
      {
        register01->push(8);
        this->display->add(EIGHT);
      }
      else if (digit == NINE)
      {
        register01->push(9);
        this->display->add(NINE);
      }
      else if (digit == ZERO)
      {
        register01->push(0);
        this->display->add(ZERO);
      }
    }
    else
    {
      throw CalculatorErrorHendrick("registrador cheio");
    }
  }
  else
  {
    if (register02->getTopo() < 7)
    {
      if (digit == ONE)
      {
        register02->push(1);
        this->display->add(ONE);
      }
      else if (digit == TWO)
      {
        register02->push(2);
        this->display->add(TWO);
      }
      else if (digit == THREE)
      {
        register02->push(3);
        this->display->add(THREE);
      }
      else if (digit == FOUR)
      {
        register02->push(4);
        this->display->add(FOUR);
      }
      else if (digit == FIVE)
      {
        register02->push(5);
        this->display->add(FIVE);
      }
      else if (digit == SIX)
      {
        register02->push(6);
        this->display->add(SIX);
      }
      else if (digit == SEVEN)
      {
        register02->push(7);
        this->display->add(SEVEN);
      }
      else if (digit == EIGHT)
      {
        register02->push(8);
        this->display->add(EIGHT);
      }
      else if (digit == NINE)
      {
        register02->push(9);
        this->display->add(NINE);
      }
      else if (digit == ZERO)
      {
        register02->push(0);
        this->display->add(ZERO);
      }
    }
    else
    {
      throw CalculatorErrorHendrick("registrador cheio");
    }
  }
}

void CpuHendrick::receive(Operator op)
{
  if (op == SUM)
  {
    *(this->op) = SUM;
    this->display->clear();
  }
  else if (op == SUBTRACTION)
  {
    *(this->op) = SUBTRACTION;
    this->display->clear();
  }
  else if (op == MULTIPLICATION)
  {
    *(this->op) = MULTIPLICATION;
    this->display->clear();
  }
  else if (op == DIVISION)
  {
    *(this->op) = DIVISION;
    this->display->clear();
  }
}
void CpuHendrick::receive(Control control)
{
  if (control == DECIMAL_SEPARATOR)
  {
    if (op == NULL)
    {
      if (register01->getTopo() < 7)
      {
        if (register01->getTopo() == -1)
        {
          register01->push(0);
          this->display->add(ZERO);
        }
        register01->push('.');
        this->display->addDecimalSeparator();
      }
      else
        throw CalculatorErrorHendrick("primeiro e ultimo digito não pode ser ponto");
    }
    else
    {
      if (register02->getTopo() < 7)
      {
        if (register02->getTopo() == -1)
        {
          register02->push(0);
          this->display->add(ZERO);
        }
        register02->push('.');
        this->display->addDecimalSeparator();
      }
      else
        throw CalculatorErrorHendrick("primeiro e ultimo digito não pode ser ponto");
    }
  }
  else if (control == EQUAL)

  {
    float decimalNumber01;
    float decimalNumber02;
    int qtdeDecimais = 0;

    int number01 = 0;
    int number02 = 0;
    int decimalDivision1 = 1;
    int decimalDivision2 = 1;
    int topo1 = register01->getTopo();
    int topo2 = register02->getTopo();

    for (int i = topo1, j = 0; i >= 0; i--)
    {
      if (register01->getVet()[i] != '.')
      {
        number01 += register01->pop() * pow(10, j);
        j++;
      }
      else
      {
        register01->pop();
        qtdeDecimais = topo1 - i;
        decimalDivision1 = pow(10, topo1 - i); // identifica por quanto devemos dividir para o obter o valor decimal
      }
    }
    decimalNumber01 = ((float)number01 / (float)decimalDivision1); // valor ajustado para decimal

    for (int i = topo2, j = 0; i >= 0; i--)
    {
      if (register02->getVet()[i] != '.')
      {
        number02 += register02->pop() * pow(10, j);
        j++;
      }
      else
      {
        register02->pop();
        int qtdeDecimais2 = topo2 - i;
        if (qtdeDecimais2 > qtdeDecimais)
        {
          qtdeDecimais = qtdeDecimais2;
        }
        decimalDivision2 = pow(10, topo2 - i); // identifica por quanto devemos dividir para o obter o valor decimal
      }
    }
    decimalNumber02 = ((float)number02 / (float)decimalDivision2); // valor ajustado para decimal

    this->display->clear();

    if (*op == SUM)
    {
      float result = decimalNumber01 + decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01
      int aux = result;

      int parteInteira = (int)floor(result);
      int parteDecimal = ceil((result * (float)pow(10, qtdeDecimais)) - ((float)parteInteira * (float)pow(10, qtdeDecimais)));
      if (parteDecimal > 0)
      {
        for (int i = qtdeDecimais; i > 0; i--)
        {
          register01->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (qtdeDecimais > 0)
        {
          register01->push('.');
        }
      }
      int qtdDigitos = 0;

      int aux2 = parteInteira;

      while (aux2 > 0)
      {
        aux2 /= 10;
        qtdDigitos++;
      }

      for (int i = 0; i < qtdDigitos; i++)
      {
        register01->push(parteInteira % 10);
        parteInteira /= 10;
      }
      register01->inverte();
      for (int i = 0; i <= register01->getTopo(); i++)
      {
        if (register01->getVet()[i] != '.')
        {
          this->display->add((Digit)register01->getVet()[i]);
        }
        else
        {
          this->display->addDecimalSeparator();
        }
      }

      register02->setTopo(topo2);
    }
    else if (*op == SUBTRACTION)
    {

      float result = decimalNumber01 - decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01for (int i = 0; i < register01->getTopo(); i++)

      int parteInteira, parteDecimal;

      if (result > 0)
      {
        parteInteira = (int)floor(result);
        parteDecimal = ceil((result * (float)pow(10, qtdeDecimais)) - ((float)parteInteira * (float)pow(10, qtdeDecimais)));
      }
      else
      {
        parteInteira = (int)ceil(result);
        parteDecimal = floor((result * (float)pow(10, qtdeDecimais)) - ((float)parteInteira * (float)pow(10, qtdeDecimais)));
      }

      for (int i = qtdeDecimais; i > 0; i--)
      {
        register01->push(parteDecimal % 10);
        parteDecimal /= 10;
      }

      if (qtdeDecimais > 0)
      {
        register01->push('.');
      }

      int qtdDigitos = 0;

      int aux = parteInteira;

      while (aux != 0)
      {
        aux /= 10;
        qtdDigitos++;
      }

      for (int i = 0; i < qtdDigitos; i++)
      {
        register01->push(parteInteira % 10);
        parteInteira /= 10;
      }

      register01->inverte();

      for (int i = 0; i <= register01->getTopo(); i++)
      {
        if (register01->getVet()[i] != '.')
        {
          if (register01->getVet()[i] < 0)
          {
            if (i == 0)
            {
              this->display->setSignal(NEGATIVE);
            }
            this->display->add((Digit)(register01->getVet()[i] * -1));
          }
          else
          {
            this->display->add((Digit)register01->getVet()[i]);
          }
        }
        else
        {
          this->display->addDecimalSeparator();
        }
      }

      register02->setTopo(topo2);
    }
    else if (*op == MULTIPLICATION)
    {
      float result = decimalNumber01 * decimalNumber02;
      std::cout << "teste" << result;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01for (int i = 0; i < register01->getTopo(); i++)

      int parteInteira = (int)floor(result);
      int parteDecimal = ceil((result * (float)pow(10, qtdeDecimais)) - ((float)parteInteira * (float)pow(10, qtdeDecimais)));

      if (parteDecimal > 0)
      {
        for (int i = qtdeDecimais; i > 0; i--)
        {
          register01->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (qtdeDecimais > 0)
        {
          register01->push('.');
        }
      }

      int qtdDigitos = 0;

      int aux = parteInteira;

      while (aux > 0)
      {
        aux /= 10;
        qtdDigitos++;
      }

      for (int i = 0; i < qtdDigitos; i++)
      {
        register01->push(parteInteira % 10);
        parteInteira /= 10;
      }

      register01->inverte();

      for (int i = 0; i <= register01->getTopo(); i++)
      {
        if (register01->getVet()[i] != '.')
        {
          this->display->add((Digit)register01->getVet()[i]);
        }
        else
        {
          this->display->addDecimalSeparator();
        }
      }

      register02->setTopo(topo2);
    }
    else if (*op == DIVISION)
    {
      float result = decimalNumber01 / decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01for (int i = 0; i < register01->getTopo(); i++)
    }
  }
  else if (control == ON_CLEAR_ERROR)
  {
    this->register01->setTopo(-1);
    this->register02->setTopo(-1);
  }
}

void CpuHendrick::setDisplay(Display *display) { this->display = display; }
//

//
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

//
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

void CalculatorHendrick::setDisplay(Display *display) { this->display = display; }
Display *CalculatorHendrick::getDisplay() { return this->display; }
void CalculatorHendrick::setCpu(Cpu *cpu) { this->cpu = cpu; }
Cpu *CalculatorHendrick::getCpu() { return this->cpu; }
void CalculatorHendrick::setKeyboard(Keyboard *keyboard) { this->keyboard = keyboard; }
Keyboard *CalculatorHendrick::getKeyboard() { return this->keyboard; }