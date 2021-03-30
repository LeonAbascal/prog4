#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char byte;
enum Wideness {VeryNarrow = 2, Narrow = 4, Normal = 8, Wide = 16};

// recommended use of Wideness enum for wide
void hex_table_inspector(void* table_ptr, int table_size, int element_size, int wide) {

    byte* ptr = (byte*) table_ptr;
    int size = table_size * element_size;
    int i;
    for (i = 0; i < size; i++) {
        // unfixed
        if (i % wide == 0) {
            printf(" ]\n%p: [", ptr + i);
        }

        printf(" %.2X", *(ptr + i));
    }

    printf(" ]\n");
}

void hex_table_inspector_file(FILE* file, int byte_amount, int wide) {

    if (file != NULL) {
        int  i;
        for(i = 0; i < byte_amount; i++) {
            if (i % wide == 0) {
                printf(" ]\n%p: [", file);
            }

            printf(" %.2X", fgetc(file));
        }

        printf("]\n");
    }
}

