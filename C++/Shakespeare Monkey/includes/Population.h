/**
 * @file population.h
 * @brief Declaration of Population Class
 * @author Sergio Quijano Rey
 */

#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "Cell.h"

class Population{
public:
    //CONSTRUCTORS
    Population();
    Population(std::string _target, int _size, int _mutationRate);
private:
    std::string target;
    int size;
    int mutationRate;
    Cell pop[];
};

#endif