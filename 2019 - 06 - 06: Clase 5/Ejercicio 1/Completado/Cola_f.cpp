#include "Cola.h"
#include <iostream>

using namespace std;

Cola::Cola(){}

void Cola::toBack(char c){
	nodoCola *nuevo = new nodoCola();
	nuevo->c = c;
	
	// Cola vacía
	if(root == nullptr){
		root = back = nuevo;
		return;
	}

	back->next = nuevo;
	back = nuevo;
}

void Cola::toBack(char *lista){
	while((int) lista[0] != 0){
		toBack(lista[0]);
		++lista;
	}
}

bool Cola::isEmpty(){
	return (root == nullptr);
}

char Cola::front(){
	if(!isEmpty()){
		char c = root->c;
		// Dos casos:
		if(root == back){ // Solo había un nodo
			root = back = nullptr;
		}else{ 						// Existen varios nodos
			root = root->next;
		}

		return c;
	}
	return ((char) 0);
}

void Cola::print(){
	if(isEmpty()){
		printf("Cola vacía.\n");
		return;
	}

	nodoCola *it = root;
	printf("Cola: <-");
	while(it != nullptr){
		printf("%c ", it->c);
		it = it->next;
	}
	printf("<-\n");
}