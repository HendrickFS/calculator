#include "cpuHendrick.hpp"
#include "calculatorErrorHendrick.hpp"
#include "displayHendrick.hpp"
#include "keyHendrick.hpp"
#include <cmath>

Stack ::Stack(int tam)
{
    this->tam = tam;
    vector = new char[tam];
    topo = -1;
}

void Stack ::push(char valor)
{
    topo++;
    vector[topo] = valor;
}

char Stack ::pop()
{
    char valor = vector[topo];
    topo--;
    return valor;
}

void Stack ::inverte()
{
    char *aux = new char[tam];
    int i = 0;
    int newTopo = topo;
    while (topo != -1)
    {
        aux[i] = pop();
        i++;
    }
    topo = newTopo;

    vector = aux;
}

int Stack ::getTopo() { return topo; }

int Stack ::getTam() { return tam; }

char *Stack ::getVet() { return vector; }

void Stack ::setTopo(int topo) { this->topo = topo; }

void Stack ::setTam(int tam) { this->tam = tam; }

void Stack ::setVet(char *vector) { this->vector = vector; }


CpuHendrick::CpuHendrick()
{
  register01 = new Stack(8);
  register02 = new Stack(8);
  register03 = new Stack(8);
  op;
  hasOperator = false;
  readyToClearMemory = false;
}

