#include <iostream>

using namespace std;

#define N_P 10
#define N_C 20

void genPalabras(char **palabras);
void contar(char *pointer, int *c_voc, int *c_con);
void printResults(int *c_voc, int *c_con);

int main(int argc, char **argv){
	srand(time(NULL));

	/* Definiciones */
	char **palabras = new char*[N_P];
	genPalabras(palabras);
	
	char *pointer = *palabras;
	int *c_voc = new int[N_P],
			*c_con = new int[N_P];

	/* Procesos */
	contar(pointer, c_voc, c_con);

	/* Finalizando */
	printResults(c_voc, c_con);

	return 0;
}