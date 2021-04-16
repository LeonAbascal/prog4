#include <stdio.h>
#include <stdlib.h>
#include "hex/hex_tools.h"
#include <string.h>
#include "Examenes/main_examenes.h"

void pruebas_char3(char* s) {
    printf("0x%p\n", s);
}

char* pruebas_char2() {
    pruebas_char3("hola");
    pruebas_char3("adios");
    pruebas_char3("holaa");
    //return c;

}

char* pruebas_char() {
    char* c = "aga";
    // *c = 'g'; // da error porque el char se reserva estáticamente.
    pruebas_char2();
}

char* pruebas_char4() {

    char* c = malloc(4 * sizeof(char)); // Se guarda en el heap
    char* c2 = c;
    c = "hola"; // Se guarda en estático, es una nueva reserva
    printf("Original: %p\n", c2);
    printf("Nuevo: %p\n", c);

}

int main()
{
    examen_2020();

    return 0;
}
