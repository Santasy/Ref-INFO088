#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila(){}

void Pila::toTop(int v){
	nodoPila *nuevo = new nodoPila();
	nuevo->v = v;
	// Dos casos:
	if(top == nullptr){	// Pila vacía
		top = nuevo;
		return;
	}

	// Pila no vacía
	nuevo->prev = top;
	top = nuevo;
}

bool Pila::isEmpty(){
	return (top == nullptr);
}

int Pila::pop(){
	if(isEmpty()){
		return -1;
	}

	int val = top->v;
	top = top->prev;
	return val;
}

void Pila::print(){
	if(isEmpty()){
		printf("Pila vacía.\n");
		return;
	}

	printf("Pila: <-");
	nodoPila *it = top;
	while(it != nullptr){
		printf("%d ", it->v);
		it = it->prev;
	}
	printf("]\n");
}

int Pila::size(){
	int size = 0;
	nodoPila *it = top;
	while(it != nullptr){
		++size;
		it = it->prev;
	}
	return size;
}