#include <iostream>
#include <cmath>

using namespace std; // Evitamos ocupar std::cout y std::cin

int main(){ // Opciones de main: 'main()' ó 'main(int argc, char **argv)'
	/* Tipos de datos */

	cout << "Largo tipo de dato(bits):\n";
	// 1 byte = 8 bits
	// Observar que todos los tipos, menos char, ocupan 1 bit para el signo (+-)
	cout << sizeof(char) * 8 << '\n';
	cout << sizeof(short) * 8 << '\n';
	cout << sizeof(int) * 8 << '\n';
	cout << sizeof(float) * 8 << '\n';
	cout << sizeof(double) * 8 << "\n\n";

	// unigned {tipo} {nombre_variable}: nos permitirá ocupar el bit para el signo
	cout << "Overflow:\n";
	cout.precision(0); // Especifica que la salida por 'cout' tenga 0 decimales, forzando también la impresión de todos los dígitos, y no una representación científica (401.24e^18)
 	int x = 2147483647; // == pow(2, 31) - 1;
	cout << fixed << x << '\n';
	++x;
	cout << fixed << x << "\n\n";

	unsigned int x2 = 2147483647; // Si aceptará correctamente la asignación
	cout << fixed << x2 << '\n';
	++x2;
	cout << fixed << x2 << "\n\n";
	
	x2 = pow(2, 32) - 1; // Este será el límite superior para un 'unsigned int'
	cout << fixed << x2 << '\n';
	++x2;
	cout << fixed << x2 << "\n\n";

	/* En general */
	char c1   ;
	short s1  ;
	int i1    ;
	float f1  ;
	double d1 ;

	cout << "Valores por defecto (ruido):\n";
	cout << c1 << '\n';
	cout << s1 << '\n';
	cout << i1 << '\n';
	cout << f1 << '\n';
	cout << d1 << "\n\n";

	c1 = s1 = i1 = f1 = d1 = NULL; // Asignación multiple
	cout << "Valores definidos NULL:\n";
	cout << '|' << c1 << "|: Caracter Nulo\n"; //Observar caracter nulo delimitado por: '|'{c1}'|'
	cout << s1 << '\n';
	cout << i1 << '\n';
	cout << f1 << '\n';
	cout << d1 << "\n\n";

	cout << "Adición rápida:\n";
	x = 0;
	cout << x << '\n';
	cout << (x++) << '\n'; // Sumará después de entregar su valor para impresión
	cout << x << '\n';
	cout << (++x) << '\n'; // Sumará antes de entregar su valor para impresión
	cout << x << "\n\n";
	// '++x' es ligeramente más rápido que 'x++', así que es recomendable ocuparlo de esa manera
	
	/* Casting: Permite transformar un tipo de dato, en otro especificado */
	c1 = 97;
	cout << "Casting:\n";
	cout << c1 << " - " << (int) c1 << '\n'; // Observar que un char, per se, es un NÚMERO
	f1 = 9.9;
	i1 = f1;
	cout << i1 << '\n';
	i1 = (int) f1;
	cout << i1 << '\n';
	i1 = round(f1);
	cout << i1 << '\n';

	return 0; // Bajo regla general, siempre el retorno de un programa debiera ser '0'
}