#include "Figura.h"

int Figura::numFiguras = 0;

Figura::Figura(string nombreFigura) {
    nombre = nombreFigura;
    numFiguras++;
}

Figura::~Figura() {
    numFiguras--;
}

void Figura::imprimir() {
    cout << nombre << endl;
}

int Figura::getNumFiguras() {
    return numFiguras;
}
