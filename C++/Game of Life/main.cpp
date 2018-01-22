#include <iostream>
#include <vector>
#include <string>
#include<stdlib.h>
using namespace std;

//FUNCTION'S HEADERS
void delay(int time){
	system("sleep 2");
}
void clearScreen(){
	system("clear");
}

//GRID CLASS
class Grid{
public:
	//CONSTRUCTOR METHODS
	Grid(int _cols, int _rows){
		cols = _cols;
		rows = _rows;

		population = 0;
		generation = 0;

		vector<int> aux(_cols, 0);
		vector<vector<int> > aux2(_rows, aux);

		data = aux2;
	}

	//MODIFIER'S METHODS
	void startGame(const vector<vector<int> > & startingPoints){
		for(int i = 0; i < startingPoints.size(); i++){
			int xCord = startingPoints[i][0];
			int yCord = startingPoints[i][1];

			data[xCord][yCord] = 1;
		}

		generation = 1;
		population = startingPoints.size();
	}

	void nextGen(){
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
	void display() const{
		clearScreen();
		cout << "Population: " << population << endl;
		cout << "Generation: " << generation << endl;

		this->show();
	}

	void show() const{
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

	int countCells(int _x, int _y, vector<vector<int> > prevGrid) const{
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

	int countPopulation() const{
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
	int getDelay()const{
		return delayTime;
	}

	int getPopulation() const{
		return population;
	}

private:
	int cols;
	int rows;
	int generation;
	int population;
	vector<vector<int> > data;

	static const int delayTime = 2;
};

int main(){
	vector<vector<int> > startingPoints = {{0,1}, {1,2}, {2,0}, {2,1}, {2,2}, {2,5}, {10,10}};	//{y, x}
	Grid grid(30, 30);
	grid.display();

	grid.startGame(startingPoints);
	grid.display();
	delay(grid.getDelay());


	while(grid.getPopulation() > 0){
		grid.nextGen();
		grid.display();

		//delay(grid.getDelay());
	}
}