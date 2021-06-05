#include "Punto.h"
#include <math.h>

#include <iostream>
using namespace std;

Punto::Punto()
{
	this->x = 0;
	this->y = 0;
}

Punto::Punto(int x, int y)
{
	this->x = x;
	this->y = y;
}

Punto::~Punto()
{
}

int Punto::getX() const
{
	return this->x;
}

int Punto::getY() const
{
	return this->y;
}

void Punto::setX(int x)
{
	this->x = x;
}

void Punto::setY(int y)
{
	this->y = y;
}


void Punto::imprimir()
{
	cout << "(" << this->x << ", " << this->y << ")" << endl;
}

float Punto::distancia(Punto p)
{
	return sqrt(((p.x - this->x)*(p.x - this->x)) + ((p.y - this->y)*(p.y - this->y)));
}
