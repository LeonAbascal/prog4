#include <stdio.h>
#include <stdlib.h>
#include "hex/hex_tools.h"
#include <string.h>

enum Wideness {VeryNarrow = 2, Narrow = 4, Normal = 8, Wide = 16};

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
    /*
    //hex_inspector(51354);
    //hex_table_inspector_example(5);


    int size = 16;
    int* nums = calloc(size, sizeof(int));
    int i;
    for(i = 0; i < 16; i++){ nums[i] = i*0x11111111; }
    //hex_table_inspector(nums, size, sizeof(int), Narrow);


    FILE* file = fopen("nums.dat", "rb");
    for (i = 0; i < 4; i++) { fgetc(file); } // displacement of 4 bytes (1 int)
    hex_table_inspector_file(file, 15 * sizeof(int), Normal); // displays the rest of the bytes
    fclose(file);

    hex_file_inspector("nums.dat", size * sizeof(int), Narrow);

    free(nums);
    */

    int i = strlen("---------------------------------");
    printf("%i", i);

    test_jonan();

    //pruebas_char();
    return 0;
}
