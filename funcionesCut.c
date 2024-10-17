#include <stdio.h>
#include <stdlib.h>


// Entradas: char* (nombre archivo) x char* (modo de acceso)
// Salida: FILE*
// Descripción: Abre un archivo y devuelve el puntero al archivo abierto
FILE *openFile(char *file_name, char *access_mode) {
    FILE *fptr;
    fptr = fopen(file_name, access_mode);
    if (fptr == NULL) {
        printf("Error al abrir el archivo %s\n", file_name);
        return NULL;
    }
    return fptr;
}

// Entradas: const char* (lista de columnas), int* (número de columnas)
// Salida: int* (puntero al array de índices)
// Descripción: Convierte la lista de columnas en un array de índices
int *procesarColumnas(const char *columnas, int *num_columnas) {
    static int indices[100]; // Asumimos como máximo 100 columnas
    *num_columnas = 0;

    int valor = 0;
    int leyendoNumero = 0;

    for (int i = 0; columnas[i] != '\0'; i++) {
        if (columnas[i] >= '0' && columnas[i] <= '9') {
            valor = valor * 10 + (columnas[i] - '0'); // Convertir de char a int
            leyendoNumero = 1;
        } else if (columnas[i] == ',' || columnas[i] == '.' || columnas[i] == '\0') {
            if (leyendoNumero) {
                indices[*num_columnas] = valor;
                (*num_columnas)++;
                valor = 0;
                leyendoNumero = 0;
            }
        }
    }
    if (leyendoNumero) {
        indices[*num_columnas] = valor;
        (*num_columnas)++;
    }

    return indices;
}


// Entradas: FILE* (archivo de entrada), FILE* (archivo de salida), char (delimitador), const char* (lista de columnas)
// Salida: void
// Descripción: Lee el archivo o la entrada por consola y muestra solo las columnas solicitadas
void cut(FILE *fp, FILE *fp2, char delimitador, const char *columnas) {
    char buffer[1024]; // Buffer para leer cada línea del archivo
    int *indices_columnas, num_columnas;

    // Procesar las columnas especificadas por el usuario
    indices_columnas = procesarColumnas(columnas, &num_columnas);

    // Leer línea por línea del archivo
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Verificar si la línea es una línea en blanco (contiene solo '\n' o está vacía)
        if (buffer[0] == '\n' || buffer[0] == '\0') {
            break; // Salir del bucle si se detecta una línea en blanco
        }

        // Eliminar el salto de línea al final de la línea, si existe
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                break;
            }
        }

        int columna_actual = 1; // Columna actual que estamos procesando
        int columna_a_imprimir = 0; // Control de impresión de columnas
        char *inicio = buffer; // Puntero al inicio del campo actual

        // Recorrer la línea carácter por carácter
        for (char *ptr = buffer; ; ptr++) {
            // Si encontramos el delimitador o el final de la línea
            if (*ptr == delimitador || *ptr == '\0') {
                char temp = *ptr; // Almacenar el carácter original
                *ptr = '\0'; // Terminar la cadena temporalmente

                // Verificar si esta columna está en las que se deben imprimir
                for (int i = 0; i < num_columnas; i++) {
                    if (columna_actual == indices_columnas[i]) {
                        // Imprimir el delimitador si no es la primera columna a imprimir
                        if (columna_a_imprimir > 0) {
                            if (fp2) {
                                fputc(delimitador, fp2);
                            } else {
                                putchar(delimitador);
                            }
                        }

                        // Imprimir la columna
                        if (fp2) {
                            fputs(inicio, fp2);
                        } else {
                            printf("%s", inicio);
                        }
                        columna_a_imprimir++;
                        break; // No es necesario seguir buscando en indices_columnas
                    }
                }

                *ptr = temp; // Restaurar el carácter original

                // Si es el final de la línea, salir del ciclo
                if (*ptr == '\0') break;

                // Mover el inicio al siguiente campo
                inicio = ptr + 1;
                columna_actual++;
            }
        }

        // Imprimir un salto de línea después de cada fila si al menos una columna fue impresa
        if (columna_a_imprimir > 0) {
            if (fp2) {
                fputc('\n', fp2);
            } else {
                putchar('\n');
            }
        }
    }
}
