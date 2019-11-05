#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <string>
#include <stddef.h>
#include "nodo.h"
#include "Coche.h"

using namespace std;

class Cola
{
    private:
        pNodo frente, final;
        string etiqueta;
        int tamano;
    public:
        Cola(string codigo): final(NULL), frente(NULL){
            etiqueta = codigo;
            tamano = 0;
        }
        ~Cola();
        void encolar(Coche v);
        Coche desencolar();
        void mostrarEtiqueta();
        int getTamano();
};


#endif
