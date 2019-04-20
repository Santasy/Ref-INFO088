CC=g++
CFLAGS=-Wall -std=c++14

all: Ejercicio1 Ejercicio2
	@echo "Se han generado ambos archivos."
	
Ejercicio1:
	@${CC} ${CFLAGS} -o ej1 Ejercicio1.cpp
	@echo "Se ha generado ej1."
	@cp Ejercicio1.cpp Ejercicio2.cpp
	@echo "Se ha copiado el archivo para el ejercicio 2."
	
Ejercicio2:
	@${CC} ${CFLAGS} -o ej2 Ejercicio2.cpp
	@echo "Se ha generado ej2."


