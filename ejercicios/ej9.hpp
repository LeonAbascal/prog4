#ifndef EJ9_HPP
#define EJ9_HPP
#include "ej3.hpp"
#include <iostream>

using namespace std;

class Point3D: public Point {
private:
    int z;

public:
    Point3D();
    Point3D(int x, int y, int z);
    virtual ~Point3D();

    int getZ();
    void setZ(int z);

    virtual void print();

    Point3D operator*(const Point3D &p3d) const {
        Point3D p3dret = *this;
        p3dret.x *= p3d.x;
        p3dret.y *= p3d.y;
        p3dret.z *= p3d.z;

        return p3dret;
    }

    Point3D operator*(const int a) const {
        Point3D p3d = *this;
        p3d.x *= a;
        p3d.y *= a;
        p3d.z *= a;

        return p3d;

    }

};

#endif //EJ9_HPP
