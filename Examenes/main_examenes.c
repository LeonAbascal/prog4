#include "2017/persona.h"
#include "2020/producto.h"
#include "2020/carrito.h"
#include <string.h>

void examen_2017() {
    Persona personas[5];
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	imprimirPersona(personas[0]);
}

void examen_2014() {

}

void examen_2020() {
    Producto p1; p1.ref=1; strcpy(p1.nombre,"Platanos"); p1.precio=12.0;
	Producto p2; p2.ref=2; strcpy(p2.nombre,"Solomillo"); p2.precio=32.2;
	Producto p3; p3.ref=3; strcpy(p3.nombre,"Chocolate"); p3.precio=25.5;
	Producto p4; p4.ref=4; strcpy(p4.nombre,"Rodaballo"); p4.precio=35.4;
	Producto p5; p5.ref=5; strcpy(p5.nombre,"Cereales"); p5.precio=10.5;

	//imprimirProducto(p1);

	Producto* comprados[] = {&p1, &p2, &p3, &p4, &p5};

	Compra c;
	c.prod = &p2;

	imprimir_compra(&c); // prueba a mala hostia 1.3
	modificar_compra(&c, 3);

	imprimir_compra(&c); // prueba bien 1.3
}
