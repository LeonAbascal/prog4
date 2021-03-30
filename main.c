#include <stdio.h>
#include <stdlib.h>
#include "hex/hex_tools.h"
enum Wideness {VeryNarrow = 2, Narrow = 4, Normal = 8, Wide = 16};

int main()
{
    //hex_inspector(51354);
    //hex_table_inspector_example(5);


    int size = 16;
    int* nums = calloc(size, sizeof(int));
    int i;
    for(i = 0; i < 16; i++){ nums[i] = i*0x11111111; }
    //hex_table_inspector(nums, size, sizeof(int), Narrow);


    FILE* file = fopen("nums.dat", "rb");
    for (i = 0; i < 4; i++) { fgetc(file); }
    hex_table_inspector_file(file, 15 * 4, Normal);
    fclose(file);


    free(nums);

    return 0;
}
