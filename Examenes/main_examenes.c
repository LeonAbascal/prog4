#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "2014/punto.h"
#include "2014/poligono.h"

#include "2017/persona.h"
#include "2017/censo.h"

#include "2020/carrito.h"
#include "2020/producto.h"

// examen 2017
void crearInforme(GrupoPersonas gp, char* fichero) {

    FILE* file = fopen(fichero, "w");

    if (file != NULL){
        fprintf(file, "CENSO DE JOVENES\n----------------\n");
        int i, edad;
        char* nombre;
        for(i = 0; i < gp.numPersonas; i++) {
            nombre = gp.personas[i]->nombre;
            edad = gp.personas[i]->edad;
            fprintf(file, "[Nombre: %s, Edad: %i]\n", nombre, edad);
        }

        fprintf(file, "Media: %.2f", gp.mediaEdad);
    }

    fclose(file);

}

void examen_2017(int arg1) {
    Persona personas[5];
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	//imprimirPersona(personas[0]);

    printf("Personas menores de %i: %i\n", arg1, cuantasPersonas(personas, 5, arg1));

    GrupoPersonas gp = recuperarJovenes(personas, 5);
    printf("\n\nGrupo de personas menores de 30: \n");
    int i;
    for(i = 0; i < 3; i++){
        Persona* p = gp.personas[i];
        imprimirPersona(*p);
    }
    printf("Media: %.2f\n", gp.mediaEdad);


    printf("\n\nLa persona mas joven es: \n");
    imprimirPersona(*recuperarYogurin(personas, 5));


    crearInforme(gp, "informe.txt");
    free(gp.personas);

    getchar();

    // parte 3
    system("cls");
    printf("PARTE 3 ------------\n");
    char letra = 'A';
    int numNombres = cuantosNombres(personas, 5, letra);
    printf("\nNum de nombres con la inicial %c: %i\n", letra, numNombres);

    char** nombres = listadoNombres(personas, 5, letra);
    for (i = 0; i < numNombres; i++) {
        printf("%s\n", nombres[i]);
    }

    free(nombres);
}

// EXAMEN 2014
void examen_2014(int x, int y) {
    // PARTE 1
    printf("Parte 1\n\n");
    Punto p1 = {1, 2};
    Punto p2 = {3, 4};
	imprimirPunto(p1);
	imprimirPunto(p2);
	trasladarXY(&p1, &p2, x, y); // ARGS DE PROGRAMA
	imprimirPunto(p1);
	imprimirPunto(p2);
    printf("\nPulsa intro para continuar... ");
    getchar();

    // PARTE 2
    system("cls");
    printf("Parte 2\n\n");
    Poligono poli;

    printf("Cuantos vertices: ");
    scanf("%i", &poli.numVertices);


    poli.vertices = malloc(poli.numVertices * sizeof(Punto*));
    int i;
    for(i = 0; i < poli.numVertices; i++) {
        *(poli.vertices + i) = malloc(sizeof(Punto));

        printf("[v%i] posicion X : ", i + 1);
        scanf("%i", &poli.vertices[i]->x);
        printf("[v%i] posicion Y : ", i + 1);
        scanf("%i", &poli.vertices[i]->y);
        putchar('\n');

    }

    system("cls");
    printf("Parte 2: poligono\n\n");
    imprimirPoligono(poli);
    printf("Perimetro: %.2f\n", perimetro(poli));

    printf("Pulsa intro para continuar... ");
    getchar();

    // PARTE 3
    system("cls");

    printf("Poligono original:\n");
    imprimirPoligono(poli);

    Poligono poli2;
    copiarPoligono(&poli2, poli);
    printf("\n\nPoligono copiado y ampliado:\n");
    anadirVertice(&poli2, p1);
    imprimirPoligono(poli2);

    // liberar
    liberar(&poli);
    liberar(&poli2);

}


// EXAMEN 2020

void leerProductos(Producto* productos[], char* fichero) {
    int i;

    FILE* file = fopen(fichero, "r");
    Producto* p;

    if (file != NULL) {
        for(i = 0; i < 5; i++) {
            p = productos[i];

            p->ref = fgetc(file) - 48;
            fgets(p->nombre, 15, file);
            char precio[6];
            fgets(precio, 6, file);
            p->precio = atof(precio);
            fgetc(file); // \n
        }

    } else {
        printf("No se ha encontrado el fichero.\n");
    }
}

void examen_2020() {
    int i;

    Producto p1; p1.ref=1; strcpy(p1.nombre,"Platanos"); p1.precio=12.0;
	Producto p2; p2.ref=2; strcpy(p2.nombre,"Solomillo"); p2.precio=32.2;
	Producto p3; p3.ref=3; strcpy(p3.nombre,"Chocolate"); p3.precio=25.5;
	Producto p4; p4.ref=4; strcpy(p4.nombre,"Rodaballo"); p4.precio=35.4;
	Producto p5; p5.ref=5; strcpy(p5.nombre,"Cereales"); p5.precio=10.5;

	Producto* comprados[] = {&p1, &p2, &p3, &p4, &p5};

	//imprimirProducto(p1);

    // parte 1
    system("cls");
    printf("PARTE 1\n");

    Compra c;
    c.p = &p2;
    c.unidades = 0;
    printf("Compra antes:\n");
    imprimirCompra(c);

    printf("\nCompra despues:\n");
    modificarCompra(&c, 3);
    imprimirCompra(c);

    getchar();

    // parte 2
    system("cls");
    printf("PARTE 2\n");

    Carrito carrito;
    Producto productos[] = {p1, p2, p3, p4, p5};
    int cants[] = {1, 3, 5, 7, 9};

    crearCarrito(&carrito, productos, cants, 5);
    imprimirTicket(carrito);

    getchar();

    // parte 3
    system("cls");
    printf("PARTE 3\n\n");

    modificarCarrito(&carrito, 3, 0);
    imprimirTicket(carrito);
    putchar(0xA);

    printf("\nViejo:\n");
    for(i = 0; i < 5; i++) {
        imprimirProducto(*comprados[i]);
        putchar(0xA);
    }
    leerProductos(&comprados, "Examenes/2020/productos.txt");

    printf("\nNuevo:\n");
    for(i = 0; i < 5; i++) {
        imprimirProducto(*comprados[i]);
        putchar(0xA);
    }

    // liberar memoria
    devolverCarrito(&carrito);
}
