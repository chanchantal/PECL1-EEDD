#include <iostream>
#include "Coche.h"
#include <string>

using namespace std;

Coche::Coche(string matricula,string marca,string modelo,string color){
    this -> matricula = matricula;
    this -> marca = marca;
    this -> modelo = modelo;
    this -> color = color;
}
Coche::Coche(){
}

string Coche::getMatricula(){
    return matricula;
}

string Coche::getMarca(){
    return marca;
}

string Coche::getModelo(){
    return modelo;
}

string Coche::getColor(){
    return color;
}

void Coche::setMatricula(string strMatricula){
    matricula=strMatricula;
}

void Coche::setMarca(string strMarca){
    marca=strMarca;
}

void Coche::setModelo(string strModelo){
    modelo=strModelo;
}

void Coche::setColor(string strColor){
    color=strColor;
}
