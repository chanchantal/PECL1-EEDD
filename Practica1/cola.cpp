#include <iostream>
#include "Cola.h"
using namespace std;

Cola::~Cola()
{
    while(frente) desencolar();
}
string Cola::getEtiqueta(){
    return etiqueta;
}
void Cola::encolar(Coche v)
{
    cout << "Entra en la cola " << etiqueta << ",un coche de matricula: " << v.getMatricula() << endl;
    pNodo nuevo;
    nuevo = new Nodo(v);
    if(final) final -> siguiente = nuevo;
    final = nuevo;
    if(!frente) frente = nuevo;
    tamano++;
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

    tamano--;
    return v;
}
int Cola::getTamano(){
    return tamano;
}


