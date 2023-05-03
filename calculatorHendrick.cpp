#include "calculatorHendrick.hpp"
#include <iostream>
#include <cmath>

void DisplayHendrick :: add(Digit digit){
    switch (digit){
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
    case ZERO:
        std::cout << "0";
        break;
    default:
        std::cout << "E!";
        throw CalculatorErrorHendrick("digito nao implementado");
        break;
    }
}
void DisplayHendrick :: clear(){ std::cout << "\n";}
void DisplayHendrick :: addDecimalSeparator(){ std::cout << ".";}


CalculatorErrorHendrick :: CalculatorErrorHendrick(char const* message){this->message = message;}
char const* CalculatorErrorHendrick :: getMessage(){ return message;}


KeyDigitHendrick :: KeyDigitHendrick(Digit digit){this->digit = digit;}
Digit KeyDigitHendrick :: getDigit(){ return digit;}


KeyOperatorHendrick :: KeyOperatorHendrick(Operator op){this->op = op;}
Operator KeyOperatorHendrick :: getOperator(){ return op;}


KeyControlHendrick :: KeyControlHendrick(Control control){this->control = control;}
Control KeyControlHendrick :: getControl(){ return control;}


KeyHendrick::KeyHendrick(char const* symbol){this->symbol = symbol;}
char const* KeyHendrick::getSymbol(){return symbol;}
void KeyHendrick :: setKeyboard(KeyboardHendrick* keyboard){this->keyboard = keyboard;}
void KeyHendrick :: press(){
    if(this->symbol == "1") this->keyboard->receive(ONE);
    else if(this->symbol == "2") this->keyboard->receive(TWO);
    else if(this->symbol == "3") this->keyboard->receive(THREE);
    else if(this->symbol == "4") this->keyboard->receive(FOUR);
    else if(this->symbol == "5") this->keyboard->receive(FIVE);
    else if(this->symbol == "6") this->keyboard->receive(SIX);
    else if(this->symbol == "7") this->keyboard->receive(SEVEN);
    else if(this->symbol == "8") this->keyboard->receive(EIGHT);
    else if(this->symbol == "9") this->keyboard->receive(NINE);
    else if(this->symbol == "0") this->keyboard->receive(ZERO);
    else if(this->symbol == ".") this->keyboard->receive(DECIMAL_SEPARATOR);
    else if(this->symbol == "+") this->keyboard->receive(SUM);
    else if(this->symbol == "-") this->keyboard->receive(SUBTRACTION);
    else if(this->symbol == "*") this->keyboard->receive(MULTIPLICATION);
    else if(this->symbol == "/") this->keyboard->receive(DIVISION);
    else if(this->symbol == "=") this->keyboard->receive(EQUAL);
    else if(this->symbol == "CE") this->keyboard->receive(CLEAR_ERROR);
    else throw CalculatorErrorHendrick("tecla nao implementada");
    // não coloquei todas as keys por enquanto
}

CalculatorHendrick :: CalculatorHendrick(){
    this->display = NULL;
    this->cpu = NULL;
    this->keyboard = NULL;
}
void CalculatorHendrick :: setDisplay(DisplayHendrick* display){this->display = display;}
void CalculatorHendrick :: setCpu(CpuHendrick* cpu){this->cpu = cpu;}
void CalculatorHendrick :: setKeyboard(KeyboardHendrick* keyboard){this->keyboard = keyboard;}
DisplayHendrick* CalculatorHendrick :: getDisplay(){return display;}
KeyboardHendrick* CalculatorHendrick :: getKeyboard(){return keyboard;}
CpuHendrick* CalculatorHendrick :: getCpu(){return cpu;}


KeyboardHendrick :: KeyboardHendrick(){
    for (int i = 0; i < 23; i++){
        keys[i] = NULL;
    }
}
void KeyboardHendrick :: setCalculator(CalculatorHendrick* calculator){
    this->calculator = calculator;
}

void KeyboardHendrick :: receive(Digit digit){
    this->calculator->cpu->receive(digit);
}

void KeyboardHendrick :: receive(Operator op){
    this->calculator->cpu->receive(op);
}

void KeyboardHendrick :: receive(Control control){
    this->calculator->cpu->receive(control);
}

KeyHendrick* KeyboardHendrick :: getKey(Digit digit){

}

KeyHendrick* KeyboardHendrick :: getKey(Operator op){

}

KeyHendrick* KeyboardHendrick :: getKey(Control control){

}

void KeyboardHendrick :: add(KeyHendrick* key){
    key->setKeyboard(this);
    for(int i = 0; i < 23; i++){
        if(keys[i] == NULL){
            keys[i] = key;
            break;
        }
    }
}


