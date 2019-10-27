#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo
{
    private:
        int valor;
        Nodo *siguiente;
        friend class Cola;
        friend class Pila;
    public:
        Nodo(int v, Nodo *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef Nodo *pNodo;

#endif // NODO_H_INCLUDED
