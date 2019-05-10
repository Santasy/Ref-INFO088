#include <iostream>
/* Para usuarios de Windows:
#include <cstdlib>
#include <ctime>
/**/

using namespace std;

typedef struct nodo{
	int id = 0;
	nodo *next = nullptr;
	nodo *prev = nullptr;
};

int popNum(int *rest, int n);

int main(int argc, char **argv){
	if(argc != 2){
		cout << "Error. Debe ejecutar {./ej2 n}.\n";
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
	if(n <= 0){
		cout << "Error. 'n' debe ser positivo.\n";
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));

	nodo *nodosRAW = new nodo[n];
	int rest_l = n - 1;
	int *restantes = new int[rest_l];
	
	// Hacia la derecha
	for(int i = 1; i < n; ++i){
		nodosRAW[i].id = i;
		restantes[i-1] = i;
	}

	nodo *it = nodosRAW;
	while(rest_l > 0){
		int indice = popNum(restantes, rest_l);
		it->next = &nodosRAW[indice];
		it = &nodosRAW[indice];
		--rest_l;
	}

	// Hacia la izquierda
	rest_l = n - 1;
	restantes = new int[rest_l];
	int comp = 0;
	for(int i = 0; i < n; ++i){
		if(i == it->id){
			++comp;
			continue;
		}
		restantes[i - comp] = i;
	}
	
	while(rest_l > 0){
		int indice = popNum(restantes, rest_l);
		it->prev = &nodosRAW[indice];
		it = &nodosRAW[indice];
		--rest_l;
	}

	// Orden final
	it = nodosRAW;
	cout << "Orden hacia la derecha:\n";
	while(it->next != nullptr){
		cout << it->id << " ";
		it = it->next;
	}
	cout << it->id << '\n';

	cout << "Orden hacia la izquierda:\n";
	while(it->prev != nullptr){
		cout << it->id << " ";
		it = it->prev;
	}
	cout << it->id << '\n';

	return 0;
}

int popNum(int *rest, int n){
	int indice = random() % n;
	int num = rest[indice];
	for(int i = indice; i < n - 1; ++i){
		rest[i] = rest[i + 1];
	}
	return num;
}