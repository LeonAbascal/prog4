void clear_stdin(); // Llamar cuando estemos seguros de que una limpieza de stdin es necesaria (si no puede pausar la ejecuci�n esperando input)
void clean_buffer(char* buffer); // Elimina el caracter de nueva l�nea de un buffer de caracteres (string)
void scan_str(char* buffer, int buffer_size); // Forma segura de leer strings del teclado

void clear_stdin() {
    char c;
    while((c = getchar()) != '\n'); // Se eliminan caracteres hasta alcanzar el salto de l�nea
}

void clean_buffer(char* buffer) {

    int pos = strlen(buffer) - 1; // Buscamos el salto de l�nea en la pen�ltima posici�n (la �ltima es '\0')
    if (buffer[pos] == '\n') {
        buffer[pos] = '\0'; // Si existe, se reemplaza por el caracter final
    }

    else {
        clear_stdin(); // Ha habido un overflow, ya que no se ha incluido el salto de l�nea y es necesaria una limpieza
    }
}

/*
void scan_str(char* buffer, int buffer_size) { // Forma segura de leer strings del teclado

    fgets(buffer, buffer_size, stdin);
    clean_buffer(buffer);
}

void scan_str(char* buffer, int buffer_size) { // Forma segura de leer strings del teclado

    fgets(buffer, buffer_size, stdin);
    clean_buffer(buffer);
}
*/
