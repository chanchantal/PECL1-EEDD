#include <iostream>
#include <stdlib.h>
#include "Cola.h"
#include "Taquilla.cpp"

using namespace std;

int main()
{
    Cola taquilla_A;

    taquilla_A.encolar(14));
    cout << "Se han añadido coches a la cola " << endl;
    taquilla_A.encolar(22);
    cout << "Se han añadido coches a la cola " << endl;
    cout << "Comprobacion: " << taquilla_A.desencolar() << endl;

    Cola taquilla_B;
    taquilla_B.encolar(33);
    cout << "Se han añadido coches a la cola " << endl;
    taquilla_B.encolar(42);
    cout << "Se han añadido coches a la cola " << endl;
    cout << "Comprobacion: " << taquilla_B.desencolar() << endl;


return 0;
}
