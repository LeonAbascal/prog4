#include "ej1.hpp"
#include "ej2.hpp"
#include "ej3.hpp"
#include "ej9.hpp"
#include <iostream>


using namespace containers;
using namespace std;

void ejercicioCpp1() {
    ArrayInt ai(5);
    cout << "Capacidad del ArrayInt: " << ai.getCapacity() << endl;

}

void ejercicioCpp2() {
    Stack s;
    s.pop();
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    cout << "Last value (pop): " << s.pop() << endl;
    cout << "Last value (poll): " << s.poll() << endl;

    delete &s;
}

void ejercicioCpp3() {

    Point p1(1, 3);
    Point p2(3, 1);

    cout << "-SWAP 1 ---------" << endl;
    p1.print();
    cout << "<=>" << endl;
    p2.print();
    p1.swap1(p2);
    cout << "=" << endl;
    p1.print(); p2.print();


    cout << "-SUMS -----------" << endl;
    p1.print();
    cout << " +" << endl;
    p2.print();
    cout << " =" << endl;

    p1.suma1(p2);
    p1.print();
    p1.suma2(p2);
    p1.print();
    p1.suma3(&p2);
    p1.print();

    cout << "-SWAP 2 ---------" << endl;
    p1.swap2(p2);
    p1.print(); p2.print();

    cout << "-SWAP 3 ---------" << endl;
    p1.swap3(&p2);
    p1.print(); p2.print();
}

void ejercicioCpp9() {

    Point p(1, 2);
    Point3D p2(1, 2, 3);
    Point3D p3(5, 2, 6);
    Point p4(4, 2);
    Point3D p5(3, 3, 4);

    Point* puntos[5];
    puntos[0] = &p;
    puntos[1] = &p2;
    puntos[2] = &p3;
    puntos[3] = &p4;
    puntos[4] = &p5;

    int i;
    for (i = 0; i < 5; i++) {
        puntos[i]->print();
    }

    p2 = p2 * p3;
    p2.print();
    p2 = p3 * 2;
    p2.print();

}
