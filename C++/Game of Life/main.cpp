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
	vector<vector<int> > startingPoints = {{25,25}, {25,27}, {24, 27}, {23, 29}, {22, 29}, {21,29}, {21,29}, {22, 31}, {21,31}, {20, 31}, {21,32}};	//{y, x}
	Grid grid(40, 40);
	grid.display();

	grid.startGame(startingPoints);

	while(grid.getPopulation() > 0){
		grid.nextGen();
		grid.display();
	}
}
