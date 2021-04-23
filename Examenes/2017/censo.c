#include "censo.h"
#include <stdlib.h>
#include <stdio.h>

int cuantasPersonas(Persona* ap, int tamanyo, int edad) {

    int i;
    int totalMenores = 0;
    for (i = 0; i < tamanyo; i++) {
        Persona p = ap[i];
        if (p.edad < edad) {
            totalMenores++;
        }
    }

    return totalMenores;

}

GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo){

    GrupoPersonas gp;
    gp.mediaEdad = 0;
    gp.numPersonas = 0;
    gp.personas = NULL;
    int contador = 0;
    Persona p;
    int i;
    for(i = 0; i < tamanyo; i++) {
        p = ap[i];
        if (p.edad < 30) {

            // ampliamos la tabla
            gp.numPersonas++;
            gp.personas = realloc(gp.personas, gp.numPersonas * sizeof(Persona*));

            // metemos a la persona
            gp.personas[contador] = ap + i;
            contador++;

            // nueva media
            gp.mediaEdad = (gp.mediaEdad*(gp.numPersonas-1) + p.edad) / gp.numPersonas;
        }
    }

    return gp;
}


Persona* recuperarYogurin(Persona* ap, int tamanyo){

    int i;
    Persona* yogurin = ap;
    for(i = 0; i < tamanyo-1; i++) {

        if(yogurin->edad > ap[i+1].edad) {
            yogurin = ap + i+1;

        }
    }

    return yogurin;

}

int cuantosNombres(Persona* ap, int tamanyo, char letra) {
    int total = 0;

    int i;
    for(i = 0; i < tamanyo; i++) {
        char* nombre = (ap + i)->nombre;
        if (nombre[0] == letra) {
            total++;
        }

    }

    return total;
}

char** listadoNombres(Persona* ap, int tamanyo, char letra) {

    int numNombres = cuantosNombres(ap, tamanyo, letra);
    char** nombres = malloc(numNombres * sizeof(char*));

    if (numNombres != 0) {
        int contador = 0;
        int i;

        for (i = 0; i < tamanyo; i++) {
            char* nombre = (ap + i)->nombre;
            if (nombre[0] == letra) {
                nombres[contador] = nombre;
                contador++;

            }
        }
    }

    return nombres;
}
