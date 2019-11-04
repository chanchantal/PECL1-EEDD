#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "nodo.h"
#include <string>

class Pila
{
    private:
        pNodo cima;
        string estadoBarco;
        int cargaBarco;
    public:
        Pila(string estado) : cima(NULL) {
            estadoBarco = estado;
        }
        ~Pila();
        void apilar(Coche v);
        Coche desapilar();
        void mostrarCima();
        string getEstado();
        int getCarga();
};

#endif // PILAS_H_INCLUDED

