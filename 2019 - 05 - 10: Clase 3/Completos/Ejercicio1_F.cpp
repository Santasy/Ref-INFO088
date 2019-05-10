#include <iostream>
/* Para usuarios de Windows:
#include <cstdlib>
#include <ctime>
/**/

using namespace std;

typedef struct ficha{
	/*---Datos de la ficha---*/
	int id; //Valor de identificación
	int largo; // Cantidad de valores del arreglo
	int *valores = nullptr; // Lista de valores aleatorios
	float prom; // Promedio de los valores 
	int n_max; // Número mayor dentro de la lista
	int n_min; // Número menor dentro de la lista
	int rep_v; // Valor de número más repetido en la lista
	int rep_c; // Cantidad de veces repetidas

	/*---Enlace a siguiente---*/
	ficha *next = nullptr;

	/*:::::Funciones de la estructura:::::*/
	void genFicha(int _id, int l);
	void printFicha();
};

void genFichas(ficha **head, int n, int inc);
void printFichas(ficha *it);

int main(int argc, char **argv){
	// No debe modificar el main.
	srand(time(NULL));
	/*---Setup---*/
	if(argc != 3){
		cout << "Error. Debe ejecutar {./ej1 n inc}\n";
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
	int inc = atoi(argv[2]);

	if(n <= 0 || inc <= 0){
		cout << "Error. 'n' y 'inc' deben ser positivos.\n";
		exit(EXIT_FAILURE);
	}

	/*---Funcionamiento---*/
	ficha *fichas = nullptr; // Cabeza de las estructuras
	genFichas(&fichas, n, inc);
	printFichas(fichas);

	/*---Término---*/
	return 0;
}

void genFichas(ficha **head, int n, int inc){
	/*:::::Función que genera todas las fichas, y las guarda a la derecha de la cabeza:::::*/
	ficha *ultima = *head;
	for(int i = 1; i <= n; ++i){
		ficha *nueva = new ficha;
		nueva->genFicha(i, i * inc);

		if(ultima == nullptr){
			*head = ultima = nueva;
		}else{
			ultima->next = nueva;
			ultima = nueva;
		}
	}
}

void printFichas(ficha *it){
	/*:::::Función que llama a la impresión de los datos de cada ficha:::::*/
	while(it != nullptr){
		it->printFicha();
		it = it->next;
	}
}

void ficha::genFicha(int _id, int l){
	/*:::::Funcion que generará y calculará los atributos de la ficha:::::*/

	/* Referencia de atributos:
		int id; //Valor de identificación
		int largo; // Cantidad de valores del arreglo
		int *valores = nullptr; // Lista de valores aleatorios
		float prom; // Promedio de los valores 
		int n_max; // Número mayor dentro de la lista
		int n_min; // Número menor dentro de la lista
		int rep_v; // Valor de número más repetido en la lista
		int rep_c; // Cantidad de veces repetidas
	*/

	id = _id;
	largo = l;
	valores = new int[largo];
	prom = 0.0;
	rep_c = 0;
	// Para max y min, se asignarán las cotas (valores que NUNCA tomará nuestro random).
	n_max = -1; 
	n_min = 100;
	for(int i = 0; i < l; i++){
		valores[i] = random() % 100;
		prom += (float) valores[i];
		if(valores[i] < n_min) n_min = valores[i];
		if(valores[i] > n_max) n_max = valores[i];
	}
	prom /= (float) largo;

	/*---Cálculo de repeticiones---*/
	// Observaciones:
	// Se hará un algoritmo bruto, donde es posible buscar en toda la lista un número ya buscado.
	// De encontrar dos números repetidos la misma cantidad de veces, mantendrá el primero que encontró.
	for(int a = 0; a < largo; ++a){
		int rep = 0;
		for(int b = 0; b < largo; ++b)
			if(valores[a] == valores[b]) ++rep;
		if(rep > rep_c){
			rep_c = rep;
			rep_v = valores[a];
		}
	}
	cout << "Generada ficha " << id << " con éxito.\n";
}

void ficha::printFicha(){
	/*:::::Función que imprime cada atributo de la ficha correpondiente.:::::*/
	cout << "Ficha " << id << ", " << largo << " valores:\n";
	cout << "Lista de valores: ";
	for(int i = 0; i < largo; ++i)
		cout << valores[i] << " ";
	cout << '\n';
	cout << "Promedio de valores:        " << prom << '\n';
	cout << "Número máximo encontrado:   " << n_max << '\n';
	cout << "Número mínimo encontrado:   " << n_min << '\n';
	cout << "Número más repetido:        " << rep_v << '\n';
	cout << "Cantidad de veces repetido: " << rep_c << "\n\n";
}
