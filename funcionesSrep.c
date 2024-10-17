#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesSrep.h"

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

// Entradas: FILE (fp) X FILE (fp2) X char (objetivo) X char (nuevo)
// Salida: void
// Descripcion: Lee el archivo fp o la entrada por consola (fp2 == NULL)  
// y reemplaza el string objetivo por el string nuevo, 
// el resultado lo escribe en fp2 o lo muestra por consola
void srep(FILE *fp, FILE *fp2, const char *objetivo, const char *nuevo) {
    char buffer[1024]; // Buffer para leer cada línea del archivo o entrada
    int primer_impresion = 1; // Indicador para controlar el primer salto de línea

    // Leer línea por línea desde el archivo o la consola
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Puntero para realizar el reemplazo
        char *pos;

        // Mientras encuentres la cadena objetivo en la línea
        while ((pos = strstr(buffer, objetivo)) != NULL) {
            // Si es la primera vez que vamos a imprimir, añadir un salto de línea
            if (fp2 == NULL && primer_impresion) {
                printf("\n");  // Solo imprimimos el salto de línea una vez
                primer_impresion = 0;  // Ya se imprimió el primer salto
            }

            // Imprimir la parte anterior a la cadena objetivo
            *pos = '\0'; // Terminar la cadena en donde empieza la palabra objetivo
            if (fp2) {
                fprintf(fp2, "%s%s", buffer, nuevo); // Escribir la parte anterior + la nueva palabra en el archivo
            } else {
                printf("%s%s", buffer, nuevo); // Mostrar en consola
            }
            // Mover el buffer para procesar el resto de la línea
            memmove(buffer, pos + strlen(objetivo), strlen(pos + strlen(objetivo)) + 1);
        }

        // Si es la primera vez que vamos a imprimir, añadir un salto de línea
        if (fp2 == NULL && primer_impresion) {
            printf("\n");  // Solo imprimimos el salto de línea una vez
            primer_impresion = 0;  // Ya se imprimió el primer salto
        }

        // Imprimir o escribir lo que queda de la línea (sin más coincidencias de la palabra objetivo)
        if (fp2) {
            fputs(buffer, fp2); // Escribir el resto en el archivo de salida
        } else {
            printf("%s", buffer); // Mostrar el resto en consola
        }
    }
}