//
void CpuHendrick::receive(Digit digit)
{
  if (!hasOperator)
  {
    if (register01->getTopo() < 7)
    {
      if (register01->getVet()[0] == 0 && register01->getTopo() == 0 && digit != ZERO)
      {
        register01->pop();
        display->clear();
      }
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
      if (register02->getVet()[0] == 0 && register02->getTopo() == 0 && digit != ZERO)
      {
        register02->pop();
        display->clear();
      }
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
    this->op = SUM;
    this->display->clear();
  }
  else if (op == SUBTRACTION)
  {
    this->op = SUBTRACTION;
    this->display->clear();
  }
  else if (op == MULTIPLICATION)
  {
    this->op = MULTIPLICATION;
    this->display->clear();
  }
  else if (op == DIVISION)
  {
    this->op = DIVISION;
    this->display->clear();
  }
  else if (op == PERCENTAGE)
  {
    this->op = PERCENTAGE;
    this->display->clear();
  }
  else if (op == SQUARE_ROOT)
  {
    this->op = SQUARE_ROOT;
    this->display->clear();
    if (register02->getTopo() == -1)
    {
      float decimalNumber01;
      int qtdeDecimais = 0;

      int number01 = 0;
      int decimalDivision1 = 1;
      int topo1 = register01->getTopo();

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
      this->display->clear();

      float result = sqrt(decimalNumber01);
      if (qtdeDecimais == 0)
      {
        qtdeDecimais = 7;
      }
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01

      int parteInteira = (int)floor(result);
      int parteDecimal = (result * (float)pow(10, qtdeDecimais)) - ((float)parteInteira * (float)pow(10, qtdeDecimais));

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

      if (aux == 0)
        qtdDigitos++;

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
    }
  }
  this->hasOperator = true;
  this->register02->setTopo(-1);
}
void CpuHendrick::receive(Control control)
{
  if (control == DECIMAL_SEPARATOR)
  {
    if (!hasOperator)
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
    int qtdeDecimais2 = 0;
    int decimaisForMultiplication = 0;

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
        qtdeDecimais2 = topo2 - i;
        if (qtdeDecimais2 > qtdeDecimais)
        {
          qtdeDecimais = qtdeDecimais2;
        }
        decimalDivision2 = pow(10, topo2 - i); // identifica por quanto devemos dividir para o obter o valor decimal
      }
    }
    decimalNumber02 = ((float)number02 / (float)decimalDivision2); // valor ajustado para decimal

    decimaisForMultiplication = qtdeDecimais + qtdeDecimais2;

    this->display->clear();

    if (op == SUM)
    {
      float result = decimalNumber01 + decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01
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

      if (aux == 0)
        qtdDigitos++;

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
    else if (op == SUBTRACTION)
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
    else if (op == MULTIPLICATION)
    {
      float result = decimalNumber01 * decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01for (int i = 0; i < register01->getTopo(); i++)

      int parteInteira = (int)floor(result);
      int parteDecimal = (result * (float)pow(10, decimaisForMultiplication)) - ((float)parteInteira * (float)pow(10, decimaisForMultiplication));
      if (parteDecimal > 0)
      {
        for (int i = decimaisForMultiplication; i > 0; i--)
        {
          register01->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (decimaisForMultiplication > 0)
        {
          register01->push('.');
        }
      }

      int qtdDigitos = 0;

      int aux = parteInteira;

      if (aux == 0)
        qtdDigitos++;

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
    else if (op == DIVISION)
    {
      float result = decimalNumber01 / decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01

      int parteInteira = (int)floor(result);
      int parteDecimal = (result * (float)pow(10, decimaisForMultiplication)) - ((float)parteInteira * (float)pow(10, decimaisForMultiplication));

      if (parteDecimal > 0)
      {
        for (int i = decimaisForMultiplication; i > 0; i--)
        {
          register01->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (decimaisForMultiplication > 0)
        {
          register01->push('.');
        }
      }

      int qtdDigitos = 0;

      int aux = parteInteira;

      if (aux == 0)
        qtdDigitos++;

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
    else if (op == PERCENTAGE)
    {
      float result = decimalNumber01 + (decimalNumber01 * decimalNumber02 / 100);
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01

      int parteInteira = (int)floor(result);
      int parteDecimal = (result * (float)pow(10, decimaisForMultiplication)) - ((float)parteInteira * (float)pow(10, decimaisForMultiplication));

      if (parteDecimal > 0)
      {
        for (int i = decimaisForMultiplication; i > 0; i--)
        {
          register01->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (decimaisForMultiplication > 0)
        {
          register01->push('.');
        }
      }

      int qtdDigitos = 0;

      int aux = parteInteira;

      if (aux == 0)
        qtdDigitos++;

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
    else if (op == SQUARE_ROOT)
    {
      float result = decimalNumber01 + (sqrt(decimalNumber01));
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01

      int parteInteira = (int)floor(result);
      int parteDecimal = (result * (float)pow(10, decimaisForMultiplication)) - ((float)parteInteira * (float)pow(10, decimaisForMultiplication));

      if (parteDecimal > 0)
      {
        for (int i = decimaisForMultiplication; i > 0; i--)
        {
          register01->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (decimaisForMultiplication > 0)
        {
          register01->push('.');
        }
      }

      int qtdDigitos = 0;

      int aux = parteInteira;

      if (aux == 0)
        qtdDigitos++;

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
  }
  else if (control == ON_CLEAR_ERROR)
  {
    this->register01->setTopo(-1);
    this->register02->setTopo(-1);
    this->display->clear();
    this->hasOperator = false;
  }
  else if (control == MEMORY_SUM || control == MEMORY_SUBTRACTION)
  {

    float decimalNumber01;
    float decimalNumber02;
    int qtdeDecimais = 0;
    int qtdeDecimais2 = 0;
    int decimaisForMultiplication = 0;

    int number01 = 0;
    int number02 = 0;
    int decimalDivision1 = 1;
    int decimalDivision2 = 1;
    int topo1 = register01->getTopo();
    int topo2 = register03->getTopo();

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
      if (register03->getVet()[i] != '.')
      {
        number02 += register03->pop() * pow(10, j);
        j++;
      }
      else
      {
        register03->pop();
        qtdeDecimais2 = topo2 - i;
        if (qtdeDecimais2 > qtdeDecimais)
        {
          qtdeDecimais = qtdeDecimais2;
        }
        decimalDivision2 = pow(10, topo2 - i); // identifica por quanto devemos dividir para o obter o valor decimal
      }
    }
    decimalNumber02 = ((float)number02 / (float)decimalDivision2); // valor ajustado para decimal

    decimaisForMultiplication = qtdeDecimais + qtdeDecimais2;

    if (control == MEMORY_SUM)
    {
      float result = decimalNumber01 + decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01
      int parteInteira = (int)floor(result);
      int parteDecimal = ceil((result * (float)pow(10, qtdeDecimais)) - ((float)parteInteira * (float)pow(10, qtdeDecimais)));
      if (parteDecimal > 0)
      {
        for (int i = qtdeDecimais; i > 0; i--)
        {
          register03->push(parteDecimal % 10);
          parteDecimal /= 10;
        }

        if (qtdeDecimais > 0)
        {
          register03->push('.');
        }
      }
      int qtdDigitos = 0;

      int aux = parteInteira;

      if (aux == 0)
        qtdDigitos++;

      while (aux > 0)
      {
        aux /= 10;
        qtdDigitos++;
      }

      for (int i = 0; i < qtdDigitos; i++)
      {
        register03->push(parteInteira % 10);
        parteInteira /= 10;
      }
      register03->inverte();
      register01->setTopo(topo1);
      this->readyToClearMemory = false;
    }
    else if (control == MEMORY_SUBTRACTION)
    {

      float result = decimalNumber01 - decimalNumber02;
      // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01for (int i = 0; i < register03->getTopo(); i++)

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
        register03->push(parteDecimal % 10);
        parteDecimal /= 10;
      }

      if (qtdeDecimais > 0)
      {
        register03->push('.');
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
        register03->push(parteInteira % 10);
        parteInteira /= 10;
      }

      register03->inverte();
      register01->setTopo(topo1);
      this->readyToClearMemory = false;
    }
  }
  else if (control == MEMORY_READ_CLEAR)
  {
    display->clear();
    for (int i = 0; i <= register03->getTopo(); i++)
    {
      if (register03->getVet()[i] != '.')
      {
        if (register03->getVet()[i] < 0)
        {
          if (i == 0)
          {
            this->display->setSignal(NEGATIVE);
          }
          this->display->add((Digit)(register03->getVet()[i] * -1));
        }
        else
        {
          this->display->add((Digit)register03->getVet()[i]);
        }
      }
      else
      {
        this->display->addDecimalSeparator();
      }
    }
    if (readyToClearMemory)
    {
      register01->setTopo(-1);
      register03->setTopo(-1);
      this->display->clear();
      this->readyToClearMemory = false;
    }
    else
    {
      this->readyToClearMemory = true;
    }
  }
}

void CpuHendrick::setDisplay(Display *display) { this->display = display; }