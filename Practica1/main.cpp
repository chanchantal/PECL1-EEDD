#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "cola.h"
#include "Pila.h"
#include "Coche.h"

using namespace std;

int random(int desde, int hasta)
{
    int outPut;

    srand(time(NULL));

    for (int i = 1; i < 5; i++) {
    outPut = rand()%((hasta - desde) + 1);
    if (outPut == 0){
        outPut++;
    }
    }
    return outPut;
}

int main()
{

    bool acabado = false;
    string aCode = "0001A";
    string bCode = "0001B";

    typedef enum estado{OrillaA, OrillaB, NavegandoAB, NavegandoBA};
    estado estadoBarco = OrillaB;

    string estado1 = "OrillaA";
    string estado2 = "OrillaB";
    string estado3 = "NavegandoAB";
    string estado4 = "NavegandoBA";

    int n1 = random(2,6);

    int n3 = random(80,120)+80;
    int n2 = random(2,6)+1;

    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;

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
