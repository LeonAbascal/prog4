#include "ej1.hpp"
#include "ej2.hpp"
#include "ej3.hpp"
#include <iostream>


using namespace containers;
using namespace std;

extern "C" void ejercicioCpp1() {
    ArrayInt ai(5);
    cout << "Capacidad del ArrayInt: " << ai.getCapacity() << endl;

}

extern "C" void ejercicioCpp2() {
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

extern "C" void ejercicioCpp3() {

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