CpuHendrick :: CpuHendrick(){
    register01 = new Stack(8);
    register02 = new Stack(8);
    op = NULL;
}
void CpuHendrick :: setCalculator(CalculatorHendrick* calculator){this->calculator = calculator;}
void CpuHendrick :: receive(Digit digit){
    if(op == NULL){
        if(register01->getTopo() < 7){
            if(digit == ONE){
                register01->push(1);
                this->calculator->display->add(ONE);
            }
            else if(digit == TWO){
                register01->push(2);
                this->calculator->display->add(TWO);
            }
            else if(digit == THREE){
                register01->push(3);
                this->calculator->display->add(THREE);
            }
            else if(digit == FOUR){
                register01->push(4);
                this->calculator->display->add(FOUR);
            }
            else if(digit == FIVE){
                register01->push(5);
                this->calculator->display->add(FIVE);
            }
            else if(digit == SIX){
                register01->push(6);
                this->calculator->display->add(SIX);
            }
            else if(digit == SEVEN){
                register01->push(7);
                this->calculator->display->add(SEVEN);
            }
            else if(digit == EIGHT){
                register01->push(8);
                this->calculator->display->add(EIGHT);
            }
            else if(digit == NINE){
                register01->push(9);
                this->calculator->display->add(NINE);
            }
            else if(digit == ZERO){
                register01->push(0);
                this->calculator->display->add(ZERO);
            }
        } else{
            throw CalculatorErrorHendrick("registrador cheio");
        }
    }else{
        if(register02->getTopo() < 7){
            if(digit == ONE){
                register02->push(1);
                this->calculator->display->add(ONE);
            }
            else if(digit == TWO){
                register02->push(2);
                this->calculator->display->add(TWO);
            }
            else if(digit == THREE){
                register02->push(3);
                this->calculator->display->add(THREE);
            }
            else if(digit == FOUR){
                register02->push(4);
                this->calculator->display->add(FOUR);
            }
            else if(digit == FIVE){
                register02->push(5);
                this->calculator->display->add(FIVE);
            }
            else if(digit == SIX){
                register02->push(6);
                this->calculator->display->add(SIX);
            }
            else if(digit == SEVEN){
                register02->push(7);
                this->calculator->display->add(SEVEN);
            }
            else if(digit == EIGHT){
                register02->push(8);
                this->calculator->display->add(EIGHT);
            }
            else if(digit == NINE){
                register02->push(9);
                this->calculator->display->add(NINE);
            }
            else if(digit == ZERO){
                register02->push(0);
                this->calculator->display->add(ZERO);
            }
        } else{
            throw CalculatorErrorHendrick("registrador cheio");
        }
    }

}

void CpuHendrick :: receive(Operator op){
    if(op == SUM){
        *(this->op) = SUM;
        this->calculator->display->clear();
    }
    else if(op == SUBTRACTION){
        *(this->op) = SUBTRACTION;
        this->calculator->display->clear();
    }
    else if(op == MULTIPLICATION){
        *(this->op) = MULTIPLICATION;
        this->calculator->display->clear();
    }
    else if(op == DIVISION){
        *(this->op) = DIVISION;
        this->calculator->display->clear();
    }
}

void CpuHendrick :: receive(Control control){
    if(control == DECIMAL_SEPARATOR){
        if(op == NULL){
            if(register01->getTopo() < 6 && register01->getTopo() > 0){
                register01->push('.');
                this->calculator->display->addDecimalSeparator();
            }else throw CalculatorErrorHendrick("primeiro e ultimo digito não pode ser ponto");
        }else{
            if(register02->getTopo() < 6 && register02->getTopo() > 0){
                register02->push('.');
                this->calculator->display->addDecimalSeparator();
            }else throw CalculatorErrorHendrick("primeiro e ultimo digito não pode ser ponto");
        }
    }
    else if(control == EQUAL){
        int number01 = 0;
        int number02 = 0;
        char decimalDivision = 1;

        for(int i = 0; i < register01->getTopo(); i++){
            if(register01->getVet()[register01->getTopo()] != '.'){
                number01 += register01->pop() * pow(10, i);
            }else{
                register01->pop();
                decimalDivision = pow(10, i); // identifica por quanto devemos dividir para o obter o valor decimal
            }
        }
        float decimalNumber01 = number01 / decimalDivision; // valor ajustado para decimal

        for(int i = 0; i < register02->getTopo(); i++){
            if(register02->getVet()[register02->getTopo()] != '.'){
                number02 += register02->pop() * pow(10, i);
            }else{
                register02->pop();
                decimalDivision = pow(10, i); // identifica por quanto devemos dividir para o obter o valor decimal
            }
        }
        float decimalNumber02 = number02 / decimalDivision; // valor ajustado para decimal

        this->calculator->display->clear();

        if(*op == SUM){
            float result = decimalNumber01 + decimalNumber02;

           // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01

        }
        else if(*op == SUBTRACTION){
            float result = decimalNumber01 - decimalNumber02;
            // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01
        }
        else if(*op == MULTIPLICATION){
            float result = decimalNumber01 * decimalNumber02;
            // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01
        }
        else if(*op == DIVISION){
            float result = decimalNumber01 / decimalNumber02;
            // TRANSFORMAR O RESULTADO EM STACK, COLOCAR NO REGISTRADOR 01
        }

        for(int i = 0; i < register01->getTopo(); i++){
            if(register01->getVet()[register01->getTopo()] != '.'){
                this->calculator->display->addDecimalSeparator();
            }
            else if(register01->getVet()[register01->getTopo()] == 1){
                this->calculator->display->add(ONE);
            }
            else if(register01->getVet()[register01->getTopo()] == 2){
                this->calculator->display->add(TWO);
            }
            else if(register01->getVet()[register01->getTopo()] == 2){
            }
            else if(register01->getVet()[register01->getTopo()] == 3){
                this->calculator->display->add(THREE);
            }
            else if(register01->getVet()[register01->getTopo()] == 4){
                this->calculator->display->add(FOUR);
            }
            else if(register01->getVet()[register01->getTopo()] == 5){
                this->calculator->display->add(FIVE);
            }
            else if(register01->getVet()[register01->getTopo()] == 6){
                this->calculator->display->add(SIX);
            }
            else if(register01->getVet()[register01->getTopo()] == 7){
                this->calculator->display->add(SEVEN);
            }
            else if(register01->getVet()[register01->getTopo()] == 8){
                this->calculator->display->add(EIGHT);
            }
            else if(register01->getVet()[register01->getTopo()] == 9){
                this->calculator->display->add(NINE);
            }
            else if(register01->getVet()[register01->getTopo()] == 0){
                this->calculator->display->add(ZERO);
            }
        }
    }
}
