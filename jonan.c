#include <stdio.h>
#include <wchar.h>
#include <locale.h>

void test_jonan() {


    char* locale;

    locale = setlocale(LC_ALL, "");

    printf("Locale info: %s\n", locale);

    //wchar_t* str = L"Ñoño"; // no funciona bien en windows

    // Forma 1
    //printf("%ls\n", str);

    // Forma 2
    //wprintf(L"%s\n", str);


}
