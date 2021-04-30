#include "ej2.hpp"
#include <stdlib.h>
#include <iostream>

using namespace containers;
using namespace std;

Element::Element(int data) {

    this->data = data;
    next = nullptr;
}

int Element::getData() const {
    return data;
}

void Element::setNext(Element* e) {
    next = e;
}

Element* Element::getNext() const {
    return next;
}

void Element::toString() const {
    cout << "Data: " << this->data << endl;
    cout << "Next ptr: " << this->getNext() << endl;
    cout << endl;
}

// STACK CLASS
Stack::Stack() {
    first = nullptr;
    size = 0;
}

Stack::~Stack() {
    this->clear();

}

void Stack::push(int data) {

    Element* eNuevo = new Element(data);

    Element* e = this->first;

    if (e != nullptr) {

        int i = 0;
        while(e->getNext() != nullptr) {

            e->toString();
            e = e->getNext();
            i++;
            if (i >= 8) break;
        }

        e->setNext(eNuevo);


    } else {
        this->first = eNuevo;
    }

    size++;

}

int Stack::pop() {
    Element* e = first;
    Element* e1 = nullptr;

    if (e == nullptr) {
        cout << "No hay elementos en la pila" << endl;
        return -1;

    } else {

        // si 'e' no es el último
        while (e->getNext() != nullptr) {

            e1 = e;
            e = e->getNext();
        }

        // Sacamos el último elemento
        int data = e->getData();
        delete e;
        if (e1 != nullptr) e1->setNext(nullptr);
        else first = nullptr;
        size--;

        return data;


    }
}

int Stack::poll() {

    if (first == nullptr) {
        cout << "Pila vacia" << endl;
        return -1;

    } else {
        Element* e = this->first;

        while(e->getNext() != nullptr) {
            e = e->getNext();
        }

        return e->getData();

    }
}

void Stack::clear() {

    while(size > 0) {
        pop();
    }
    cout << size << endl;

}

unsigned int Stack::getSize() {
    return this->size;
}
