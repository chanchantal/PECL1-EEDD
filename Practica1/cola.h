#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodo.h"

class Cola
{
    public:
        Cola() : final(NULL), frente(NULL) {}
        ~Cola();
        void encolar(int v);
        int desencolar();
    private:
        pNodo frente, final;
};


#endif
