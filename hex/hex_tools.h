#ifndef HEXTOOLS_H
#define HEXTOOLS_H

enum Wideness {VeryNarrow = 2, Narrow = 4, Normal = 8, Wide = 16};

void hex_table_inspector(void* table_ptr, int table_size, int element_size, int wide);
void hex_table_inspector_file(FILE* file, int byte_amount, int wide);
void hex_file_inspector(char* filename, int byte_amount, int wide);

#endif // HEXTOOLS_H

