#include "calculatorHendrick.hpp"

Stack :: Stack(int tam){
    this->tam = tam;
    vector = new char[tam];
    topo = -1;
}

void Stack :: push(int valor){
    topo++;
    vector[topo] = valor;
}

char Stack :: pop(){
    int valor = vector[topo];
    topo--;
    return valor;
}

int Stack :: getTopo(){return topo;}

int Stack :: getTam(){return tam;}

char* Stack :: getVet(){return vector;}

void Stack :: setTopo(int topo){this->topo = topo;}

void Stack :: setTam(int tam){this->tam = tam;}

void Stack :: setVet(char* vector){this->vector = vector;}
