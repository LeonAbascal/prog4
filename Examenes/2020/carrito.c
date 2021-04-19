#include "carrito.h"
#include <stdio.h>
#include <stdlib.h>

void crear_carrito(Carrito* carrito, Producto* productos, int* cantidades, int tamanyo) {

    int i;
    float total = 0;

    Compra* compras = malloc(tamanyo * sizeof(Compra));

    for (i = 0; i < tamanyo; i++) {
        Producto* p = productos + i;
        compras[i].prod = p;
        compras[i].unidades = cantidades[i];

        total+=cantidades[i] * p->precio;
    }

    carrito->compras = compras;
    carrito->importe_total = total;

}

void imprimir_ticket(Carrito carrito) {

    int i = 0;
    float carrito_no_vacio = carrito.importe_total;

    printf("TICKET\n");
    printf("------\n");

    while(carrito_no_vacio > 0) {

        imprimir_compra(carrito.compras + i);

        carrito_no_vacio -= carrito.compras[i].unidades * carrito.compras[i].prod->precio;
        i++;
    }

    printf("........................................\n");
    printf("TOTAL: %.2f euros\n", carrito.importe_total);
}

void modificar_carrito(Carrito* carrito, int ref, int cant) {
    int existe = 0;
    int i = 0;

    float carrito_no_vacio = carrito->importe_total;
    // existe?
    Compra* c = carrito->compras;
    while (carrito_no_vacio) {

        if (c[i].prod->ref == ref) {
            existe = 1;

            break;
        }

        carrito_no_vacio -= c[i].unidades * c[i].prod->precio;
        i++;
    }

    if (existe) {
        // precio total + ( (ahora - antes) * precio)
        // antes 1, ahora 3
        // total + (3 - 1) * 12 = total + 2*12 = total + 24
        // antes 3, ahora 1
        // total + (1 - 3) * 12 = total + (-2)*12 = total -24
        carrito->importe_total += (cant - c[i].unidades) * c[i].prod->precio; // Rebalanceamos el total
        c[i].unidades = cant; // Registramos la nueva cantidad
    }
}

void devolver_carrito(Carrito* carrito) {
    int carrito_no_vacio = carrito->importe_total;

    if (carrito_no_vacio) {
        free(carrito->compras);
    }
}

void modificar_compra(Compra* compra, int cant) {
    compra->unidades = cant;
}

void imprimir_compra(Compra* compra) {
    Producto p = *(compra->prod);
    imprimirProducto(p);
    printf(" x %i kg/ud\n", compra->unidades);
}
