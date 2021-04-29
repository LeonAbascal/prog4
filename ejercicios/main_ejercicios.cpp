#include "ej1.hpp"
#include <iostream>

using namespace containers;
using namespace std;

extern "C" void ejercicioCpp1()
{
    ArrayInt ai(5);
    cout << "Capacidad del ArrayInt: " << ai.getCapacity() << endl;

}
