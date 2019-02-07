#include "Grid.h"
#include "Functions.h"	//Contains some useful funtions

//CONSTRUCTOR METHODS
Grid::Grid(int _cols, int _rows){
	cols = _cols;
	rows = _rows;

	population = 0;
	generation = 0;

	vector<int> aux(_cols, 0);
	vector<vector<int> > aux2(_rows, aux);

	data = aux2;
}

//MODIFIER'S METHODS
void Grid::startGame(const vector<vector<int> > & startingPoints){
	for(int i = 0; i < startingPoints.size(); i++){
		int xCord = startingPoints[i][0];
		int yCord = startingPoints[i][1];

		data[xCord][yCord] = 1;
	}

	generation = 1;
	population = startingPoints.size();
}

void Grid::nextGen(){
	int aliveCells;

	//The states of the grid before the evolution must be saved
	vector<vector<int> > prevGrid = data;

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			aliveCells = countCells(i, j, prevGrid);

			if(prevGrid[j][i] == 0 && aliveCells == 3){
				//This cell borns
				data[j][i] = 1;
			}else if((prevGrid[j][i] == 1) && (aliveCells == 2 || aliveCells == 3)){
				//This cell remains alive
				data[j][i] = 1;
			}else{
				//This cell dies
				data[j][i] = 0;
			}
		}
	}


	generation++;
	population = countPopulation();
}

//OBSERVER METHODS
void Grid::display() const{
	clearScreen();
	cout << "Population: " << population << endl;
	cout << "Generation: " << generation << endl;

	this->show();
}

void Grid::show() const{
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(data[i][j] == 0)
				cout << " . ";
			else
				cout << " o ";
		}

		cout << endl;
	}
}

int Grid::countCells(int _x, int _y, vector<vector<int> > prevGrid) const{
	int liveCells = 0;

	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(_x + i < cols && _x + i >= 0 && _y + j < rows && _y + j >= 0){
				int xCord = _x + i;
				int yCord = _y + j;

				liveCells += prevGrid[yCord][xCord];
			}
		}
	}

	//If the central cell is alive, it must not be counted
	liveCells = liveCells - prevGrid[_y][_x];

	return liveCells;
}

int Grid::countPopulation() const{
	int total = 0;

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(data[i][j] == 1){
				total++;
			}
		}
	}

	return total;
}

//GET METHODS
int Grid::getDelay()const{
	return delayTime;
}

int Grid::getPopulation() const{
	return population;
}
