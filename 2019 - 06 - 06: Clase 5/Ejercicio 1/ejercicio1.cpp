#include <iostream>
#include <cmath>
#include "Cola.h"
#include "Pila.h"

using namespace std;

int main(int argc, char **argv){
	if(argc != 2){
		printf("Error. Ejecutar como './ej1 palabra'.\n");
		exit(EXIT_FAILURE);
	}

	Cola ingreso;
	Pila p;

	ingreso.toBack(argv[1]);
	int currNum = 0;

	/* 	
		|
		| Código para lectura de la palabra
		|
	*/
	return 0;
}