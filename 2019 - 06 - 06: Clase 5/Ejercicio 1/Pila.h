#ifndef PILA_H
#define PILA_H

class Pila{
public:

	/* Sub-estructura */
	typedef struct nodoPila{
		int v;
		nodoPila *prev;
	};
	nodoPila *top = nullptr;

	/* Funciones */
	Pila();
	void toTop(int v); 	// Añade valor
	bool isEmpty();			// Pila vacía
	int pop();					// Obtiene valor de top
	void print();				// Imprime los valores en la Pila
	int size();					// Retorna la cantidad de elementos de la Pila
};

#endif // PILA_H