#include <iostream>
#include <cmath>
#include "nodoArbol.h"

/*:::::Definiciones:::::*/

using namespace std;

void nodoArbol::addNum(int v){
	//printf("Añadiendo |%d|\n", v);
	/* Función que añadirá el nuevo valor al árbol */
	nodo *nuevo;
		// Caso para cabeza vacía:
	if(root == nullptr){
		nuevo = new nodo(v);
		root = nuevo;
		return;
	}
	/* 	
			|
			| Código
			|
	*/
}

void nodoArbol::printArbol(nodo *n, int *col){
	/* 	
			|
			| Código
			|
	*/
}

void nodoArbol::printArbol(){
	int col = 0;
	if(root != nullptr) printArbol(root, &col);
	cout << '\n';
}

void nodoArbol::genSumadores(int v, int *s_1, int *s_2){
	/*:::::Función que genera dos números diferentes, cuya suma es 'v':::::*/
	*s_1 = floor(v / 2.0);
	(*s_2) = (*s_1) + 1;
	if((*s_1) * 2 == v){
		--(*s_1);
	}
}

nodoArbol::nodo::nodo(int _v){
	v = _v;
}

/*::::::::::*/