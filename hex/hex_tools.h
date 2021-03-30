#ifndef HEXTOOLS_H
#define HEXTOOLS_H

void hex_table_inspector(void* table_ptr, int table_size, int element_size, int wide);
void hex_table_inspector_file(FILE* file, int byte_amount, int wide);

#endif // HEXTOOLS_H

