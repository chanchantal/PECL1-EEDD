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
void Cola::encolar(int v)
{
    pNodo nuevo;
    nuevo = new Nodo(v);
    if(final) final -> siguiente = nuevo;
    final = nuevo;
    if(!frente) frente = nuevo;
}

int Cola::desencolar()
{
    pNodo nodo;
    int v;
    nodo = frente;
    if(!nodo) return 0;
    frente = nodo -> siguiente;
    v = nodo->valor;
    delete nodo;
    if(!frente) final = NULL;
    return v;
}


