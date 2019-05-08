#include <iostream>
/* Para usuarios de Windows:
#include <cstdlib>
#include <ctime>
*/
using namespace std;

struct nodoRAW{
	// Para evitar otro tipo de errores que ya conocemos sobre el ruido en variables SOLAMENTE DEFINIDAS,
	// las inicializamos con valores default según corresponda.
	// Es importante notar que, de esta manera, TODO 'nodoRAW' que declaremos, 
	// al inicio SIEMPRE tendrá 'v = 0', y su puntero referenciará a NULL (ó nullptr).

	// Las varibles de una estructura son llamadas 'atributos'. 
	int v = 0;
	nodoRAW *next = nullptr; // A esta utilización de puntero se le conoce como 'Self-Reference' (autoreferencia).
};
// Hasta este punto, C++ no sabe diferenciar 'nodoRAW' de una posible función 'nodoRAW()',
// por lo que su uso no dará directamente a un error.
// Sin embargo, esto puede dar paso a un sinfín de bugs, por lo que 'typedef' es una solución viable y coherente.

/*-----¡Pruébalo!-----*/
/* // PD: Debes borrar los dos primeros carácteres de esta línea para descomentar todo lo que hay hacia abajo. 
void nodoRAW(){
	cout << "Llamado a función.\n";
}

int main(){
	struct nodoRAW n1; // La manera formal (des-ambiguada) de declarar un nodo será ésta.
	cout << n1.v << '\n';
	nodoRAW();
	return 0;
}
/*-----Fin de Prueba-----*/

/*
*/ // PD: Debes borrar los dos primeros carácteres de esta línea para comentar todo lo que hay hacia abajo. 

// ------------
// Continuamos:

typedef nodoRAW nodo; 
// De esta manera, nuestro struct se combierte, en pocas palabras, en un tipo de dato.
// Es decir, será similar a declarar una variable 'int var',
// pero ocuparemos nuestro propio tipo: 'nodo var'.

// Explicaré estas funciones más abajo.
void agregarNodos(nodo **head, int *valores, int cant);
void imprimirNodos(nodo *iterador);

int main(){
	srand(time(NULL));

	nodo normal; // Aquí, el nodo ya fue creado con sus valores default.
	cout << "Valor de normal: " << normal.v << "\n\n"; // Es decir, podemos imprimir sus atributos.
	// Observar que, al ser una variable sin puntero,
	// para modificar o obtener sus atributos, se debe acceder a ellos de la forma: '{estructura}.{atributo}' (con un punto).

	// Ruido con punteros:
	nodo *n_ptr;
	if(n_ptr == nullptr){
		cout << "Observar que un puntero, al igual que otras variables, no está declarado, por lo que solo será ruido.\n";
		cout << "Por lo que es posible que estas salidas no se impriman en consola.\n";
	}
	n_ptr = nullptr;
	if(n_ptr == nullptr)
		cout << "Para evitar bugs, es útil asegurarse que es iniciado con un valor nulo.\n\n";

	// Como listas:
	int cant = 5, i; // : cantidad de nodos, iterador.
	nodo *lista = new nodo[cant]; // Al igual que otro tipo de datos, podemos crear una lista de nodos, referenciados con un puntero.
	cout << "Lista inicializada:\n";
	for(i = 0; i < cant; ++i){
		// 'new nodo[cant]', además de asignar la memoria correspondiente, equivale a hacer 'cant' declaraciones normales,
		// por lo que es posible imprimir sus valores:
		cout << lista[i].v << ' ';
		lista[i].v = 10 + rand() % 89;
	}
	cout << '\n';

	// También:
	cout << "Lista con valores random:\n";
	for(i = 0; i < cant; ++i)
		cout << (lista + i)->v << ' '; // Observar que, al tratarse de un puntero, para referirse a sus atributos se ocupa '->'.
	cout << "\n\n";

	// Ahora, entendamos un poco de direcciones:
	cout << "Direcciones:\n";
	cout << "Dirección de normal:           " << &normal << '\n';
	n_ptr = &normal;
	cout << "Dirección guardada en puntero: " << n_ptr << '\n';
	cout << "Dirección propia del puntero:  " << &n_ptr << "\n\n"; //Observar que el puntero, per se, tiene otra dirección.
	// Es por ésto que al querer modificar un puntero dentro de una función debe entregar la dirección del puntero: {&puntero}.

	// Creando e imprimiendo nodos:
	nodo *head = nullptr;
	int *valores = new int[5]{10, 20, 30, 40, 50};
	imprimirNodos(head);
	agregarNodos(&head, valores, 5); // Observar que se pasó la dirección del puntero: {&head}.
	imprimirNodos(head); // Como en esta función no se modifican valores, solo se pasa el puntero.
	valores = new int[4]{1, 2, 3, 4};
	agregarNodos(&head, valores, 4);
	imprimirNodos(head);
	return 0;
}

void agregarNodos(nodo **head, int *valores, int cant){
	//:::::Función que agrega todos los números en la lista 'valores', a la derecha de 'head':::::
	nodo *ultimo = *head; // Para evitar buscar el último nodo todas las veces, lo mantendremos a mano.
	// Buscaremos el último:
	while(ultimo != nullptr && ultimo->next != nullptr)
		ultimo = ultimo->next;

	for(int i = 0; i < cant; ++i){
		nodo *nuevo = new nodo; // Ya que es un puntero, debe declarse explícitamente de la forma 'new nodo'.
		nuevo->v = valores[i];
		
		if(ultimo == nullptr){ // Implicará que '*head == nullptr', por lo que se guardará el nuevo nodo como 'head'.
			*head = ultimo = nuevo; // Asignación multiple: == {'*head = nuevo'; ultimo = nuevo;}
		}else{ //De no ser así, se enlaza con el último.
			ultimo->next = nuevo;
			ultimo = nuevo;
		}
	}
}

void imprimirNodos(nodo *iterador){
	//:::::Función que imprime todos los valores de la serie de nodos enlazadas a 'head':::::
	
	// Como solo se pasó la dirección del primer nodo, y modificarla no afectará fuera de esta función, se ocupará de iterador
	cout << "Valores de nodos:\n";
	while(iterador != nullptr){
		cout << iterador->v << ' ';
		iterador = iterador->next;
	}
	cout << "|nullptr\n\n";
}

/**/