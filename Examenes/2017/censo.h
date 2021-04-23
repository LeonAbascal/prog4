#ifndef CENSO_H
#define CENSO_H
#include "persona.h"

typedef struct {
    int numPersonas;
    Persona** personas;
    float mediaEdad;

}GrupoPersonas;

int cuantasPersonas(Persona*, int, int);
GrupoPersonas recuperarJovenes(Persona*, int);
Persona* recuperarYogurin(Persona*, int);

// parte 3
int cuantosNombres(Persona*, int, char);
char** listadoNombres(Persona*, int, char);

#endif // CENSO_H
