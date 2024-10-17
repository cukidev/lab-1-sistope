#include <stdio.h>
#include <stdlib.h>

// Entradas: char* (nombre archivo) X char* (modo de acceso)
// Salida: FILE*
// Descripcion: abre un archivo
FILE *openFile(char *file_name, char *access_mode);

// Entradas: const char* (lista de columnas), int* (número de columnas)
// Salida: int* (puntero al array de índices)
// Descripción: Convierte la lista de columnas en un array de índices.
int *procesarColumnas(const char *columnas, int *num_columnas);

// Entradas: FILE* (archivo de entrada), FILE* (archivo de salida), char (delimitador), const char* (lista de columnas)
// Salida: void
// Descripcion: Lee el archivo o la entrada por consola y muestra solo las columnas solicitadas
void cut(FILE *fp, FILE *fp2, char delimitador, const char *columnas);
