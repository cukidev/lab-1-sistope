#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "funcionesCut.h"

int main(int argc, char *argv[]) {
    int opcion;
    char *nombre_archivo_entrada = NULL;
    char *nombre_archivo_salida = NULL;
    char delimitador = ';';  // Delimitador por defecto
    char *columnas = NULL;   // Columnas a extraer (por ejemplo, "1,3,5")
    FILE *fp = NULL, *fp2 = NULL;

    // Ejemplo de comando:
    /*
    ./cut -i input.txt -o output.txt -d : -c 2,4
    */
    while ((opcion = getopt(argc, argv, "i:o:d:c:")) != -1) {
        switch (opcion) {
        case 'i':
            nombre_archivo_entrada = optarg; // Nombre del archivo de entrada
            break;
        case 'o':
            nombre_archivo_salida = optarg;  // Nombre del archivo de salida
            break;
        case 'd':
            delimitador = optarg[0];         // Delimitador personalizado
            break;
        case 'c':
            columnas = optarg;               // Columnas a extraer
            break;
        default:
            return 1;
        }
    }

    // Especificar si se debe abrir un archivo o usar stdin
    if (nombre_archivo_entrada) {
        fp = openFile(nombre_archivo_entrada, "r");
        if (fp == NULL) {
            perror("Error al abrir el archivo de entrada");
            return 1;
        }
    } else {
        fp = stdin; // Usar stdin si no se especifica archivo de entrada
    }

    // Especificar si se debe abrir un archivo de salida o usar stdout
    if (nombre_archivo_salida) {
        fp2 = openFile(nombre_archivo_salida, "w");
        if (fp2 == NULL) {
            perror("Error al abrir el archivo de salida");
            return 1;
        }
    }

    // Llamada a la función principal para realizar la extracción de columnas
    cut(fp, fp2, delimitador, columnas);

    // Cerrar archivos si se abrieron
    if (fp != stdin) {
        fclose(fp);
    }
    if (fp2) {
        fclose(fp2);
    }

    return 0;
}
