#include "ej1.hpp"
#include "ej2.hpp"
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
