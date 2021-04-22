#include "poligono.h"
#include <stdlib.h>
#include <stdio.h>

void imprimirPoligono(Poligono poli) {
    int i;
    for(i = 0; i < poli.numVertices; i++) {
        printf("Vertice %i: ", i + 1);
        imprimirPunto(*(poli.vertices[i]));
    }
}

float perimetro(Poligono poli) {
    float total = 0;
    int i;
    for(i = 0; i < poli.numVertices - 1; i++) {
        total+=distancia(*poli.vertices[i], *poli.vertices[i+1]);
    }

    // sumamos el lado del primero con el último
    total+= distancia(*poli.vertices[0], *poli.vertices[i]);

    return total;
}

void liberar(Poligono* poli) {
    int i;
    for(i = 0; i < poli->numVertices; i++) {
        free(poli->vertices[i]);
    }

    free(poli->vertices);
}

void copiarPoligono(Poligono* dest, Poligono src) {

    int size = src.numVertices;
    dest->numVertices = size;
    dest->vertices = malloc(size * sizeof(Punto*));

    // copiamos el array (deep copy)
    int i;
    for(i = 0; i < size; i++) {
        dest->vertices[i] = malloc(sizeof(Punto));
        dest->vertices[i]->x = src.vertices[i]->x;
        dest->vertices[i]->y = src.vertices[i]->y;

    }

}

void anadirVertice(Poligono* poli, Punto p) {

    poli->numVertices++;
    int size = poli->numVertices;

    // ampliamos el array dinámico
    poli->vertices = realloc(poli->vertices, size * sizeof(Punto*));

    // reservamos memoria para el nuevo punto
    *(poli->vertices + size - 1) = malloc(sizeof(Punto));

    // Copiamos el punto del argumento
    poli->vertices[size-1]->x = p.x;
    poli->vertices[size-1]->y = p.y;

}
