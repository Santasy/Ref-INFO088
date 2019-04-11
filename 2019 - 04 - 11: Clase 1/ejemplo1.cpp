/*-----Contador de vocales y consonantes-----*/
#include <iostream>

using namespace std;

#define N_P 10 // Palabras
#define N_C 20 // Caracteres

const char *vocales;

void genPalabras(char **palabras);
void contar(char *pointer, int *c_voc, int *c_con);
void printResults(int *c_voc, int *c_con);

int main(int argc, char **argv){
	srand(time(NULL));

	/* Definiciones */
	char **palabras = new char*[N_P];
	genPalabras(palabras);
	/*      Referencia:
			palabras = {dir hex}: 0x55c1c1fdbe70
			*palabras = {palabra}: ajelsidje
			**palabras = {caracter}: a
	*/
	
	char *pointer = *palabras;
	int *c_voc = new int[N_P],
			*c_con = new int[N_P];

	/* Procesos */
	contar(pointer, c_voc, c_con);

	/* Finalizando */
	printResults(c_voc, c_con);

	return 0;
}

void genPalabras(char **palabras){
	//Tabla ascii: 97 -> 'a', 122 -> 'z'

}

void contar(char *pointer, int *c_voc, int *c_con){

}

void printResults(int *c_voc, int *c_con){

}

