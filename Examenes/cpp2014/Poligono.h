#ifndef CPP_POLIGONO_H
#define CPP_POLIGONO_H
#include "Figura.h"
#include "Punto.h"

class Poligono : public Figura {
protected:
    int numVertices;
    Punto** vertices;

public:
    Poligono(string nombre, int numVertices, Punto* vertices): Figura(nombre) {
        this->numVertices = numVertices;
        this->vertices = new Punto*[numVertices];

        for (int i = 0; i < numVertices; i++) {
            this->vertices[i] = new Punto(vertices[i].getX(), vertices[i].getY());
        }
    };

    ~Poligono();

    virtual float getPerimetro();
    virtual void imprimir();

};

#endif // CPP_POLIGONO_H
