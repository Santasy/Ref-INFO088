#include <iostream>
#include <cmath>
#include "Cola.h"
#include "Pila.h"

using namespace std;

int main(int argc, char **argv){
	if(argc != 2){
		printf("Error. Ejecutar como './ej1 lista'.\n");
		exit(EXIT_FAILURE);
	}

	Cola ingreso;
	Pila p;

	ingreso.toBack(argv[1]);
	char comando;
	int currNum = 0, i;
	while(!ingreso.isEmpty()){
		comando = ingreso.front();
		switch(comando){
			case 'a':{
				// Se añaden los tres siguientes valores de currNum:
				for(i = 0; i < 3; ++i)
					p.toTop(currNum++); // Agrega primero, luego suma 1
				break;
			}

			case 'm':{
				// Resume la mitad superior de la pila a un solo valor:
				int max = floor(p.size() / 2.0);
				int suma = 0;
				for(i = 0; i < max; ++i){
					suma += p.pop();
				}
				p.toTop(suma);
				break;
			}

			case 'r':{
				// Da vuelta la pila:
				Pila aux;
				while(!p.isEmpty()){
					aux.toTop(p.pop());
				}
				p = aux;
				break;
			}

			case 's':{
				// Suma 1 a todos sus valores:
				Pila aux;
				while(!p.isEmpty()){
					aux.toTop(p.pop() + 1);
				}
				while(!aux.isEmpty()){
					p.toTop(aux.pop());
				}
				break;
			}

			case 'c':{
				// Añade 'agrv' a la fila:
				char *linea = new char[5]{'a', 's', 'r', 'v'};
				while((int) linea[0] != 0){
					ingreso.toBack(linea[0]);
					++linea;
				}
				break;
			}

			default:
				// Cualquier otro caracter, imprimirá los objetos:
				ingreso.print();
				p.print();
				printf("----------\n");
		}
	}
	return 0;
}