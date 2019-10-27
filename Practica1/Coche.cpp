#include <iostream>
using namespace std;

class Coche{
    private: //Atributos
        char matricula[7];
        char marca [20];
        char modelo [20];
        char  color [20];
    public:
        Coche (char,char,char,char);
};

//Constructor
Coche::Coche(char matricula,char marca,char modelo,char color){
    matricula = matricula;
    marca = marca;
    modelo = modelo;
    color = color;
}




