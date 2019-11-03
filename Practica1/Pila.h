#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "nodo.h"

class Pila
{
    private:
        pNodo cima;
    public:
        Pila() : cima(NULL) {}
        ~Pila();
        void apilar(Coche v);
        Coche desapilar();
        void mostrarCima();
};

#endif // PILAS_H_INCLUDED

