#include <iostream>
#include <vector>
#include "Cell.h"
using namespace std;

class Population{
public:
    //Constructors
    Population(int _size, string _target);

    //Observers
    void displayInfo() const;

    //Get methods
    bool getFinished() const;
    Cell getBestCell() const;

    //Modifiers
    void calculateBestCell();
    void nextGeneration();
    void generateCandidates();
    void checkFinished();
    
private:
    int size;
    int generation;
    string target;
    bool finished;
    vector<Cell> population;
    vector<Cell> candidates;
    Cell bestCell;

};
