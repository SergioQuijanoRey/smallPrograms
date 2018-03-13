#ifndef _CELL_H_
#define _CELL_H_

#include <string>

class Cell{
public:
    //Constructors
    Cell();
    Cell(std::string _target, int _mutationRate, bool randomize);

    //Observers

    //Modifiers
    void calculateFitness();
    void randomDNA();
    
private:
    int size;
    int mutationRate;
    int fitness;
    std::string DNA;
    std::string target;
};
#endif