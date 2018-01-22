#include <iostream>
#include <vector>
using namespace std;

/*
	Class which contains the game logic and representation
	A live cell will still alive if It's surrounded by either 2 or 3 alive cells
	A death cell will born if is surrounded by exactly 3 alive cells

	To access to an element of the grid matrix, data[row][column]
*/
class Grid{
public:
	//CONSTRUCTOR METHODS

	/*
		It builds a matrix M(rowsxcols) filled with zeros
	*/
	Grid(int _cols, int _rows);

	//MODIFIER'S METHODS

	/*
		The starting alive cells are selected
	*/
	void startGame(const vector<vector<int> > & startingPoints);

	/*
		New grid is generated via the already explained rules
	*/
	void nextGen();

	//OBSERVER METHODS

	/*
		It shows the populatio, the generation and the matrix
	*/
	void display() const;

	/*
		It just shows the matrix
	*/
	void show() const;

	/*
		It returns the number of alive cells that surround a given cell
	*/
	int countCells(int _x, int _y, vector<vector<int> > prevGrid) const;

	/*
		It counts the total number of alive cells on the grid
	*/
	int countPopulation() const;

	//GET METHODS

	/*
		It returns the delay value if needed
	*/
	int getDelay()const;

	/*
		It returns the current population on the grid
	*/
	int getPopulation() const;

private:
	//Matrix parameters
	int cols;
	int rows;
	
	//Game parameters
	int generation;
	int population;

	//The matrix info
	vector<vector<int> > data;

	//Const which can be swiched if delay is needed
	static const int delayTime = 2;
};
