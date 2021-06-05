#include "Circulo.h"

Circulo::~Circulo() {
    delete centro;
}

float Circulo::getPerimetro() {
    return 2 * 3.1416 * radio;
}

void Circulo::imprimir() {
    Figura::imprimir();
    cout << "Centro: "; centro->imprimir();
    cout << "Radio: " << radio << endl;
}
