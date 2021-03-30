#ifndef HEXTOOLS_H
#define HEXTOOLS_H

typedef unsigned char byte;

void hex_inspector(int x);
void hex_fail_inspector(int x);
void hex_editor(int x, byte most_significant_byte, byte second_byte, byte third_byte, byte least_significant_byte);
void hex_editor_example(int x);
void hex_inspector_comparison(int x);

#endif // HEXTOOLS_H
