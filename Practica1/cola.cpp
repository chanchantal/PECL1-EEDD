#include <iostream>
#include "Cola.h"
using namespace std;

Cola::~Cola()
{
    while(frente) desencolar();
}
void Cola::mostrarEtiqueta(){
    cout << etiqueta << endl;
}
void Cola::encolar(Coche v)
{
    pNodo nuevo;
    nuevo = new Nodo(v);
    if(final) final -> siguiente = nuevo;
    final = nuevo;
    if(!frente) frente = nuevo;
}

Coche Cola::desencolar()
{
    pNodo nodo;
    Coche v;
    nodo = frente;
    if(!nodo) return v;
    frente = nodo -> siguiente;
    v = nodo -> valor;
    delete nodo;
    if(!frente) final = NULL;
    return v;
}


