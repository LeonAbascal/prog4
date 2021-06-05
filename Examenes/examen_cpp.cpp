#include "examen_cpp.hpp"
#include <iostream>
#include <string.h>

// 2014
#include "cpp2014/Figura.h"
#include "cpp2014/Circulo.h"
#include "cpp2014/Poligono.h"
#include "cpp2014/Punto.h"

using namespace std;

void imprimirDetalleFigura(Figura &f) {
	// TAREA 4.2: Implementar esta función.
	f.imprimir();
	cout << "Perímetro: " << f.getPerimetro() << endl;
}

float sumarPerimetros(Figura* figuras[], int numFiguras) {
	// TAREA 4.3: Implementar esta función.

    float total = 0;

    for (int i = 0; i < numFiguras; i++) {
        total += figuras[i]->getPerimetro();
    }

    return total;
}

void cpp2014() {

    Circulo c1("Circulo1", Punto(1,2), 3);
	Circulo *c2 = new Circulo("Circulo2", Punto(2,1), 4);

	Punto vertices[] = {Punto(1,1), Punto(1,2), Punto(2,1)};
	Poligono *p1 = new Poligono("Triangulo", 3, vertices);


	// TAREA 4.1: Imprimir por pantalla el numero de figuras creadas
    cout << "Num total de figuras: " << Figura::getNumFiguras() << endl;

	// TAREA 4.2: Imprime el detalle de cada una de las figuras existentes
	imprimirDetalleFigura(c1);
	cout << "-----" << endl;
	imprimirDetalleFigura(*c2);
	cout << "-----" << endl;
    imprimirDetalleFigura(*p1);
    cout << "-----" << endl;

	// TAREA 4.3: Imprimir por pantalla la suma de los perimetros de las 3 figuras
	Figura* figuras[3];
	figuras[0] = &c1;
	figuras[1] = c2;
	figuras[2] = p1;
    cout << "Suma perimetros = " << sumarPerimetros(figuras, Figura::getNumFiguras());

    // liberamos memoria
    delete p1;
    delete c2;
}
