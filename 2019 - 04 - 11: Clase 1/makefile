# Esto es un comentario

	# Aqui van nuestras asignaciones previas
CC=g++
CFLAGS=-Wall -std=c++14

# El símbolo '@' evitará que el comando se escriba 
# antes de ejecutarse

# Como en python, es importante la identación
# Evitar ambigüedad

all: ejemplo1 ejemplo2
	@echo "Todos los ejercicios han sido generados"

# ${var} será la syntax para que el programa reemplace según corresponda
ejemplo1:
	@${CC} ${CFLAGS} -o ej1 ejemplo1.cpp 
	@echo "ej1 generado"

ejemplo2:
	@${CC} ${CFLAGS} -o ej2 ejemplo2.cpp 
	@echo "ej2 generado"