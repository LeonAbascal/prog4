#ifndef CIRCULO_H
#define CIRCULO_H
#include "Punto.h"
#include "Figura.h"

class Circulo: public Figura {

protected:
    float radio;
    Punto* centro;

public:
    Circulo(string nombre, Punto central, float radio): Figura(nombre){
        this->radio = radio;
        this->centro = new Punto(central.getX(), central.getY());
    };
    ~Circulo();

    virtual float getPerimetro();
    virtual void imprimir();
};

#endif // CIRCULO_H
