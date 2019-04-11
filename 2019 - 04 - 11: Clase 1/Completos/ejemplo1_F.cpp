/*-----Contador de vocales y consonantes-----*/
#include <iostream>

using namespace std;

#define N_P 10
#define N_C 20

const char *vocales = "aeiou";

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
    for(int i = 0; i < N_P; i++){
        palabras[i] = new char[N_C];
        for(int j = 0; j < N_C; j++){
            palabras[i][j] = 97 + rand() % 25;
        }
    }
    cout << "Palabras generadas" << endl << endl;
}

void contar(char *pointer, int *c_voc, int *c_con){
    for(int i = 0; i < N_P; i++, pointer++){
        c_voc[i] = c_con[i] = 0;
        bool found = false;
        for(int j = 0; j < N_C; j++, pointer++){
            for(int k = 0; k < 5; k++){
                if(*pointer == vocales[k]){
                    found = true;
                    break; //No se necesita seguir iterando
                }
            }
            if(found)
                    c_voc[i]++;
                else
                    c_con[i]++;
        }
    }
}

void printResults(int *c_voc, int *c_con){
    cout << "Vocales:" << endl;
    for(int i = 0; i < N_P; i++){
        if(c_voc[i] < 10) cout << " ";
        cout << c_voc[i]<< " ";
    }
    cout << endl;

    cout << "Consonantes:" << endl;
    for(int i = 0; i < N_P; i++){
        if(c_con[i] < 10) cout << " ";
        cout << c_con[i]<< " ";
    }
    cout << endl;
}