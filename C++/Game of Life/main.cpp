/*
Author:
	Sergio Quijano Rey
	sergiquijano@gmail.com

Description:
	The program is a basic representation of Conway's game of life

Version:
	v1.0, 22th Jaunary, 2018: First version of the program with fully functionality 
*/

#include <iostream>
#include <vector>
#include <string>
#include "Grid.h"		//The grid objet which contains the game's logic
using namespace std;

int main(){
	vector<vector<int> > startingPoints = {{0,1}, {1,2}, {2,0}, {2,1}, {2,2}, {2,5}, {10,10}};	//{y, x}
	Grid grid(30, 30);
	grid.display();

	grid.startGame(startingPoints);

	while(grid.getPopulation() > 0){
		grid.nextGen();
		grid.display();
	}
}