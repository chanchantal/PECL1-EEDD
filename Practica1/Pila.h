#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

class Nodo
{
    private:
        int valor;
        Nodo *siguiente;
        friend class Pila;
    public:
        Nodo(int v, Nodo *sig = NULL)
        {
            valor = v;
            siguiente = sig;
        }
};
typedef Nodo *pNodo;

class Pila
{
    private:
        pNodo cima;
    public:
        Pila() : cima(NULL) {}
        ~Pila();
        void apilar(int v);
        int desapilar();
        void mostrarCima();
};

#endif // PILAS_H_INCLUDED

