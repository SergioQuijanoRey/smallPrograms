#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"
#include "Functions.h"
using namespace std;

int main(){
    int xCord;
    int yCord;
    int size = 20;
    int mines = 10;

    Grid board(size);

    cout << "Select the starting cell (x,y): ";
    cin >> xCord >> yCord;
    board.startGame(xCord, yCord, mines);

    while(board.getFinished() == false){
        cleanScreen();
        board.show();

        cout << "Choose a cell (x,y): ";
        cin >> xCord >> yCord;

        board.putMine(xCord, yCord);
    }
}
