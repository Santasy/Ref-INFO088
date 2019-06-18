#ifndef BST_H
#define BST_H

class bst{
// (protected:) por defecto
	typedef struct nBST{
		// Esta estructura solo existe dentro de esta clase.
		// Si estuviera en public, se podría referenciar como:
		//		bst::nBST *{var};

		int val;
		nBST 
			*izq = nullptr,
			*der = nullptr;
	};

	nBST **root = nullptr; // Cabeza
		// No pueden ser llamadas por el usuario:
	void preO(nBST *nodo);
	void inO(nBST *nodo);
	void postO(nBST *nodo);
public:
	bst();	// Constructor
	~bst(); // Destructor: Para eliminar el árbol
	bool searchVal(int val);
	nBST *searchNode(int val); // Retorna un puntero
	bool insertVal(int val);
	bool deleteVal(int val);
	
	/* Impresión: */
	void preOroot();
	void inOroot();
	void postOroot();
};

#endif // BST_H
