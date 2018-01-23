#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include<time.h>
using namespace std;

//FUNCTIONS' HEADERS
void startRandom();
void clearScreen();
int random(int min, int max);

//GRID CLASS
class Grid{
public:
	//CONSTRUCTOR METHODS
	Grid(int side){
		length = side;
		mines = 0;
		finished = false;

		vector<vector<int> > auxMines(length, vector<int> (length, 0));
		minesboard = auxMines;		//Mines' grid is filled with 0s

		vector<vector<int> > auxGame(length, vector<int> (length, -1));
		gameboard = auxGame;	//Gameboard is filled with -1
	}

	//OBSERVER METHODS
	void show() const{
		for(int i = 0; i < length; i++){
			for(int j = 0; j < length; j++){
				if(gameboard[i][j] == -1){
					cout << " . ";
				}else{
					cout << " " << gameboard[i][j] << " ";
				}
			}

			cout << endl;
		}
	}

	int countMines(int x, int y) const{
		int totalMines = 0;

		for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				if(x + i >= 0 && x + i < length && y + j >= 0 && y + j < length){
					totalMines = totalMines + minesboard[y + j][x + i];
				}
			}
		}

		totalMines = totalMines - minesboard[y][x];
		return totalMines;

	}

	//GET METHODS
	bool getFinished() const{
		return finished;
	}


	//MODIFIERS
	void chooseCell(int x, int y){
		if(minesboard[y][x] == 1){
			finished = true;
		}else if(gameboard[y][x] == -1){
			//This cell hasn't been revealed yet
			this->revealCell(x, y); 
		}
	}

	void revealCell(int x, int y){
		int nMines = countMines(x, y);

		if(nMines == 0){
			//Surrounded cells are revealed as well
			for(int i = -1; i <= 1; i++){
				for(int j = -1; j <= 1; j++){
					if(i != 0 && j != 0 && x + i >= 0 && x + i < length && y + j >= 0 && y + j < length && gameboard[y][x] == -1){
						gameboard[y][x] = 0;
						revealCell(x + i, y + j);
					}
				}
			}
		}else{
			gameboard[y][x] = nMines; 
 		}
	}

	void putMines(int initialX, int initialY, int nMines){
		mines = nMines;

		while(nMines > 0){
			int xCord = random(0, length);
			int yCord = random(0, length);

			if(xCord != initialX && yCord != initialY && minesboard[yCord][xCord] == 0){
				minesboard[yCord][xCord] = 1;
				nMines--;
			}
		}
	}

private:
	int length;
	int mines;
	bool finished;

	vector<vector<int> > minesboard;
	vector<vector<int> > gameboard;
};

//MAIN PROGRAM
int main(){
	const int side = 20;
	const int nMines = 20;

	int xIn;
	int yIn;

	//Random number generation is now available
	startRandom();

	//Game is generated
	Grid minesweeper(side);
	minesweeper.putMines(5, 5, nMines);
	while(!minesweeper.getFinished()){
		clearScreen();
		minesweeper.show();

		cout << "Introduce [x, y]: ";
		cin >> xIn >> yIn;

		minesweeper.chooseCell(xIn, yIn);
	}
}

//FUNCTIONS IMPLEMENTATIONS
void startRandom(){
	srand(time(NULL));
}

void clearScreen(){
	system("clear");
}

int random(int min, int max){
	int value =  min + rand() % (max +1 - min);
    return value;
}


