#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "funcionesSrep.h"

int main (int argc, char *argv[]) {

    int opcion;
    char *nombre_archivo_entrada = NULL;
    char *nombre_archivo_salida = NULL;
    char *objetivo = NULL, *nuevo = NULL;  // inicializamos los caracteres
    FILE *fp = NULL, *fp2 = NULL;

    // ejemplo de comando
    /*
    ./srep -i input.txt -o output.txt -s / -S \
    */
    while ((opcion = getopt(argc, argv, "i:o:s:S:")) != -1) {
        switch (opcion) {
        case 'i':
            nombre_archivo_entrada = optarg; // indica el nombre del archivo de entrada
            break;
        case 'o':
            nombre_archivo_salida = optarg; // indica el nombre del archivo de salida
            break;
        case 's':
            objetivo = optarg; // tomar solo el primer carácter de la cadena
            break;
        case 'S':
            nuevo = optarg; // tomar solo el primer carácter de la cadena
            break;
        default:
            return 1;
        }
    }

    // Especifica o no -i
    if (nombre_archivo_entrada) { 
        fp = fopen(nombre_archivo_entrada, "r"); 
        if (fp == NULL) {
            perror("Error al abrir el archivo de entrada");
            return 1;
        }
    } else { 
        fp = stdin; 
    }

    // Especifica o no -o
    if (nombre_archivo_salida) { 
        fp2 = fopen(nombre_archivo_salida, "w"); 
        if (fp2 == NULL) {
            perror("Error al abrir el archivo de salida");
            return 1;
        }
    }

    // Llamada a la función principal para realizar el reemplazo
    srep(fp, fp2, objetivo, nuevo); 
    
    // Cerrar los archivos si se abrieron
    if (fp != stdin) { 
        fclose(fp); 
    }
    if (fp2) { 
        fclose(fp2); 
    }

    return 0;
}
