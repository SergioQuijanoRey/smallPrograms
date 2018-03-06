#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"
#include "Functions.h"
using namespace std;

int main(){
    int xCord;
    int yCord;
    int width;
    int height;
    int mines;

    //Random number generation is started
    startRandom();

    //Users define some game's parameters
    cout << "Introduce the width and height of your gameboard: ";
    cin >> width >> height;
    cout << "Introduce the number of mines: ";
    cin >> mines;

    //The board object is created
    Grid board(width, height);

    //The mines' position are setted
    cout << "Select the starting cell (x,y): ";
    cin >> xCord >> yCord;
    board.startGame(xCord, yCord, mines);
    board.putMine(xCord, yCord);

    //Game loop
    while(board.getFinished() == false){
        cleanScreen();
        board.show();

        cout << "Choose a cell (x,y): ";
        cin >> xCord >> yCord;

        board.putMine(xCord, yCord);
    }

    //Results are shown
    if(board.getWin() == true){
        cout << "You won the game" << endl;
    }else{
        cout << "You selected a mine, you loose" << endl;
    }
}
