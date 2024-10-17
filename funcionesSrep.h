#include <stdio.h>
#include <stdlib.h>

// Entradas: char* (nombre del archivo), char* (modo de acceso)
// Salida: FILE*
// Descripción: Abre un archivo y devuelve el puntero al archivo abierto
FILE *openFile(char *file_name, char *access_mode);

// Entradas: FILE* (archivo de entrada), FILE* (archivo de salida), const char* (objetivo), const char* (nuevo)
// Salida: void
// Descripción: Reemplaza todas las ocurrencias de una cadena objetivo por una nueva cadena en el archivo de entrada y escribe el resultado en el archivo de salida
void srep(FILE *fp, FILE *fp2, const char *objetivo, const char *nuevo);
