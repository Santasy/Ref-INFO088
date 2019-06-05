#ifndef COLA_H
#define COLA_H

class Cola{
public:
	
	/* Sub-estructura */
	typedef struct nodoCola{
		
		char c;
		nodoCola *next = nullptr;
	};
	nodoCola
		*root = nullptr,
		*back = nullptr
	;

	/* Funciones */
	Cola();
	void toBack(char c); 			// Añade carácteres
	void toBack(char *lista);	// Añade lista de carácteres
	bool isEmpty();						// Cola vacía
	char front(); 			 			// Obtiene frente
	void print();							// Imprime los valores en la Cola
};

#endif // COLA_H