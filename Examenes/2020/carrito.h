#ifndef CARRITO_H
#define CARRITO_H
#include "producto.h"

typedef struct {
    int unidades;
    Producto* prod;

} Compra;

void modificar_compra(Compra* compra, int cant);
void imprimir_compra(Compra* compra);

#endif // CARRITO_H
