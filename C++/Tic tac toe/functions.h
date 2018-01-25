#include <vector>
#include "stdlib.h"
using namespace std;

void clearScreen();
void mostrarTablero(vector<vector<int> > tablero);      //J1 = 1 | J2 = 2 | NULL = 0
void juega(vector<vector<int> > & tablero, int jugador);
bool comprobar(const vector<vector<int> > & tablero, int & jugador);
