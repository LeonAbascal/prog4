#include <stdio.h>
#include <stdlib.h>

// char* (string) to other data types
void example_conversions() {


    // https://www.geeksforgeeks.org/atol-atoll-and-atof-functions-in-c-c/

    // INTS
    int x, y;
    sscanf("123", "%d", &x);
    y = atoi("321");
    printf("x: %i, y: %i\n", x, y);

    // FLOATS
    float f1, f2;
    sscanf("12.4", "%f", &f1);
    f2 = atof("2.8");
    printf("f1: %.2f, f2: %.2f", f1, f2);

}
