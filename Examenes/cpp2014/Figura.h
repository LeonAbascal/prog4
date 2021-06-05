#ifndef FIGURA_H
#define FIGURA_H
#include <string>
#include <iostream>

using namespace std;

class Figura {
private:
    static int numFiguras;

protected:
    string nombre;

public:
    Figura(string nombreFigura);
    virtual ~Figura();

    string getName();
    static int getNumFiguras();
    virtual float getPerimetro() = 0;
    virtual void imprimir();

};

#endif // FIGURA_H
