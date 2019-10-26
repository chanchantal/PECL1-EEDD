#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

class Nodo
{
    private:
        int valor;
        Nodo *siguiente;
        friend class Cola;
    public:
        Nodo(int v, Nodo *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef Nodo *pNodo;

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
