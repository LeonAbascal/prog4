#include <iostream>
#include "ej3.hpp"

using namespace std;

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

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
