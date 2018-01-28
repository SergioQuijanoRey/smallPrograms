#include <iostream>
#include <vector>
#include <string>
#include "Functions.h"
using namespace std;

class Cell{
public:
    //Constructors
    Cell(string _target, bool random);

    //Get methods
    string getDNA() const;
    int getFitness() const;

    //Modifiers
    void calculateFitness();
    void addDNA(char newFragment);

    //Observers
    Cell reproduce(Cell cell1, Cell cell2);

private:
    string DNA;
    string target;
    int size;
    double fitness;
    const double mutationRate = 5;
};
