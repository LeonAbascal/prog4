#ifndef CARRITO_H
#define CARRITO_H
#include "producto.h"

typedef struct {
    int unidades;
    Producto* prod;

} Compra;

typedef struct {
    Compra* compras;
    float importe_total;
} Carrito;

void modificar_compra(Compra* compra, int cant);
void imprimir_compra(Compra* compra);
void crear_carrito(Carrito* carrito, Producto* productos, int* cantidades, int tamanyo);
void imprimir_ticket(Carrito carrito);
void modificar_carrito(Carrito* carrito, int ref, int cant);
void devolver_carrito(Carrito* carrito);

#endif // CARRITO_H
