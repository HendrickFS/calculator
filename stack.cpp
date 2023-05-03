#include "calculatorPaulo.hpp"

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
