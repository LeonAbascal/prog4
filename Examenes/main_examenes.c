#include "2017/persona.h"
#include "2020/producto.h"
#include "2020/carrito.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "2014/punto.h"

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
    Punto p1 = {1,2};
	imprimirPunto(p1);
}

// EXAMEN 2020
void leer_productos(Producto* productos[], char* fichero) {
    FILE* file = fopen(fichero, "r");

    if (file == NULL) {
        printf("Archivo no encontrado.\n");
    } else {
        // asumimos que siempre hay 5 productos
        int i;
        int j;
        for (i = 0; i < 5; i++) {
            j = 0;
            Producto* p = malloc(sizeof(Producto));

            // referencia
            p->ref = fgetc(file) - 48;

            // nombre
            for (j = 0; j < 14; j++) {
                p->nombre[j] = fgetc(file);
            }

            // precio
            char precio[4];
            for (j = 0; j < 4; j++) {
                precio[j] = fgetc(file);
                p->precio = atof(precio);
            }

            productos[i] = p;
        }
    }
}

void examen_2020() {
    Producto p1; p1.ref=1; strcpy(p1.nombre,"Platanos"); p1.precio=12.0;
	Producto p2; p2.ref=2; strcpy(p2.nombre,"Solomillo"); p2.precio=32.2;
	Producto p3; p3.ref=3; strcpy(p3.nombre,"Chocolate"); p3.precio=25.5;
	Producto p4; p4.ref=4; strcpy(p4.nombre,"Rodaballo"); p4.precio=35.4;
	Producto p5; p5.ref=5; strcpy(p5.nombre,"Cereales"); p5.precio=10.5;

	Producto* comprados[] = {&p1, &p2, &p3, &p4, &p5};

	//imprimirProducto(p1);


    // EJERCICIO 1
    /*


	Compra c;
	c.prod = &p2;

	imprimir_compra(&c); // prueba a mala hostia 1.3
	modificar_compra(&c, 3);

	imprimir_compra(&c); // prueba bien 1.3
	*/

    // EJERCICIO 2
	Carrito carrito;
	int cantidades[] = {1, 3, 5, 7, 9};
	Producto productos[] = {p1, p2, p3, p4, p5};
	crear_carrito(&carrito, productos, cantidades, 5);
	imprimir_ticket(carrito);


	// EJERCICIO 3
    modificar_carrito(&carrito, 3, 0);

    printf("\n\n");
    imprimir_ticket(carrito);

    devolver_carrito(&carrito);
    Producto** produs[5];
    leer_productos(&produs, "Examenes/2020/productos.txt");

    // liberamos memoria
    int i;
    for (i = 0; i < 5; i++) {
        //imprimirProducto(produs[i]);
        free(&produs[i]);
    }
}
