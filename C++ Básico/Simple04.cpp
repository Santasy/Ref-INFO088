#include <iostream>
/*  //Para usuarios de Windows:
#include <ctime>
#inclide <cstdlib>
/**/

using namespace std;

/* Definición de clases */
class animal{
    protected:
        // Todo dentro de la etiqueta 'protected' no es accesible de manera directa.
        char *nombre = new char[30];
        // Fuera de esta estructura, no se podrá acceder al atributo 'nombre'.
        // En otras palabras, {animal}.nombre no es accesible.
        // A esta característica se le conoce como 'encapsulamiento', pues
        // restringe el acceso a ciertos atributos de la clase correspondiente.

    public:
        // Todo dentro de la etiqueta 'public' será accesible sin problemas.
        void sonido(){
            cout << "El animal se aleja sin hacer ruido.\n";
        }

        // También, funciones propias de la clase SÍ podrán acceder a atributos protegidos y/o privados.
        // Usualmente, a este tipo de funciones se le llaman 'set(ters)' y 'get(ters)'.
        // Observar que 'set' y 'get' son parte los nombres.
        void setNombre(char *n){
            nombre = n;
        }

        char* getNombre();
        // ^ Observar que la función se define más abajo
};

class perro : public animal{
    // ^ Esta syntax, explicará que la clase perro hereda los elementos de la clase animal
    // Se puede entender como "un perro es un animal", ó "un perro se comporta como animal".
    // Esto permite que nuestras variables tipo perro también tengan nombre,
    // y acceso a las funciones 'set' y 'get' de la clase animal.
    // A esta característica se le conoce como 'herencia'.
    public:
        perro(char *n){
            // Esta función se conoce como constructor.
            // No debe declararse un tipo de dato de retorno (se obvia el 'void').
            // Generalmente es llamada directamente en la creación de un nuevo perro,
            // pero también se puede llamar a conveniencia.
            nombre = n;
            sonido();
            cout << '\n';
        }

        perro(){
            // No olvidar que las funciones se pueden sobrecargar.
            // En este caso, el constructor se podrá llamar con o sin argumentos.
            nombre = (char *) "Kilterri"; // Se ocupó un casting simple, para evitar ambigüedad.
            sonido();
            cout << '\n';
        }

        void sonido(){
            // Y esta función sobre-escribe la función 'sonido()' heredada de animal.
            // Observar el caso para clase 'gato'
            cout << nombre << " dice '¡GUAU!' con mucha vitalidad.\n";
        }
};

class gato : public animal{
    public: 
        gato(char *n){
            // Similar al constructor del perro.
            // Solo se puede llamar entregando un argumento,
            // es decir, para crear un gato es necesario darle un nombre.
            nombre = n;
            sonido();
            cout << '\n';
        }

        void sonido(){
            // Al igual que 'perro', 'gato' sobre-escribe la función sonido,
            // pero además llama también a la función original de 'animal'.
            cout << nombre << " es un gato muy silencioso.\n";
            animal::sonido(); // <- Esa es la syntax para lograrlo.
        }
};
/*----------*/

/*:::::Programa Principal:::::*/
int main(){
    int i;

    // Se creará una lista de punteros de animales.
    animal **animales = new animal*[3];
    // Se crearán 3 animales, y se guardará su dirección en la lista.
    animales[0] = new perro((char *) "Firulais");
    animales[1] = new perro();
    animales[2] = new gato((char *) "Algodón");
    // Nuestro uso de herencia, permite que una
    // lista de animales, pueda contener tanto perros como gatos.
    // A esta característica se le conoce como 'polimorfismo'.
    
    // También, el polimorfismo permitirá tratar a un perro y/ó gato como animal,
    // lamando indiferentemente a funciones que tengan en común.
   
    cout << "Nombres de los animales:\n";
    for(i = 0; i < 3; ++i)
        // Recordar que el programa no permite acceder a animales[i].nombre
        cout << animales[i]->getNombre() << '\n';
    return 0;
}
/*::::::::::*/

char* animal::getNombre(){
    return nombre;
}
