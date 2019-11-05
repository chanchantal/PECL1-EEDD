#ifndef COCHE_H_INCLUDED
#define COCHE_H_INCLUDED
#include <string>

using namespace std;

class Coche{
    private:
        string matricula;
        string marca;
        string modelo;
        string color;
    public:
        Coche(string,string,string,string);
        Coche();
        string getMatricula();
        string getMarca();
        string getModelo();
        string getColor();
        void setMatricula(string strMatricula);
        void setMarca(string strMarca);
        void setModelo(string strModelo);
        void setColor(string strColor);
};

#endif // COCHE_H_INCLUDED
