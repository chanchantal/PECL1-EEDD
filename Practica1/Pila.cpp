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
    cargaBarco--;
    return v;
}
int Pila::getCarga(){
    return cargaBarco;
}

Pila::~Pila()
{
    while(cima) desapilar();
}

string Pila::getEstado(){
    return estadoBarco;
}

void Pila::setEstado(string estado){
    estadoBarco = estado;
}

void Pila::apilar(Coche v)
{
    pNodo nuevo;
    nuevo = new Nodo(v, cima);
    cima = nuevo;
    cout << "Se ha apilado: " << v.getMatricula() << endl;
    cargaBarco++;
}

void Pila::mostrarCima()
{
    //if (!cima) cout << "Cima: 0" << endl;
    //else cout << "Cima: " << cima -> valor << endl;
}

