#include "ej9.hpp"

Point3D::Point3D(int x, int y, int z) : Point(x, y) {
    this->z = z;
}

Point3D::Point3D() : Point() {
    this->z = 0;
}

Point3D::~Point3D() {

}

int Point3D::getZ() {
 return this->z;

}

void Point3D::setZ(int z) {
    this->z = z;
}

void Point3D::print() {

    cout <<
    "[ x: " << this->getX() <<
    ", y: " << this->getY() <<
    ", z: " << this->z <<
    " ]" << endl;

}
