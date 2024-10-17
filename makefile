FLAGS = -Wall -lm

# Compilar todos los programas
all: srep count cut

# Regla para compilar srep
srep: srep.o funcionesSrep.o
	gcc $(FLAGS) -o srep srep.o funcionesSrep.o

# Regla para compilar count
count: count.o funcionesCount.o
	gcc $(FLAGS) -o count count.o funcionesCount.o

# Regla para compilar cut
cut: cut.o funcionesCut.o
	gcc $(FLAGS) -o cut cut.o funcionesCut.o

# Objetos para las funciones y programas principales

cut.o: cut.c funcionesCut.h
	gcc -c $(FLAGS) cut.c

srep.o: srep.c funcionesSrep.h
	gcc -c $(FLAGS) srep.c

count.o: count.c funcionesCount.h
	gcc -c $(FLAGS) count.c

funcionesCut.o: funcionesCut.c funcionesCut.h
	gcc -c $(FLAGS) funcionesCut.c

funcionesSrep.o: funcionesSrep.c funcionesSrep.h
	gcc -c $(FLAGS) funcionesSrep.c

funcionesCount.o: funcionesCount.c funcionesCount.h
	gcc -c $(FLAGS) funcionesCount.c

# Limpiar los archivos generados
clean:
	rm -f *.o srep count cut
