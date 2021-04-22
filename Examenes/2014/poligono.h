#ifndef POLIGONO_H
#define POLIGONO_H
#include "punto.h"

typedef struct {
    int numVertices;
    Punto** vertices;
} Poligono;

// parte 2
void imprimirPoligono(Poligono);
float perimetro(Poligono);
void liberar(Poligono*);

// Parte 3
void anadirVertice(Poligono*, Punto);
void copiarPoligono(Poligono* dest, Poligono src);

#endif // POLIGONO_H
