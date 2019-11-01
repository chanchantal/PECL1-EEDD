#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "cola.h"
#include "Pila.h"
#include "Coche.h"

using namespace std;

int main()
{
    bool acabado = false;
    string aCode = "0001A";
    string bCode = "0001B";

    int x = rand();
    int y = rand();
    int z = rand();
    int n1 = x%4+2;
    int n2 = y%4+2;
    Coche* Orilla1[n1];
    Coche* Orilla2[n2];

    while(acabado == false){

        //Print estado barco
        acabado = true;
    }

    Cola TaquillaA(aCode);
    Cola TaquillaB(bCode);
    TaquillaA.mostrarEtiqueta();
    TaquillaB.mostrarEtiqueta();
return 0;
}
