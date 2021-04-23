#include "carrito.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void modificarCompra(Compra* c, int cantidad) {
    c->unidades = cantidad;
}

void imprimirCompra(Compra c) {
    imprimirProducto(*c.p);
    printf(" x %i kg/ud\n", c.unidades);
}

void crearCarrito(Carrito* c, Producto* prods, int* cants, int tamanyo) {
    float importeTotal = 0;

    c->compras = malloc(tamanyo * sizeof(Compra*));
    Compra* compra;
    int i;
    for(i = 0; i < tamanyo; i++) {
        compra = malloc(sizeof(Compra));
        compra->p = prods + i;
        compra->unidades = cants[i];

        c->compras[i] = compra;

        importeTotal += prods[i].precio * cants[i];
    }

    c->noProductos = tamanyo;
    c->importeTotal = importeTotal;

}

void imprimirTicket(Carrito c) {

    int i;

    printf("TICKET\n------\n");
    for(i = 0; i < c.noProductos; i++) {
        imprimirCompra(*c.compras[i]);
    }
    printf("...................................\n");
    printf("TOTAL: %.2f euros\n", c.importeTotal);
}

void devolverCarrito(Carrito* c) {

    int i;
    for(i = 0; i < c->noProductos; i++) {
        free(c->compras + i);
    }

    free(c->compras);
}

void modificarCarrito(Carrito* carrito, int ref, int cant) {
    int i = 0;
    bool found = false;

    while(!found) {
        if(carrito->compras[i]->p->ref == ref) found = true;
        else if (i >= carrito->noProductos) break;
        else i++;
    }

    if (found) {
        // corregimos el total
        Compra* foundCompra = carrito->compras[i];
        carrito->importeTotal -= foundCompra->unidades * foundCompra->p->precio;

        // cambiamos la cantidad
        foundCompra->unidades = cant;

        carrito->importeTotal += cant * foundCompra->p->precio;


    } else {
        printf("No se ha encontrado el id en el carrito.\n");
    }

}
