#include <iostream>
#include <cstring>
/* Para usuarios de Windows:
#include <cstdlib>
#include <ctime>
/**/

using namespace std;

/*-----Estructuras-----*/
typedef struct celula{
	int hp;
	celula *der = nullptr;
	celula *izq = nullptr;

	void takeDamage(int dir, int cantidad, auto *j, celula **head);
	void defend(int dir, int cantidad, auto *j);
};

typedef struct jugador{
	celula *celulas = nullptr;
	int energia;
	int restantes;

	void printCells();
	void genCells(int cant, celula **head);
	bool vivo();
	void ejecutar(char comando, int gasto, int pos, jugador *enemigo);
	void buscarYAtacar(int pos, int cantidad, celula **head);
	void buscarYDefender(int pos, int cantidad, celula **head);
};

typedef struct enemigo : public jugador{
	/*
	Ejemplo de herencia.
	Enemigo heredará todas las funciones y atributos que ya tiene la estructura jugador
	*/
	void genJugada(char *comando, int *gasto, int *pos, jugador *enemigo);
};

/*-----Otras funciones-----*/
bool noValido(char comando, int gasto, int pos, jugador *j, jugador *enemigo);
void printPos(jugador j);

/*----Main-----*/
int main(int argc, char **argv){
	srand(time(NULL));
	if(argc != 2){
		cout << "Error. Debe ejecutarse como {./des1 n}.\n";
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);
	if(n < 0 || n > 10){
		cout << "Error. 'n' debe estar dentro de [1, 10].\n";
		exit(EXIT_FAILURE);
	}

	jugador j1;
	j1.genCells(n, &(j1.celulas));

	enemigo j2;
	j2.genCells(n, &(j2.celulas));

	int turno = 1;
	/* Para entrada: */
	char comando;
	int gasto, pos, generada;
	/* Bucle principal */
	while(j1.vivo() && j2.vivo()){
		/*:::::Tablero:::::*/
		cout << "\n\n:::::Turno " << turno++ << ":::::\n\n";

		// Generación de energía
		generada = 2 + random() % j2.restantes;
		j1.energia += generada;
		cout << "Jugador ganó " << generada << " energía.\n";
		generada = 2 + random() % j1.restantes;
		j2.energia += generada;
		cout << "Enemigo ganó " << generada << " energía.\n\n";
		
		cout << "Enemigo - Energía: " << j2.energia << '\n';
		printPos(j2);
		j2.printCells();

		cout << "\n\n";

		j1.printCells();
		printPos(j1);
		cout << "Jugador - Energía: " << j1.energia << "\n\n";

		/*:::::Comandos:::::*/
		// Fase de jugador
		do{
			do{
				cout << "Comando ('h 0 0' para comandos): ";
				cin >> comando >> gasto >> pos;
			}while(noValido(comando, gasto, pos, &j1, &j2));
			j1.ejecutar(comando, gasto, pos, &j2);
		}while(comando == 'h');
		cout << '\n';
		// Fase de enemigo
		if(j2.vivo()){
			j2.genJugada(&comando, &gasto, &pos, &j1);
			j2.ejecutar(comando, gasto, pos, &j1);
		}
	}
	cout << "::::::::::\n";
	if(j1.vivo()){
		cout << "¡Victoria!\n\n";
	}else{
		cout << "Derrota.\n\n";
	}
	cout << "Fin del juego.\n";
	return 0;
}

/*-----Funciones generales-----*/
bool noValido(char comando, int gasto, int pos, jugador *j, jugador *enemigo){
	/*:::::Función que valida el comando, gasto y posición:::::*/
	if(comando != 'h' && comando != 'd' && comando != 'a'){ // Tiene que ser alguno de los comandos disponibles
		cout << "Comando no reconocido.\n";
		return true;
	}
	if(comando == 'h' && gasto == 0 && pos == 0){ // h 0 0
		return false;
	}
	// Validación de gasto
	if(gasto > j->energia){ 
		cout << "Falta energía.\n";
		return true;
	}
	if(gasto <= 0){
		cout << "Debe gastar al menos 1 de energía.\n";
		return true;
	}
	// Validación de posición
	if(pos < 0){
		cout << "Posición no válida.\n";
		return true;
	}
	if(comando == 'a' && pos >= enemigo->restantes){
		cout << "Enemigo no tiene tantas células.\n";
		return true;
	}
	if(comando == 'd' && pos >= j->restantes){
		cout << "No tienes tantas células.\n";
		return true;
	}
	return false;
}

void printPos(jugador j){
	/*:::::Función que imprime indice de las posiciones:::::*/
	for(int i = 0; i < j.restantes; ++i){
		cout << '_';
		if(i < 10) cout << '0';
		cout << i << "_ ";
	}
	cout << "<- Indices\n";
}

