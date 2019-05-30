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
		// Se busca el último posible padre:
	nodo *it = root; // Se copia la cabeza del árbol
	while(
		(v < it->v && it->izq != nullptr) || 
		(v > it->v && it->der != nullptr)
	){
		if(v < it->v)
			it = it->izq;
		else 
			it = it->der;
	}
		// Se agrega el nuevo valor:
			// - Si es que el valor es 1 ó 2
	if(it->v == v && v <= 2){
		++(it->rep);
		return;
	}
			// - Número repetido
	if(it->v == v){
		int sum_1, sum_2;
		genSumadores(v, &sum_1, &sum_2);
		addNum(sum_1);
		addNum(sum_2);
		return;
	}
			// - Cualquier otro caso: Número nuevo
	nuevo = new nodo(v);
	if(v < it->v)
		it->izq = nuevo;
	else
		it->der = nuevo;
}

void nodoArbol::printArbol(nodo *n, int *col){
	if(n->izq != nullptr){
		printArbol(n->izq, col);
	}
	if(n->v <= 2){
		cout << '(' << n->rep << ')';
	}
	cout << n->v << " ";
	if(*col == 4){ // Cada 5 nodos
		cout << '\n';
		*col = -1;
	}
	++(*col);
	if(n->der != nullptr){
		printArbol(n->der, col);
	}
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