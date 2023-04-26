#include "calculatorHendrick.hpp"
#include <iostream>

int main(){
    Display *display = new DisplayHendrick();
    try{
        display->add(ZERO);
        display->add(ONE);
        display->add(TWO);
        display->add(THREE);
        display->add(FOUR);
        display->add(FIVE);
        display->add(SIX);
        display->add(SEVEN);
        display->add(EIGHT);
        display->add(NINE);
    }catch(CalculatorErrorHendrick erro){
        std::cout << "Erro:" << erro.getMessage();
    }
    display->clear();
    return 0;
}   