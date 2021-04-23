#ifndef CARRITO_H
#define CARRITO_H
#include "producto.h"

typedef struct {
    int unidades;
    Producto* p;

} Compra;

typedef struct {
    int noProductos;
    Compra** compras;
    float importeTotal;

} Carrito;

// parte 1
void modificarCompra(Compra*, int);
void imprimirCompra(Compra);

// parte 2
void crearCarrito(Carrito* c, Producto* prods, int* cants, int tamanyo);
void imprimirTicket(Carrito c);
void devolverCarrito(Carrito* c);

// parte 3
void modificarCarrito(Carrito* carrito, int ref, int cant);

#endif // CARRITO_H