/*-----Funciones de jugador-----*/
void jugador::ejecutar(char comando, int gasto, int pos, jugador *enemigo){
	energia -= gasto; // Gasto de energía
	switch(comando){
		case 'h':
			cout << "a energia posicion: Atacar con 'energia' a 'posicion'\n";
			cout << "d energia posicion: Defender con 'energia' a 'posicion'\n";
			break;
		case 'a':
			cout << "Atacando pos [" << pos << "] con " << gasto << " de energía.\n";
			enemigo->buscarYAtacar(pos, gasto, &(enemigo->celulas));
			enemigo->printCells();
			break;
		case 'd':
			cout << "Defendiendo pos [" << pos << "] con " << gasto << " de energía.\n";
			buscarYDefender(pos, gasto, &(celulas));
			printCells();
			break;
	}
}

void jugador::buscarYAtacar(int pos, int cantidad, celula **head){
	celula *it = *head;
	for(int i = 0; i < pos; ++i) it = it->der;
	it->takeDamage(0, cantidad, this, head);
}

void jugador::buscarYDefender(int pos, int cantidad, celula **head){
	celula *it = *head;
	for(int i = 0; i < pos; ++i) it = it->der;
	it->defend(0, cantidad, this);
}

bool jugador::vivo(){
	/*:::::Función que retorna si el jugador sigue vivo:::::*/
	return (restantes > 0);
}

void jugador::printCells(){
	celula *it = celulas;
	while(it != nullptr){
		cout << '|';
		if(it->hp < 10) cout << '0';
		cout << it->hp << "| ";
		it = it->der;
	}
	cout << '\n';
}

void jugador::genCells(int cant, celula **head){
	cout << "Generando células\n";
	restantes = cant;
	energia = 0;
	celula *ultima = *head;
	for(int i = 0; i < cant; ++i){
		celula *nueva = new celula;
		nueva->hp = 1 + random() % cant;
		if(ultima == nullptr){
			*head = ultima = nueva;
		}else{
			ultima->der = nueva;
			nueva->izq = ultima;
			ultima = nueva;
		}
	}
	cout << "Celulas generadas.\n";
}

/*:::::Funciones de enemigo:::::*/
void enemigo::genJugada(char *comando, int *gasto, int *pos, jugador *enemigo){
	*gasto = 1 + random() % energia;
	switch(random() % 2){
		case 0: // Atacar
			*comando = 'a';
			*pos = random() % enemigo->restantes;
			cout << "Enemigo atacará!\n";
			break;
		case 1: // Defender
			*comando = 'd';
			*pos = random() % restantes;
			cout << "Enemigo se defenderá!\n";
			break;
	}
}

/*:::::Funciones de celula:::::*/
void celula::takeDamage(int dir, int cantidad, auto *j, celula **head){
	hp -= cantidad;
	if(hp <= 0){ // Si es que la célula muere, hay que sacarla de la lista
		if(izq != nullptr)
			izq->der = der;
		else // Si no, se modificó la cabeza
			*head = der;

		if(der != nullptr)
			der->izq = izq;
		--((jugador*) j)->restantes;
		cout << "Se ha destruído una célula.\n";
	}

	//Ahora se entrega el daño expandido
	if(cantidad > 1){ // Si aún queda daño que repartir
		switch(dir){
			case 0:
				if(izq != nullptr) izq->takeDamage(-1, cantidad - 1, j, head);
				if(der != nullptr) der->takeDamage( 1, cantidad - 1, j, head);
				break;
			case 1:
				if(der != nullptr) der->takeDamage( 1, cantidad - 1, j, head);
				break;
			case -1:
				if(izq != nullptr) izq->takeDamage(-1, cantidad - 1, j, head);
				break;
		}
	}
}

void celula::defend(int dir, int cantidad, auto *j){
	hp += cantidad;

	if(hp > 10){ // Si es que la célula tiene más de 10 de vida, se replica
		celula *nueva = new celula;
		nueva->hp = hp - 10;
		hp = 10;
		// Se agrega a la derecha
		nueva->der = der;
		nueva->izq = this;
		if(der != nullptr) der->izq = nueva;
		der = nueva;
		++((jugador*) j)->restantes;
		cout << "Se ha replicado una célula.\n";
	}

	//Ahora se entrega la defensa expandida
	if(cantidad > 1){ // Si aún queda defensa que repartir
		switch(dir){
			case 0:
				if(izq != nullptr) izq->defend(-1, cantidad - 1, j);
				if(der != nullptr) der->defend( 1, cantidad - 1, j);
				break;
			case 1:
				if(der != nullptr) der->defend( 1, cantidad - 1, j);
				break;
			case -1:
				if(izq != nullptr) izq->defend(-1, cantidad - 1, j);
				break;
		}
	}
}