/*-----Juego Rock, Paper, Scissors-----*/
#include <iostream>
#include <cmath>

using namespace std;

int 
		N_R, //Rondas
		N_J, //Jugadores 
	  N_C; //Caracteres
const char *opciones;

struct torneo{
	/* Def. de Sub-estructuras */
	struct jugador{
		/* Atributos */
		char *jugadas = new char[N_C];
		int score = 0, id;

		/* Funciones */
		void cambiarJugada(int i){
			/*---Codigo---*/
			//cout << "Jugador " << id << " ha cambiado su jugada" << endl;
		}

		void generarJugada(){
			/*---Codigo---*/
			//cout << "Jugador " << id << " ha creado su jugada" << endl;
		}
	};

	/* Atributos */
	int premio = 0, ronda = 1;
	jugador *restantes = new jugador[N_J],
					*siguiente = new jugador[N_J / 2];

	/* Funciones */
	void generarJugadores(){
		//cout << "Creando jugadores" << endl;
		/*---Codigo---*/
		//cout << "Jugadores creados" << endl << endl;
	}

	void realizar(){
		cout << "El torneo ha comenzado" << endl;
		/*---Codigo---*/
		cout << "El jugador " << restantes[0].id << " ha ganado el premio de $" << premio << endl << endl;
	}

	void jugarRonda(){
		cout << "Se inicia ronda " << ronda << endl << endl;
		for(int i = 0;; i++){
			/*---Codigo---*/
			//cout << "Gano el jugador numero " << siguiente[i].id << endl; 
		}

		cout << "Ronda " << ronda << " terminada" << endl << endl;
		/*---Codigo---*/
	}

	jugador jugar(jugador j1, jugador j2){
		cout << "Jugador " << j1.id << " contra jugador " << j2.id << endl; 
		j1.score = j2.score = 0;
		/*---Codigo---*/
		if(j1.score > j2.score) return j1;
		else return j2;
	}
};

int main(int argc, char **argv){
	/* Setup */
	srand(time(NULL));
	if(argc != 3){
		cout << "Error. Debe ejecutar: ./ej2 {N_R} {N_C}" << endl;
		return EXIT_FAILURE;
	}
	N_R = atoi(argv[1]);
	N_C = atoi(argv[2]);
	N_J = pow(2, N_R);
	if(N_C % 2 == 0){
		cout << "Error. La cantidad de jugadas debe ser impar" << endl;
		return EXIT_FAILURE;
	}

	/* Definiciones */
	torneo t;
	t.premio = 3000;
	t.generarJugadores();

	/* Procesos */
	t.realizar();

	/* Finalizando */
	cout << "Fin del programa" << endl;
	return 0;
}