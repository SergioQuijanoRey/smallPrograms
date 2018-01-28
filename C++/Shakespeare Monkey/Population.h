#include <iostream>
#include <vector>
#include <string>
#include "Cell.h"
#include "Functions.h"
using namespace std;

class Population{
public:
    //Constructors
    Population(string _target, int _size);

    //Get methods
    bool getFinished() const;

    //Observers
    void show() const;

    //Modifiers
    void nextGen();
    void generateCandidates();
    void calculateBestCell();
    void checkFinished();

private:
    int size;
    int generation;
    bool finished;
    string target;

    vector<Cell> members;
    vector<Cell> candidates;
    Cell bestCell;

};
