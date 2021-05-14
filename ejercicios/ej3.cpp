#include <iostream>
#include "ej3.hpp"

using namespace std;

// CONSTRUCTORES
// Normal
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

// Vacío
Point::Point() {
    x = 0;
    y = 0;
}

// Destructor
Point::~Point() {

}

// GETTERS & SETTERS
int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}

// MISC
void Point::print() {
    cout << "[ x: " << this->x << ", y: "<< this->y << " ]" << endl;
}

void Point::suma1(Point p) {
    this->x += p.x;
    this->y += p.y;
}

void Point::suma2(Point& p) {
    this->x += p.x;
    this->y += p.y;
}

void Point::suma3(Point* p) {
    this->x += p->x;
    this->y += p->y;
}

void Point::swap1(Point p) {

    this->x *= p.x;
    p.x = this->x / p.x;
    this->x /= p.x;

    this->y *= p.y;
    p.y = this->y / p.y;
    this->y /= p.y;
}

void Point::swap2(Point& p) {

    this->x *= p.x;
    p.x = this->x / p.x;
    this->x /= p.x;

    this->y *= p.y;
    p.y = this->y / p.y;
    this->y /= p.y;
}

void Point::swap3(Point* p) {

}


