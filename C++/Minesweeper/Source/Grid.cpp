#include <iostream>
#include "Grid.h"
#include "Functions.h"
using namespace std;

//Constructors
Grid::Grid(){
    width = 10;
    height = 10;

    nMines = 0;
    finished = false;

    startNumberBoard();
}

Grid::Grid(int size){
    width = size;
    height = size;

    nMines = 0;
    finished = false;

    startNumberBoard();
}

Grid::Grid(int width, int height){
    this->width = width;
    this->height = height;

    nMines = 0;
    finished = false;

    startNumberBoard();
}

//Modifiers
void Grid::startGame(int xCord, int yCord, int minesIn){
    int xChoice;
    int yChoice;

    this->nMines = minesIn;

    while(minesIn > 0){
        xChoice = randomInt(0, width);
        yChoice = randomInt(0, height);

        if(xChoice != xCord && yChoice != yCord && minesBoard[yChoice][xChoice] == false){
            minesBoard[yChoice][xChoice] = true;
            minesIn--;
        }
    }
}

void Grid::putMine(int xCord, int yCord){
    if(minesBoard[yCord][xCord] == true){
        cout << "You selected a mine, game ends" << endl;
        finished = true;
    }else{
        revealCell(xCord, yCord);
    }
}

void Grid::revealCell(int xCord, int yCord){
    int mines = countMines(xCord, yCord);

    if(mines == 0){
        numbersBoard[yCord][xCord] = mines;

        for(int row = -1; row <= 1; row++){
            for(int col = -1; col <= 1; col++){
                if(xCord + col < width && xCord + col >= 0 && yCord + row < height && yCord + row >= 0 && numbersBoard[xCord+col][yCord+row]!= -1){
                    revealCell(xCord+col, yCord+row);
                }
            }
        }
    }else{
        numbersBoard[yCord][xCord] = mines;
    }
}

void Grid::startNumberBoard(){
    for(int row = 0; row < width; row++){
        for(int col = 0; col < height; col++){
            numbersBoard[row][col] = -1;
        }
    }
}

//Observers
int Grid::countMines(int xCord, int yCord) const{
    int numberMines = 0;

    for(int row = -1; row <= 1; row++){
        for(int col = -1; col <= 1; col++){
            if(xCord + col < width && xCord + col >= 0 && yCord + row < height && yCord + row >= 0){
                if(minesBoard[yCord + row][xCord + row] == true){
                    numberMines++;
                }
            }
        }
    }

    return numberMines;
}

void Grid::show() const{
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            if(numbersBoard[row][col] == -1){
                cout << ". ";
            }else{
                cout << numbersBoard[row][col] << " ";
            }
        }
        cout << endl;
    }
}

//Get methods
bool Grid::getFinished() const{
    return finished;
}
