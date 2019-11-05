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

    if (outPut < 2){
        outPut = 2;
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
    int numeracion = random(1000,9999);
    while (numeracion < 1000){
        numeracion = random(1000,9999);
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

    cout << "Se ha generado la cola " << TaquillaA.getEtiqueta() << ",como Taquilla A" << endl;
    cout << "Se ha generado la cola " << TaquillaB.getEtiqueta() << ",como Taquilla B" << endl;
    cout << "Se ha generado la cola " << EmbarcaderoA.getEtiqueta() << ",como Embarcadero A" << endl;
    cout << "Se ha generado la cola " << EmbarcaderoB.getEtiqueta() << ",como Embarcadero B" << endl;

    string estado[4] = {"OrillaA", "NavegandoAB", "OrillaB","NavegandoBA"};
    int posicionBarco = random(0,3);
    Pila Barco(estado[posicionBarco]);

    int n3 = random(80,120)+80;
    int n4 = 10;
    int n5 = 7;
    int n6 = 14;
    cout << "\n**El valor de n3 es de: " << n3 << endl;
    cout << "**El valor de n4 es de: " << n4 << endl;
    cout << "**El valor de n5 es de: " << n5 << endl;
    cout << "**El valor de n6 es de: " << n6 << "\n" << endl;
    bool acabado = false;
    int contador = 0;
    int cochesGeneradosA,cochesGeneradosB,n1,n2,h,cuenta;
    bool descargarYa;

    while(acabado == false){
        contador++;
        cout << "\n### Quedan " << n3 << " vehiculos por generarse" << endl;
        cout << "### El barco se encuentra: " << Barco.getEstado() << " <------------------------------------" << endl;

        if (n3>0){
            if (n3 == 1){
                n1 = 1;
            } else {
                    n1 = random(2,8);
                while (n3-n1 < 0){
                    n1 = random(2,8);
                }
            }
            cout << "\n n1 coches en Orilla A: " << n1 << endl;
            n3 = n3-n1;
            cochesGeneradosA = cochesGeneradosA + n1;

            for (int i = 1; i< n1+1 ; i++){
                TaquillaA.encolar(generarVehiculo());
            }

            if (n3 > 0){
                if (n3 == 1){
                    n2 = 1;
                } else {
                        n2 = random(2,8);
                    while(n3-n2 < 0){
                        n2 = random(2,8);
                    }
                }
                cochesGeneradosB = cochesGeneradosB + n2;
                n3 = n3-n2;
                cout <<"\n n2 coches en orilla B : " << n2 << endl;
                for (int i = 1; i< n2+1 ; i++){
                    TaquillaB.encolar(generarVehiculo());
                }
            }
        }
        cout << "\n.....................EMBARCADEROS...................." << endl;
        while(EmbarcaderoA.getTamano() < n4 && TaquillaA.getTamano() > 0){
            EmbarcaderoA.encolar(TaquillaA.desencolar());
        }
        cout << "\n";
        while(EmbarcaderoB.getTamano() < n4 && TaquillaB.getTamano() > 0){
            EmbarcaderoB.encolar(TaquillaB.desencolar());
        }
        cout << "......................................................\n";
        if (Barco.getEstado() == estado[0] && Barco.getCarga() > 0 && descargarYa == true){
            descargarYa = false;
            while(Barco.getCarga() > 0){
                    cout << "Se ha desapilado: " << (Barco.desapilar()).getMatricula() << ",En " << estado[0] << endl;
            }
        }
        if (Barco.getEstado() == estado[2] && Barco.getCarga() > 0 && descargarYa == true){
            descargarYa = false;
            while(Barco.getCarga() > 0){
                    cout << "Se ha desapilado: " << (Barco.desapilar()).getMatricula() << ",En " << estado[2] << endl;
            }
        }
        cout << "\n";
        if (Barco.getEstado() == estado[0] && EmbarcaderoA.getTamano() > 0){
            h = EmbarcaderoA.getTamano();
            cuenta = 0;
            while (h > 0 && Barco.getCarga() < n6 && cuenta < n5){
                Barco.apilar(EmbarcaderoA.desencolar());
                h--;
                cuenta++;
            }
        } else if (Barco.getEstado() == estado[2] && EmbarcaderoB.getTamano() > 0){
            h = EmbarcaderoB.getTamano();
            cuenta = 0;
            while (h > 0 && Barco.getCarga() < n6 && cuenta < n5){
                Barco.apilar(EmbarcaderoB.desencolar());
                h--;
                cuenta ++;
            }
        }
        if (Barco.getCarga() == n6){
            posicionBarco++;
            descargarYa = true;
        } else if (Barco.getEstado() == estado[1] || Barco.getEstado() == estado[3]){
            posicionBarco++;
        } else if(EmbarcaderoA.getTamano()==0 && TaquillaA.getTamano()==0 && n3==0){
            posicionBarco++;
            descargarYa = true;
        } else if(EmbarcaderoB.getTamano()==0 && TaquillaB.getTamano()==0 && n3==0){
            posicionBarco++;
            descargarYa = true;
        }
        if (posicionBarco > 3){
            posicionBarco = 0;
        }

        Barco.setEstado(estado[posicionBarco]);

        cout << "\n** Hay " << Barco.getCarga() << " elementos en el barco" << endl;
        cout << "** El tamano de " << TaquillaA.getEtiqueta() << " es de: " << TaquillaA.getTamano() << " elementos" << endl;
        cout << "** El tamano de " << TaquillaB.getEtiqueta() << " es de: " << TaquillaB.getTamano() << " elementos" << endl;
        cout << "** El tamano de " << EmbarcaderoA.getEtiqueta() << " es de: " << EmbarcaderoA.getTamano() << " elementos" << endl;
        cout << "** El tamano de " << EmbarcaderoB.getEtiqueta() << " es de: " << EmbarcaderoB.getTamano() << " elementos" << endl;


        if (Barco.getCarga() == 0 && TaquillaA.getTamano() == 0 && TaquillaB.getTamano() == 0 && EmbarcaderoA.getTamano() == 0 && EmbarcaderoB.getTamano()==0){
            acabado = true;
            cout << "SE ACABO EL PROGRAMA" << endl;
        } else {
        cout << " \n======================================================" << endl;
        cout << " Pulse <Enter> para seguir el turno\n\n" << endl;
        cin.get();
        }
    }
return 0;
}
