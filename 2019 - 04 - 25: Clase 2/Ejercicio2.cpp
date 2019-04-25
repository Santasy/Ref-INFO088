#include <iostream>
/* Para usuarios de Windows:
#include <ctime>
#include <stdlib.h>
*/

using namespace std;

#define N_C 100 //Número de cálculos a almacenar

/*{ retorno} */ void fibonacci(/* *{argumentos} */);
void printAll(/* *{argumentos} */);

int main(int argc, char **argv){
	srand(time(NULL));
	cout.precision(0); // Fija la cantidad de indices decimales a imprimir a través de std::cout a 0, asegurando que el número entero imprima todos sus dígitos.
	// Para que funcione, se debe entregar '<< fixed' antes de entregar el número '<< n'
	
	int calculos = 0; // Contador de cálculos necesitados durante la ejecución del programa
	/*{tipo}*/ *calculados = new /*{tipo}*/[N_C]{0, 1, 1}; // Nos ahorramos los primeros cálculos, que son un poco más tedioso de generar.
	
	// Esta es una técnica lógica simple, que nos permiten crear condiciones para el avance de nuestro programa
	for(int i = 3; i < N_C; i++) calculados[i] = -1; // Definimos que si la casilla contiene un '-1', significará que el valor no ha sido calculado.
	
	/* Llamdos triviales a la funcion */
	for(int i = 0; i < 15; i++){
		int v = rand() % N_C; // Indice a buscar
		/*{tipo}*/ r = fibonacci(/* *{argumentos} */);
		cout << "Fibonacci indice " << v << ": " << fixed << r << '\n';
	}
	cout << "Se han realizado " << calculos << " calculos.\n\n";
	
	printAll(/* *{argumentos} */);
	return 0;
}

/*{retorno}*/ fibonacci(/* *{argumentos} */){
	/* Función que entrega el número en índice 'i' de la serie de Fibonacci */
	
	/*
	Código
	*/
}

void printAll(/* *{argumentos} */){
	cout << "Calculados: ";
	for(int i = 0; i< N_C && calculados[i] != -1; i++)
		cout << fixed << calculados[i] << " ";
	cout << '\n';
}
