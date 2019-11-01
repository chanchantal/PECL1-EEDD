#ifndef COCHE_H_INCLUDED
#define COCHE_H_INCLUDED

class Coche{
    private:
        char matricula;
        char marca;
        char modelo;
        char color;
        char estadoCoche;
    public:
        Coche(char,char,char,char,char);
        Coche();
};

#endif // COCHE_H_INCLUDED
