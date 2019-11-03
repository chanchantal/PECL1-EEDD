#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
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
string convertirAString(int numero){
    ostringstream str1;
    str1 << numero;
    string numeroString =  str1.str();
    return numeroString;
}
string generarMatricula(){
    string abecedario[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int numeracion = random(100,999);
    while (numeracion < 100){
        numeracion = random(100,999);
    }
    string numeracionString = convertirAString(numeracion);

    int y1 = random(0,23);
    int y2 = random(0,23);
    while (y1 == y2){
        y2 = random(0,23);
    }
    int y3 = random(0,23);

    string letra1 = abecedario[y1];
    string letra2 = abecedario[y2];
    string letra3 = abecedario[y3];
    string letrasMatricula = letra1 + letra2 + letra3;
    string matricula = numeracionString + letra1 + letra2 + letra3;

    return matricula;
}
Coche generarVehiculo(){
    string marcas[42] = {"Hyundai","Seat","Citröen","Volkswagen","Audi","Land Rover","Maserati","Mazda","Subaru","Renault","Ferrari","McLaren","Lamborghini","Mercedes-Benz","Dodge","BMW","Bugatti","Aston Martin","Alfa Romeo","Dacia","Fiat","Ford","Honda","Infiniti","Jaguar","Jeep","KIA","Lexus","Lotus","MINI","Mitsubisi","Nissan","Opel","Peugot","Porsche","Skoda","Smart","SsangYong","Suzuki","Tesla","Toyota","Volvo"};
    string colores[8] = {"Azul","Rojo","Naranja","Verde","Negro","Granate","Blanco","Amarillo"};
    string matricula = generarMatricula();
    int x = random(0,8);
    int y = random(0,42);
    string colorAleatorio = colores[x];
    string marcaAleatoria = marcas[y];
    int z = random(2000,2019);
    string modelo = convertirAString(z);


    Coche koche(matricula,marcaAleatoria,modelo,colorAleatorio);
    return koche;
}


int main()
{
    string aCode = "0001A";
    string bCode = "0001B";
    Cola TaquillaA(aCode);
    Cola TaquillaB(bCode);
    Pila Barco();

    string estado[4] = {"OrillaA", "OrillaB", "NavegandoAB", "NavegandoBA"};

    int n1 = random(2,6);
    int n3 = random(80,120)+80;
    int n2 = random(2,6);

    bool acabado = false;
    while(n1 == n2){
        n2 = random(2,6);
    }

    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;

    //Coche* Orilla1[n1];
    //Coche* Orilla2[n2];

    int contador = 0;
    while(acabado == false){
            contador++;
            for (int i = 0; i<= 2 ; i++){
                TaquillaA.encolar(generarVehiculo());
                cout << "se genera" << endl;
            }
            for (int i = 0; i<= n2 ; i++){
                TaquillaB.encolar(generarVehiculo());
            }

            cout << (TaquillaA.desencolar()).getMatricula() << endl;
            cout << (TaquillaA.desencolar()).getMatricula() << endl;
            acabado = true;
    }
return 0;
}
