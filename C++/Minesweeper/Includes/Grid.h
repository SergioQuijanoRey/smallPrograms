#ifndef _GRID_H_
#define _GRID_H_

class Grid{
public:
    //Constructors
    Grid();
    Grid(int size);
    Grid(int width, int height);

    //Modifiers
    void startGame(int xCord, int yCord, int nMines);
    void putMine(int xCord, int yCord);
    void revealCell(int xCord, int yCord);
    void startNumberBoard();

    //Observers
    int countMines(int xCord, int yCord) const;
    void show() const;

    //Get methods
    bool getFinished() const;

private:
    static const int arraySize = 500;
    int width;
    int height;
    int nMines;
    bool finished;
    bool minesBoard[arraySize/2][arraySize/2];
    int numbersBoard[arraySize/2][arraySize/2];
};

#endif
