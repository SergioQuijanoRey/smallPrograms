#include <iostream>
#include "functions.h"
using namespace std;

void clearScreen(){
    system("clear");
}

void mostrarTablero(vector<vector<int> > tablero){
    for(int i = 0; i < tablero.size(); i++){
        for(int j = 0; j < tablero[i].size(); j++){
            //Muestro X para J1, O para J2 y espacio para nadie
            switch (tablero[i][j]){
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << "X";
                    break;
                case 2:
                    cout << "O";
                    break;
            }

            cout << " | ";
        }
        cout << endl;
    }
}

void juega(vector<vector<int> > & tablero, int jugador){
    int x;
    int y;
    bool fichaCorrecta = false;

    while(!fichaCorrecta){
        cout << "Introduce una ficha J" << jugador << " (x,y): ";
        cin >> x >> y;

        if(!(x >= 0 && x <= 2 && y >= 0 && y <= 2)){
            cout << "Incorrecto, introduce bien la ficha" << endl;
        }else{
            if(tablero[x][y] != 0){
                cout << "Incorrecto, ya hay una ficha, introducelo de nuevo" << endl;
            }else{
                fichaCorrecta = true;
                tablero[x][y] = jugador;        //Segun la constante definida mas arriba
            }
        }
    }
}

bool comprobar(const vector<vector<int> > & tablero, int & jugador){
    int ganador;
    bool fin = false;

    //Compruebo filas
    for(int i = 0; i < 3 && !fin; i++){
        if(tablero[i][0] == tablero[i][1] &&  tablero[i][1] == tablero[i][2]){
            ganador = tablero[i][0];
            fin = true;
        }
    }

    //Compruebo columnas
    for(int j = 0; j < 3 && !fin; j++){
        if(tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j]){
            ganador = tablero[0][j];
            fin = true;
        }
    }

    //Compruebo diagonales
    if(!fin){
        if(tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]){
            ganador = tablero[0][0];
            fin = true;
        }else if(tablero[2][0] == tablero[1][1] && tablero[1][1] == tablero[0][2]){
            ganador = tablero[2][0];
            fin = true;
        }
    }

    return fin;
}
