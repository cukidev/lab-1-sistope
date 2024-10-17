#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "funcionesCount.h"

int main (int argc, char *argv[]){

    int opcion;
    char *nombre_archivo = NULL;
    int opcionL = 0, opcionC = 0;
    FILE *fp = NULL;

    // ejemplo de comando
    /*
     ./count -i input.txt -C
     ./count -i input.txt -L
     ./count -i input.txt -L -C
     ./count -i input.txt -C -L

    */

    while ((opcion = getopt(argc, argv, "i:CL")) != -1){
        switch (opcion){
        case 'i':
            nombre_archivo = optarg; // indica el nombre del archivo de entrada
            break;
        case 'C':
            opcionC = 1; // opcion para contar caracteres
            break;
        case 'L':
            opcionL = 1; // opcion para contar lineas
            break;  
        default:
            return 1;
        }
    }

    // Especifica o no nombre_archivo
    if (nombre_archivo) { fp = openFile(nombre_archivo,"r"); } 
    else { fp = stdin; }

    count(fp, opcionL, opcionC); // llamada a funcion principal

    // Cerrar el archivo si se abrió
    if (fp != stdin) { fclose(fp); }

    return 0;
}
