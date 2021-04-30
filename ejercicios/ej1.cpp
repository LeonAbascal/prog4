#include <stdlib.h>
#include <stdio.h>
#include "ej1.hpp"

#define DEFAULT_CAPACITY 10

using namespace containers;

ArrayInt::ArrayInt() {
    this->capacity = DEFAULT_CAPACITY;
    array = new int[this->capacity];
}

ArrayInt::ArrayInt(unsigned int capacity) {
    this->capacity = capacity;
    this->array = (int*) malloc(capacity * sizeof(int));
}

ArrayInt::~ArrayInt() {
    delete[] array;

}

void ArrayInt::setValue(unsigned int index, int data) {
    if (index < this->capacity) {
        this->array[index] = data;

    } else {
        printf("Index out of bounds\n");
    }

}

int ArrayInt::getValue(unsigned int index) {
    return this->array[index];
}

void ArrayInt::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
    this->array = (int*) realloc(this-> array, capacity * sizeof(int));
}

unsigned int ArrayInt::getCapacity() {
    return this->capacity;
}
