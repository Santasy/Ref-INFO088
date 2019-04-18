#include <iostream>
/* Para usuarios de Windows:
#include <ctime> //: time()
#include <stdlib.h> //: rand(), srand()
*/

using namespace std;

#define N_V 10 // Número de valores

void quickSort(int *, int, int, int *); // Esta forma de declarar funciones es válida para c++
void impLista(int *); // Solo se declara el tipo de dato de entrada, para posteriormente declararla con nombres.
// NO ES UNA BUENA PRÁCTICA. Siempre es bueno de antemano saber qué entra y sale de una función. Pero funciona.

int main(int argc, char **argv){
	srand(time(NULL));
	
	/* Genero valores */
	int *valores = new int[N_V];
	for(int i = 0; i < N_V; i++) valores[i] = 1 + rand() % 100;
	
	int intercambios = 0;

	/* Llamo a funciones */
	impLista(valores); // Original
	quickSort(valores, 0, N_V - 1, &intercambios);
	impLista(valores); // Modificado

	cout << "Logrado en " << intercambios << " intercambio(s).\n";
	return 0;
}

void quickSort(int *v, int i, int f, int *intercambios){
	/* Funcion que ordenara de forma ascendente un arreglo */
	/* Acepta números repetidos */
	
	// La ténica a utilizar será un pivoteo trivial, es decir:
	// - Escoger un número aleatorio de la lista
	// - Intercambiar los valores hasta que a la izquierda del pivote solo hayan números menores que él
	// - Intercambiar los valores hasta que a la derecha del pivote solo hayan números mayores que él
	
	int piv = (f + i) / 2; // Posición del pivote: Mitad del arreglo
	int piv_v = v[piv]; // Valor del pivote
	int x = i, y = f; // Iteradores: izquierda y derecha
	int aux; // Variable de intercambio
	cout << "Orden entre " << i << " y " << f << " | piv: " << piv << '\n';

	// Termina cuando los dos iteradores se ubican en la misma posición, el pivote.
	while(x != y){
		cout << x << "  -  " << y << '\n';
		// Se buscan valores que debieran cambiarse, y de no encontrar, se ubica en el pivote.
		while(v[x] <= piv_v && x < piv) x++; // Encuentra algún número mayor por la izquierda del pivote.
		while(v[y] >= piv_v && y > piv) y--; // Encuentra algún número menor por la derecha del pivote.
		cout << x << " --- " << y << '\n';
		// Si aún no se encuentran (condición de término), se intercambian las posiciones
		if(x != y){
			// Se intercambian los valores
			aux = v[x];
			v[x] = v[y];
			v[y] = aux;
			// Si se movio el pivote, actualiza su posicion
			if(x == piv) //Si x era el pivote, se intercambió con la posicion y
				piv = y;
			else if(y == piv) //Si y era el pivote, se intercambió con la posicion x
				piv = x;
			cout << "Cambio entre " << x << " y " << y << " | piv: " << piv << '\n';
			
			(*intercambios)++;
		}
	}
	cout << '\n';
	// Ajusta ambos lados (derecho y izquierdo) recursivamente
	// Referencia: {i .. (piv-1)}_____{piv}______{(piv+1) .. f}
	if(piv - 1 > i && piv != 0) //Asegura el largo de la lista, y no salirse de ésta por la izquierda
		quickSort(v, i, piv - 1, intercambios);
	if(piv + 1 < f && piv != N_V - 1) //Asegura el largo de la lista, y no salirse de ésta por la derecha
		quickSort(v, piv + 1, f, intercambios);
	// En caso de encontrar una sub-lista de largo 0 o 1, no se llama nuevamente a la función.
	// La lógica del programa asegura que, de ser el caso anterior, el número ya ha encontrado su casilla final.
}

void impLista(int *v){
	cout << "Lista: ";
	for(int i = 0; i < N_V; i++){
		cout << v[i] << " ";
	}
	cout << '\n';
}
