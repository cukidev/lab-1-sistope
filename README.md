# Laboratorio 1 de Sistemas Operativos 2-2024

Este proyecto consiste en tres herramientas de procesamiento de archivos diseñadas para ejecutar operaciones específicas sobre archivos de texto o entradas de consola: `srep`, `cut`, y `count`. Cada herramienta cumple una función distinta, detallada a continuación.

## Índice

1. [Autoras](#autoras)
2. [Descripción General](#descripción-general)
3. [Herramientas](#herramientas)
   - [srep](#srep)
   - [cut](#cut)
   - [count](#count)
4. [Uso](#uso)
   - [Compilación](#compilación)
   - [Ejecución](#ejecución)
5. [Requisitos del Sistema](#requisitos-del-sistema)

---

## Autoras

Las creadoras del presente laboratorio son:

* [Paloma Zepeda](https://github.com/cukidev)
* [Amalia Veas](https://github.com/MaliViaux)


## Descripción General

Este proyecto contiene tres programas de línea de comandos que permiten realizar operaciones sobre archivos de texto delimitados o entradas de consola:

- `srep`: Realiza búsqueda y reemplazo de texto dentro de un archivo.
- `cut`: Extrae columnas específicas de un archivo delimitado.
- `count`: Cuenta líneas y caracteres en un archivo de texto.

Cada programa acepta una serie de argumentos que permiten al usuario especificar archivos de entrada y salida, delimitadores y otras opciones.

---

## Herramientas

### srep

El comando `srep` busca y reemplaza cadenas de texto en un archivo o entrada de consola. 

#### Ejemplo de uso:

```bash
./srep -i input.csv -o output.csv -s "Madrid" -S "Santiago"
```

Este ejemplo lo que hace es que reemplaza la ciudad de Madrid por Santiago, guardando el resultado en un `output.txt`

#### Argumentos:
* -i: Archivo de entrada. Si no se especifica, la entrada será stdin.
* -o: Archivo de salida. Si no se especifica, la salida será stdout.
* -s: Texto a buscar en el archivo.
* -S: Texto que reemplazará al buscado.

---

### cut

El comando `cut` se utiliza para extraer columnas específicas de un archivo delimitado o entrada de consola. El usuario puede especificar el delimitador y las columnas a extraer.

#### Ejemplo de uso:

```bash
./cut -i input.txt -o output.txt -d : -c 1,2,4
```

Este ejemplo extrae las columnas 1, 3 y 5 del archivo `input.txt` y guarda el resultado en `output.txt`, utilizando una coma como delimitador.

#### Argumentos:
* -i: Archivo de entrada. Si no se especifica, la entrada será stdin.
* -o: Archivo de salida. Si no se especifica, la salida será stdout.
* -d: Delimitador de campos. Si no se especifica, se utiliza una tabulación.
* -c: Columnas a extraer, separadas por comas.

---

### count

El comando `count` cuenta las líneas y los caracteres de un archivo o entrada de consola. Permite al usuario decidir si contar líneas, caracteres o ambos.

#### Ejemplo de uso:

```bash
./count -i input.txt -C
```

Este ejemplo cuenta el número de caracteres en `input.txt`.

```bash
./count -i input.txt -L
```
Este ejemplo cuenta el número de líneas en `input.txt`.

```bash
./count -i input.txt -L -C
```

Este ejemplo cuenta el número de líneas y caracteres en `input.txt`.

#### Argumentos:
* -i: Archivo de entrada. Si no se especifica, la entrada será stdin.
* -C: Cuenta el número de caracteres.
* -L: Cuenta el número de líneas.

---

## Uso

### Compilación

Este proyecto utiliza un `Makefile` para facilitar la compilación. Para compilar las herramientas, ejecuta:

```bash
make
```

Esto generará los ejecutables `srep`, `cut`, y `count`.

### Ejecución

Cada herramienta puede ejecutarse desde la línea de comandos con los argumentos correspondientes. Algunos ejemplos de ejecución se encuentran en las secciones anteriores.

### Limpiar el proyecto

Para eliminar los archivos compilados y otros temporales:

```bash
make clean
```

---
## Requisitos del Sistema

* Compilador de C (como gcc).
* Sistema operativo Unix/Linux o cualquier sistema compatible con POSIX.