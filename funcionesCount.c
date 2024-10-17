#include <stdio.h>
#include <stdlib.h>
#include "funcionesCount.h"

// Entradas: char (nombre archivo) X char (modo de acceso)
// Salida: FILE
// Descripcion: abre un archivo
FILE *openFile(char *file_name, char *access_mode){
	FILE *fptr;
	fptr = fopen(file_name, access_mode);
	if (fptr == NULL){
		printf("Error al abrir el archivo %s\n", file_name);
		return NULL;
	}
	return fptr;
}

// Entradas: FILE (fp) X int (opcionL) X int (opcionC)
// Salida: void
// Descripcion: Lee el archivo o la entrada por consola y cuenta los caracteres
// y las lineas, muestra por consola la cantidad de lineas y/o caracteres 
void count(FILE *fp, int opcionL, int opcionC) {
    int lineas = 0, caracteres = 0;
    char ch;

    // Leer el archivo o stdin carácter por carácter
    while ((ch = fgetc(fp)) != EOF) {
        if (opcionC) {
            // Contar caracteres (incluye espacios, saltos de línea, etc.)
            caracteres++;
        }
        if (opcionL && ch == '\n') {
            // Contar líneas (cuando se encuentra un salto de línea)
            lineas++;
        }
    }

    if (opcionL && opcionC) {
        // 
        printf("%d %d\n", lineas, caracteres);
    } else if (opcionL) {
        // Solo imprimir la cantidad de líneas
        printf("%d\n", lineas);
    } else if (opcionC) {
        // Solo imprimir la cantidad de caracteres
        printf("%d\n", caracteres);
    }
}