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
    while (y2 == y3){
        y3 = random(0,23);
    }
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
    Cola TaquillaA("0001A");
    Cola TaquillaB("0001B");
    Cola EmbarcaderoA("0002A");
    Cola EmbarcaderoB("0002B");


    string estado[4] = {"OrillaA", "NavegandoAB", "OrillaB","NavegandoBA"};
    int estadoComienzo = random(0,3);
    Pila Barco(estado[estadoComienzo]);

    int n3 = 10; //random(80,120)+80;
    int n4 = 4;
    bool acabado = false;
    int contador = 0;
    int cochesGeneradosA,cochesGeneradosB,n1,n2,enter;

    while(acabado == false){
        contador++;
        cout << "Quedan " << n3 << " vehiculos por generarse" << endl;
        cout << "El barco se encuentra: " << Barco.getEstado() << endl;
        if (n3>0){
            if (n3 == 1){
                n1 = 1;
            } else {
                    n1 = random(2,6);
                while (n3-n1 < 0){
                    n1 = random(2,6);
                }
            }
            cout << "n1: " << n1 << endl;
            n3 = n3-n1;
            cochesGeneradosA = cochesGeneradosA + n1;

            for (int i = 1; i< n1+1 ; i++){
                TaquillaA.encolar(generarVehiculo());
            }

            if (n3 >0){
                if (n3 == 1){
                    n2 = 1;
                } else {
                        n2 = random(2,6);
                    while(n3-n2 < 0){
                        n2 = random(2,6);
                    }
                }
                cochesGeneradosB = cochesGeneradosB + n2;
                n3 = n3-n2;
                cout <<"n2 : " << n2 << endl;
                for (int i = 1; i< n2+1 ; i++){
                    TaquillaB.encolar(generarVehiculo());
                }
            }
        }

        while(EmbarcaderoA.getTamano() < n4 && TaquillaA.getTamano() > 0){
            EmbarcaderoA.encolar(TaquillaA.desencolar());
            cout << "Desencolo A y encolo a embarcadero" << endl;
        }
        while(EmbarcaderoB.getTamano()< n4 && TaquillaB.getTamano() > 0){
            EmbarcaderoB.encolar(TaquillaB.desencolar());
            cout << "Desencolo B y encolo a embarcadero" << endl;
        }


        cout << " \n========== REINICIO ================" << endl;
        cout << " Pulse <Enter> para seguir el turno\n\n" << endl;
        while(enter != '\n'){
                cin >> enter;
        }
    }
return 0;
}
