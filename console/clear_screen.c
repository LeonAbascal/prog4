#if __gnu_linux__
void clear_screen() {
    system("clear");
}

#elif _WIN64 || _WIN32
void clear_screen() {
    system("cls");
}

#else
void clear_screen() {
    putchar('\n');
}

#endif
