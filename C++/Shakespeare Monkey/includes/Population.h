#ifndef _POPULATION_H_
#define _POPULATION_H_

#include <string>
#include <vector>
#include "Cell.h"

class Population{
public:
    //Constructors
    Population();
    Population(int _size, int _mutationRate, std::string _target);

    //Observers
    void show() const;

    //Modifiers

private:
    int size;
    int mutationRate;
    std::vector<Cell> pop;
    std::string target;
};

#endif