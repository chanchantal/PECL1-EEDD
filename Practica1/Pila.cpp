#include <iostream>
#include "Pila.h"

using namespace std;

Coche Pila::desapilar()
{
    pNodo nodo;
    Coche v;
    if(!cima) return v;
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

void Pila::apilar(Coche v)
{
    pNodo nuevo;
    nuevo = new Nodo(v, cima);
    cima = nuevo;
}

void Pila::mostrarCima()
{
    //if (!cima) cout << "Cima: 0" << endl;
    //else cout << "Cima: " << cima -> valor << endl;
}

