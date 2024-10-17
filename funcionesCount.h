#include <stdio.h>
#include <stdlib.h>

// Entradas: char (nombre archivo) X char (modo de acceso)
// Salida: FILE
// Descripcion: abre un archivo
FILE *openFile(char *file_name, char *access_mode);

// Entradas: pointer (fp) X int (opcionL) X int (opcionC)
// Salida: void
// Descripcion: Lee el archivo o la entrada por consola y cuenta los caracteres
// y las lineas, muestra por consola la cantidad de lineas y/o caracteres 
void count(FILE *fp, int opcionL, int opcionC);