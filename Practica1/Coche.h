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
};

#endif // COCHE_H_INCLUDED
