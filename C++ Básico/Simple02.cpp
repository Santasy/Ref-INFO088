#include <iostream>
#include <ctime>
#include <stdlib.h>

#define DIM 10 // Macros: Toda aparición de 'DIM' en nuestro código, será reemplazada al compilar por el valor que le asignamos
using namespace std;

// Se DECLARAN qué funciones integrará nuestro código. No es necesario DEFINIRLAS directamente, pero sí declararlas antes del llamado a la función 'int main()'
void impLista(auto *, int); // Esta declaración es válida en C++, donde solo se especifica los tipos de dato de entrada, para posteriormente declarar los nombres en la definición de la función

int main(int argc, char **argv){
	srand(time(NULL));
	
	/* Punteros */
	int *p; // Un puntero '{tipo} *{nombre_var}' será una dirección de memoria, donde es posible asignar un valor de espacio {sizeof(tipo)}
	// Generalmente se ocupará para apuntar a una lista, o más bien a una casilla (posición) de ésta
	p = new int[DIM]; // Esta asignación le dice a la máquina que, asigne a 'p' una dirección donde los 'DIM' espacios contiguos no son ocupados por otras variables
	cout << "Valores con \"ruido\"\n"; // Anteponer un '\' nos permitirá ocupar carácteres dentro de un string que cumplen funciones especiales. En este caso, permite agregar comillas sin que el string se desarme
	impLista(p, DIM);
	
	p = new int[(int) (DIM / 2)]; // Dentro de '[]', se debe asegurar entregar un valor entero que permita una asignación de memoria válida. Para ésto, se ocupa un simple casting
	// Observar que se le fue asignado otro espacio de memoria, diferente al que ya tenía (a pesar de que la nueva lista tiene dimensión menor a la anterior), donde solo necesitamos (DIM / 2) casillas contiguas disponibles 
	for(int i = 0; i < DIM / 2; ++i){
		p[i] = (i + 1) * 10;
	}
	impLista(p, DIM); // Observe que se imprimió fuera de la lista adrede
	
	// También, se puede recorrer linealmente memoria, permitiendo acceder a {mem + 1} ó {mem - 1}
	// Esto permite cosas como:
	cout << (p + 2)[-1] << "\n\n";
	// Donde (p + 2) sería la posición p[2] = 30
	// Y [-1] nos permitiría acceder a la posición anterior: p[1] = 20
	
	// Observar que con p[i] accedemos al valor i desde la dirección p, pero también podemos obtener su dirección con '&':
	cout << &(p[1]) << "\n\n"; //Esto tiene un formato hexadecimal
	
	/* Con todo ésto, podemos generalizar que:
		- Para tipos de números, {tipo} *{nombre_var} será una lista de números
		- Para char, char *{nombre_var} será abstractamente una palabra. Ej: "hola", con {nombre_var}[1] = 'o'
	*/
	// Es posible:
	int *numeros = new int[DIM]{1, 2, 3}; // Inicializar una lista de números, con algunos valores, asignados desde su inicio (izquierda)
	impLista(numeros, DIM);
	const char *palabra = "hola"; // Inicializar una lista de char como asignación de un string. Ésto solo es posible declarando la variable como 'const'.
	cout << (palabra + 1) << '\n'; // Imprimir una palabra desde posición i (i = 1 para estes caso)
	char *palabra2 = new char[DIM]{'t', 'e', 's', 't'}; // Inicializar una palabra con algunas letras
	cout << palabra2 << "\n\n";
	
	/* Punteros dobles */
	
	int **matrix; // De la misma manera, un doble puntero indicará que la estructura es similar a una "lista de listas". Para números, se relacionará con una matriz
	matrix = new int*[3]; // Se asigna su dimensión más externa primero. En este caso, nos referiremos a las filas.
	// Es decir, cada fila contendrá su propia lista, sus columnas, por lo tanto será una dirección que apunta a otra dirección, que en sí es una lista de números.
	cout << "Matriz:\n";
	for(int j = 0; j < 3; ++j){ 
 		matrix[j] = new int[3]; // Luego, para cada fila, se crean sus columnas
 		for(int i = 0; i < 3; ++i){
 			//Para acceder a una lista de esta estructura, primero se accede a su dimensión más general (exterior), en este caso las filas 'j', y luego a su dimensión más anidada, en este caso, columnas 'i'
 			matrix[j][i] = j * 3 + (i + 1); // Fórmula básica que enumera desde 1 hasta 9, recorriendo primero las columnas, y luego las filas.
 			cout << matrix[j][i] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
	char ***sopa; // Similar a lo anterior, un puntero triple de char hará referencia a una matriz de palabras, pues una palabra es una lista, y por cada fila existen sus columnas correspondientes.
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

void impLista(auto *l, int n){ // El tipo 'auto' determinará por si solo qué tipo de dato necesita utilizar para la asignación
	cout << "Lista:\n";
	for(int i = 0; i < n; ++i){
		cout << l[i] << ' ';
	}
	cout << "\n\n";
}
