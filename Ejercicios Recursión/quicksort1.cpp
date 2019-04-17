#include <iostream>

using namespace std;

#define N_V 10

void quickSort(int *, int, int);
void impLista(int *);

int main(int argc, char **argv){
	srand(time(NULL));
	
	/* Genero valores */
	int *valores = new int[N_V];
	for(int i = 0; i < N_V; i++) valores[i] = 1 + rand() % 100;

	/* Llamo a funciones */
	impLista(valores);
	quickSort(valores, 0, N_V - 1);
	impLista(valores);

	return 0;
}

void quickSort(int *v, int i, int f){
	/* Funcion que ordenara de forma ascendente un arreglo */
	
	int piv = (f + i) / 2; // Posición del pivote
	int piv_v = v[piv]; // Valor del pivote
	int x = i, y = f; // Iteradores
	int aux; // Variable de intercambio
	cout << "Orden entre " << i << " y " << f << "| piv: " << piv << '\n';

	// Ajusta el arreglo, de manera que a la izquierda del pivote sean números menores que él, y a la derecha mayores
	while(x != y){
		cout << x << "  -  " << y << '\n';
		while(v[x] <= piv_v && x < piv) x++; // Encuentra algún número mayor por la izquierda del pivote
		while(v[y] >= piv_v && y > piv) y--; // Encuentra algún número menor por la derecha del pivote
		cout << x << " --- " << y << '\n';
		// Si aún no se encuentran (condición de término), se intercambian las posiciones
		if(x != y){
			// Se intercambian los valores
			aux = v[x];
			v[x] = v[y];
			v[y] = aux;
			// Si se movio el pivote, actualiza su posicion
			if(x == piv) //Si x era el pivote, se intercambio con la posicion y
				piv = y;
			else if(y == piv) //Si y era el pivote, se intercambio con la posicion x
				piv = x;
			cout << "Cambio entre " << x << " y " << y << "| piv: " << piv << '\n';
		}
	}
	cout << '\n';
	// Ajusta ambos lados (derecho y izquierdo) recursivamente
	// Referencia: {i .. (piv-1)}_____{piv}______{(piv+1) .. f}
	if(piv - 1 > i && piv != 0) quickSort(v, i, piv - 1);
	if(piv + 1 < f && piv != N_V - 1) quickSort(v, piv + 1, f);
}

void impLista(int *v){
	cout << "Lista: ";
	for(int i = 0; i < N_V; i++){
		cout << v[i] << " ";
	}
	cout << '\n';
}