/*
 * Punto.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"
#include <stdio.h>
#include <math.h>

float distancia(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void trasladarXY(Punto* ptr1, Punto* ptr2, int x, int y) {
    ptr1->x += x; ptr2->x += x;
    ptr1->y += y; ptr2->y += y;
}

void imprimirPunto(Punto p)
{
	printf("(%i, %i)\n", p.x, p.y);
}
