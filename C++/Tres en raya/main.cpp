#include <iostream>
#include <cmath>
#include <vector>
#include "functions.h"
using namespace std;

//Constantes
const int J1 = 1;
const int J2 = 2;

//Funcion principañ
int main(){
    bool acabado = false;
    int ganador = -1;
    vector<int> columnas(3,0);                      //Creo el tablero 3x3 rellenado de 0
    vector<vector<int> > tablero(3, columnas);

    while(!acabado){
        clearScreen();
        mostrarTablero(tablero);
        juega(tablero, J1);
        acabado = comprobar(tablero, ganador);
        if(!acabado){
            clearScreen();
            mostrarTablero(tablero);
            juega(tablero, J2);
            acabado = comprobar(tablero, ganador);
        }
    }

    clearScreen();
    mostrarTablero(tablero);
    cout << "El ganador es: J" << ganador << endl;
}
