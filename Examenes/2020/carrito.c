#include "carrito.h"
#include <stdio.h>

void modificar_compra(Compra* compra, int cant) {
    compra->unidades = cant;
}

void imprimir_compra(Compra* compra) {
    printf("-----------------------------------------\nProducto: ");
    Producto p = *(compra->prod);
    imprimirProducto(p);
    printf("Unidades: %i\n", compra->unidades);
    printf("\n-----------------------------------------\n");
}
