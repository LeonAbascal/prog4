#include <stdio.h>
#include <stdlib.h>
#include "pruebas/hexTools.h"
enum Wideness {VeryNarrow = 2, Narrow = 4, Normal = 8, Wide = 16};

int main()
{
    hex_inspector(51354);
    //hex_table_inspector_example(5);

    int size = 2048;
    int nums3[size];
    int* nums2 = malloc(size * sizeof(int));
    int* nums = calloc(size, sizeof(int));
    hex_table_inspector(nums3, size, sizeof(int), 20);

    free(nums);
    free(nums2);

    return 0;
}
