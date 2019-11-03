#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Coche.h"

class Nodo
{
    private:
        Coche valor;
        Nodo *siguiente;
        friend class Cola;
        friend class Pila;
    public:
        Nodo(Coche v, Nodo *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef Nodo *pNodo;

#endif // NODO_H_INCLUDED
