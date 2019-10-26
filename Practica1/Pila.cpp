#include <iostream>
#include "Pila.h"

using namespace std;

int Pila::desapilar()
{
    pNodo nodo;
    int v;
    if(!cima) return 0;
    nodo = cima;
    cima= nodo -> siguiente;
    v = nodo -> valor;
    delete nodo;
    return v;
}

Pila::~Pila()
{
    while(cima) desapilar();
}

void Pila::apilar(int v)
{
    pNodo nuevo;
    nuevo = new Nodo(v, cima);
    cima = nuevo;
}

void Pila::mostrarCima()
{
    if (!cima) cout << "Cima: 0" << endl;
    else cout << "Cima: " << cima -> valor << endl;
}

