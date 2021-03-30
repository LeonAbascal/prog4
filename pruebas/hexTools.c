#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void hex_inspector(int x) {

    byte* ptr = (byte*)&x;
    printf("HEX: [ ");
    printf("%.2X ", ptr[3]);
    printf("%.2X ", ptr[2]);
    printf("%.2X ", ptr[1]);
    printf("%.2X ", ptr[0]);
    printf("]\n");

    printf("Int: %i\n\n", x);
}

void hex_fail_inspector(int x) {
    // why doesn't work?

    //                                         byte# 1  2  3  4
    // what is stored in memory 128 (32 bits) [ int: 00 00 00 80 ]
    // this process will happen with each byte SEPARATELY
    // zero is a non problematic value, so we will skip up to the 4th byte

    // signed vs unsigned char -> -128 up to 127; 0 up to 255
    // that's something we will pay attention to when doing "promotion"
    // when calling printf, this promotion to int is happening
    // for the signed char, the value stored in memory is -128 (0x80 = 1000 0000)

    // when promotion happens from a 8 bit SIGNED char to 32 bit SIGNED int
    // at ASM level will happen a "MOVSX - MOVe with Sign eXtension"
    // (for unsigned types we will use "MOVZX - MOVe with Zero eXtension")
    // since we are filling an empty space and we want to keep the sign extension,
    // we need to pay attention to the MSb of the smaller value (1 = negative, 0 = positive)
    // then, we will fill that empty space with that bit, in order to keep its sign


    // signed char = 1000 0000 = 0x80 = -128 (8 bit extension)
    //               ^ msb is 1 -> thus, is negative

    // signed int  = 1111 1111 1111 1111 1111 1111 1000 0000 = 0xFFFF FF80 = -128 (32 bit extension)
    //               ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ ^^^^ 24 empty bits will be filled up with ones

    signed char* ptr = (signed char*)&x;
    printf("HEX: [ ");
    printf("%.2X ", ptr[3]);
    printf("%.2X ", ptr[2]);
    printf("%.2X ", ptr[1]);
    printf("%.2X ", ptr[0]);
    printf("]\n");

    printf("Int: %i\n\n", x);
}

void hex_editor_example(int x) {
    hex_inspector(x);

    byte* ptr = (byte*)&x;
    ptr[0] = 0xEF;
    ptr[1] = 0x6B;
    ptr[2] = 0x80;
    ptr[3] = 0x00;
    // x = 8416239;


    hex_inspector(x);

}

void hex_editor(int x, byte most_significant_byte, byte second_byte, byte third_byte, byte least_significant_byte) {
    byte* ptr = (byte*)&x;
    ptr[3] = most_significant_byte;
    ptr[2] = second_byte;
    ptr[1] = third_byte;
    ptr[0] = least_significant_byte;
}

void hex_inspector_comparison(int x) {
    printf("\n-------------------\n");
    printf("Working Inspector:\n");
    hex_inspector(x);
    printf("Fail Inspector:\n");
    hex_fail_inspector(x);
    printf("-------------------\n");
    printf("Working Inspector:\n");
    hex_inspector(127);
    printf("Fail Inspector:\n");
    hex_fail_inspector(127);
    printf("-------------------\n");
    printf("Working Inspector:\n");
    hex_inspector(128);
    printf("Fail Inspector:\n");
    hex_fail_inspector(128);
    printf("-------------------\n");
}
