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
            cargaBarco = 0;
        }
        ~Pila();
        void apilar(Coche v);
        Coche desapilar();
        void mostrarCima();
        string getEstado();
        int getCarga();
        void setEstado(string estado);
};

#endif // PILAS_H_INCLUDED

