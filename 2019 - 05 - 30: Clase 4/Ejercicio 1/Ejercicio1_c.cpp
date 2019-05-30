#include <iostream>
#include "nodoArbol.h"
using namespace std;

int main(){
	nodoArbol nA;
	int val;
	while(cout << "Ingrese valor (> 0): " && cin >> val && val > 0){
		nA.addNum(val);
	}
	nA.printArbol();
	return 0;
}