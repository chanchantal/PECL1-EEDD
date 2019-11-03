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
    public:
        Cola(string codigo): final(NULL), frente(NULL){
            etiqueta = codigo;
        }
        ~Cola();
        void encolar(Coche v);
        Coche desencolar();
        void mostrarEtiqueta();
};


#endif
