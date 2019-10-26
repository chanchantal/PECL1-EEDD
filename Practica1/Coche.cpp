#include <iostream>
#include "cola.h"

using namespace std;

class n1{
    private: //Atributos
        string matricula[7];
        string marca [20];
        string modelo [20];
        string color [20];
    public:
        n1 (string,string,string,string);
};

class n2{
    private: //Atributos
        string matricula[7];
        string marca [20];
        string modelo [20];
        string color [20];
    public:
        n2 (string,string,string,string);
};

//Constructor
n1::n1(string _matricula,string _marca,string _modelo,string _color){
    matricula = _matricula;
    marca = _marca;
    modelo = _modelo;
    color = _color;
}

n2::n2(string _matricula,string _marca,string _modelo,string _color){
    matricula = _matricula;
    marca = _marca;
    modelo = _modelo;
    color = _color;
}




