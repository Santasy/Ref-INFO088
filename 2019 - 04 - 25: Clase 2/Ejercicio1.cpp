#include <iostream>

using namespace std;

int minCC(int n1, int n2, int acum1, int acum2, int m);

int main(int argc, char **argv){
	if(argc != 3){
		cout << "Error. Debe ejecutarse como ./ej1 n1 n2";
		exit(EXIT_FAILURE);
	}

	int n1 = atoi(argv[1]), n2 = atoi(argv[2]);
	if(n1 < 2 || n2 < 2){
		cout << "Error. Los números deben ser mayores a 2\n";
		exit(EXIT_FAILURE);
	}

	int mcc = minCC(n1, n2, n1, n2, 2);
	cout << "MCC entre " << n1 << " y " << n2 << ": " << mcc << '\n';
	return 0;
}

int minCC(int n1, int n2, int acum1, int acum2, int m){
	/* Código */
}