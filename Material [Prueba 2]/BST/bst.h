#ifndef BST_H
#define BST_H

class bst{
// (protected:) por defecto
	typedef struct nBST{
		int val;
		nBST 
			*izq = nullptr,
			*der = nullptr;
	};

	nBST **root = nullptr;
public:
	bst();
	~bst(); // Para eliminar el árbol
	bool searchVal(int val);
	nBST *searchNode(int val); // Retorna un puntero
	bool insertVal(int val);
	bool deleteval(int val);
	
	/* Impresión: */
	void preOroot();
	void inOroot();
	void postOroot();

	void preO(nBST *nodo);
	void inO(nBST *nodo);
	void postO(nBST *nodo);
};

#endif // BST_H