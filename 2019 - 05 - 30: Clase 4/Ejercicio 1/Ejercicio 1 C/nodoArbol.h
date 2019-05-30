#ifndef NODOARBOL_H
#define NODOARBOL_H

/*:::::Clase nodoArbol:::::*/
class nodoArbol{
		/* Sub-estructura */
	typedef struct nodo{
		int
			v,			// Valor del nodo
			rep = 1 // Número de repeticiones
		;

		nodo
			*izq = nullptr, // Enlace hacia la izquierda
			*der = nullptr	// Enlace hacia la derecha
		;
	public:
		nodo(int _v);
	};

		/* Atributos: */
	nodo *root = nullptr; // Cabeza del árbol
	
public:
		/* Funciones */
	void addNum(int v);
	void genSumadores(int v, int *s_1, int *s_2);
	void printArbol(nodo *n, int *col);
	void printArbol();
};
/*::::::::::*/

#endif // NODOARBOL_H