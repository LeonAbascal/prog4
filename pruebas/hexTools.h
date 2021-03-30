#ifndef HEXTOOLS_H
#define HEXTOOLS_H

typedef unsigned char byte;

void hex_inspector(int x);
void hex_fail_inspector(int x);
void hex_editor(int x, byte most_significant_byte, byte second_byte, byte third_byte, byte least_significant_byte);
void hex_editor_example(int x);
void hex_inspector_comparison(int x);

/** @brief Given a wideness it prints a table in hex
 *  @param Wideness Total number of columns
*/
void hex_table_inspector_example(int wide);

void hex_table_inspector(void* table_ptr, int table_size, int element_size, int wide);

#endif // HEXTOOLS_H
