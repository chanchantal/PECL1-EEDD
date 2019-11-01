#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <string>
#include "nodo.h"

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
        void encolar(int v);
        int desencolar();
        void mostrarEtiqueta();
};


#endif
