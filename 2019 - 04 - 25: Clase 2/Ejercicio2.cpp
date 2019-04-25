#include <iostream>
/* Para usuarios de Windows:
#include <ctime>
#include <stdlib.h>
*/

using namespace std;

#define N_C 100 //N�mero de c�lculos a almacenar

/*{ retorno} */ void fibonacci(/* *{argumentos} */);
void printAll(/* *{argumentos} */);

int main(int argc, char **argv){
	srand(time(NULL));
	cout.precision(0); // Fija la cantidad de indices decimales a imprimir a trav�s de std::cout a 0, asegurando que el n�mero entero imprima todos sus d�gitos.
	// Para que funcione, se debe entregar '<< fixed' antes de entregar el n�mero '<< n'
	
	int calculos = 0; // Contador de c�lculos necesitados durante la ejecuci�n del programa
	/*{tipo}*/ *calculados = new /*{tipo}*/[N_C]{0, 1, 1}; // Nos ahorramos los primeros c�lculos, que son un poco m�s tedioso de generar.
	
	// Esta es una t�cnica l�gica simple, que nos permiten crear condiciones para el avance de nuestro programa
	for(int i = 3; i < N_C; i++) calculados[i] = -1; // Definimos que si la casilla contiene un '-1', significar� que el valor no ha sido calculado.
	
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
	/* Funci�n que entrega el n�mero en �ndice 'i' de la serie de Fibonacci */
	
	/*
	C�digo
	*/
}

void printAll(/* *{argumentos} */){
	cout << "Calculados: ";
	for(int i = 0; i< N_C && calculados[i] != -1; i++)
		cout << fixed << calculados[i] << " ";
	cout << '\n';
}
