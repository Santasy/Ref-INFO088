#include <iostream>
/* // Para usuarios de Windows:
#include <random>
#include <ctime>
/**/
#include "nodoArbol.h"
using namespace std;

int main(){
	srand(time(NULL));
	nodoArbol nA;
	cout << "Valores:\n";
	for(int i = 0; i < 15; ++i){
		int val = 1 + (int) random() % 10;
		cout << val << ' ';
		nA.addNum(val);
	}
	cout << '\n';
	nA.printArbol();
	return 0;
}