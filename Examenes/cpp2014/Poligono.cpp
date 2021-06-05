#include "Poligono.h"

Poligono::~Poligono() {
    for (int i = 0; i < numVertices; i++) {
        delete vertices[i];
    }
    delete vertices;
}

// TODO
float Poligono::getPerimetro() {
    float perimetro = 0;

    // Recorremos todos los puntos
    int i;
    for (i = 0; i < numVertices - 1; i++) {
        perimetro += vertices[i]->distancia(*vertices[i+1]);
    }

    // el útlimo punto con el primero
    perimetro += vertices[i]->distancia(*vertices[0]);

    return perimetro;
}

void Poligono::imprimir() {
    Figura::imprimir();

    for (int i = 0; i < numVertices; i++) {
        cout << "Vertice " << i << " = ";
        vertices[i]->imprimir();
    }
}
