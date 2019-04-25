#include <iostream>
#include <ctime>
#include <stdlib.h>

#define DIM 10 // Macros: Toda aparici�n de 'DIM' en nuestro c�digo, ser� reemplazada al compilar por el valor que le asignamos
using namespace std;

// Se DECLARAN qu� funciones integrar� nuestro c�digo. No es necesario DEFINIRLAS directamente, pero s� declararlas antes del llamado a la funci�n 'int main()'
void impLista(auto *, int); // Esta declaraci�n es v�lida en C++, donde solo se especifica los tipos de dato de entrada, para posteriormente declarar los nombres en la definici�n de la funci�n

int main(int argc, char **argv){
	srand(time(NULL));
	
	/* Punteros */
	int *p; // Un puntero '{tipo} *{nombre_var}' ser� una direcci�n de memoria, donde es posible asignar un valor de espacio {sizeof(tipo)}
	// Generalmente se ocupar� para apuntar a una lista, o m�s bien a una casilla (posici�n) de �sta
	p = new int[DIM]; // Esta asignaci�n le dice a la m�quina que, asigne a 'p' una direcci�n donde los 'DIM' espacios contiguos no son ocupados por otras variables
	cout << "Valores con \"ruido\"\n"; // Anteponer un '\' nos permitir� ocupar car�cteres dentro de un string que cumplen funciones especiales. En este caso, permite agregar comillas sin que el string se desarme
	impLista(p, DIM);
	
	p = new int[(int) (DIM / 2)]; // Dentro de '[]', se debe asegurar entregar un valor entero que permita una asignaci�n de memoria v�lida. Para �sto, se ocupa un simple casting
	// Observar que se le fue asignado otro espacio de memoria, diferente al que ya ten�a (a pesar de que la nueva lista tiene dimensi�n menor a la anterior), donde solo necesitamos (DIM / 2) casillas contiguas disponibles 
	for(int i = 0; i < DIM / 2; ++i){
		p[i] = (i + 1) * 10;
	}
	impLista(p, DIM); // Observe que se imprimi� fuera de la lista adrede
	
	// Tambi�n, se puede recorrer linealmente memoria, permitiendo acceder a {mem + 1} � {mem - 1}
	// Esto permite cosas como:
	cout << (p + 2)[-1] << "\n\n";
	// Donde (p + 2) ser�a la posici�n p[2] = 30
	// Y [-1] nos permitir�a acceder a la posici�n anterior: p[1] = 20
	
	// Observar que con p[i] accedemos al valor i desde la direcci�n p, pero tambi�n podemos obtener su direcci�n con '&':
	cout << &(p[1]) << "\n\n"; //Esto tiene un formato hexadecimal
	
	/* Con todo �sto, podemos generalizar que:
		- Para tipos de n�meros, {tipo} *{nombre_var} ser� una lista de n�meros
		- Para char, char *{nombre_var} ser� abstractamente una palabra. Ej: "hola", con {nombre_var}[1] = 'o'
	*/
	// Es posible:
	int *numeros = new int[DIM]{1, 2, 3}; // Inicializar una lista de n�meros, con algunos valores, asignados desde su inicio (izquierda)
	impLista(numeros, DIM);
	const char *palabra = "hola"; // Inicializar una lista de char como asignaci�n de un string. �sto solo es posible declarando la variable como 'const'.
	cout << (palabra + 1) << '\n'; // Imprimir una palabra desde posici�n i (i = 1 para estes caso)
	char *palabra2 = new char[DIM]{'t', 'e', 's', 't'}; // Inicializar una palabra con algunas letras
	cout << palabra2 << "\n\n";
	
	/* Punteros dobles */
	
	int **matrix; // De la misma manera, un doble puntero indicar� que la estructura es similar a una "lista de listas". Para n�meros, se relacionar� con una matriz
	matrix = new int*[3]; // Se asigna su dimensi�n m�s externa primero. En este caso, nos referiremos a las filas.
	// Es decir, cada fila contendr� su propia lista, sus columnas, por lo tanto ser� una direcci�n que apunta a otra direcci�n, que en s� es una lista de n�meros.
	cout << "Matriz:\n";
	for(int j = 0; j < 3; ++j){ 
 		matrix[j] = new int[3]; // Luego, para cada fila, se crean sus columnas
 		for(int i = 0; i < 3; ++i){
 			//Para acceder a una lista de esta estructura, primero se accede a su dimensi�n m�s general (exterior), en este caso las filas 'j', y luego a su dimensi�n m�s anidada, en este caso, columnas 'i'
 			matrix[j][i] = j * 3 + (i + 1); // F�rmula b�sica que enumera desde 1 hasta 9, recorriendo primero las columnas, y luego las filas.
 			cout << matrix[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
	char ***sopa; // Similar a lo anterior, un puntero triple de char har� referencia a una matriz de palabras, pues una palabra es una lista, y por cada fila existen sus columnas correspondientes.
	sopa = new char**[3]; // Filas
	cout << "Sopa de letras:\n";
	for(int j = 0; j < 3; ++j){
		sopa[j] = new char*[3]; // Columnas
		for(int i = 0; i < 3; ++i){
			sopa[j][i] = new char[4]{'t', 'e', 's', 't'}; //Largo de la palabra, iniciada con 'test'
			cout << sopa[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << "\n\n";
	return 0;
}

void impLista(auto *l, int n){ // El tipo 'auto' determinar� por si solo qu� tipo de dato necesita utilizar para la asignaci�n
	cout << "Lista:\n";
	for(int i = 0; i < n; ++i){
		cout << l[i] << ' ';
	}
	cout << "\n\n";
}
