#include <stdio.h>
#include <stdlib.h>
#include "hex/hex_tools.h"
#include <string.h>
#include "Examenes/main_examenes.h"
#include "strings/strings.h"
#include "ejercicios/main_ejercicios.hpp"


void examenes(int argc, char* argv[]) {
    //examen_2020();

    // examen 2014
    int arg1 = 1;
    int arg2 = 2;
    // si hay suficientes argumentos (3 = programa, 1º arg y 2º arg)
    if (argc == 3) {
        sscanf(argv[1], "%d", &arg1);
        sscanf(argv[2], "%d", &arg2);
    }


    examen_2014(arg1, arg2);

    // FIN: examen 2014

    // examen 2017
    arg1 = 15;
    if (argc == 2) {

        arg1 = atoi(argv[1]);
    }

    //examen_2017(arg1);

}

int main(int argc, char* argv[]) {
    ejercicioCpp9();


    return 0;
}
