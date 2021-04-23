#include <stdio.h>
#include <stdlib.h>
#include "hex/hex_tools.h"
#include <string.h>
#include "Examenes/main_examenes.h"
#include "strings/strings.h"

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

int main(int argc, char* argv[]) {
    examen_2020();

    // examen 2014
    int arg1 = 1;
    int arg2 = 2;
    // si hay suficientes argumentos (3 = programa, 1º arg y 2º arg)
    if (argc == 3) {
        sscanf(argv[1], "%d", &arg1);
        sscanf(argv[2], "%d", &arg2);
    }

    //examen_2014(arg1, arg2);

    // FIN: examen 2014

    // examen 2017
    arg1 = 15;
    if (argc == 2) {
        arg1 = atoi(argv[1]);
    }

    //examen_2017(arg1);

    return 0;
}
