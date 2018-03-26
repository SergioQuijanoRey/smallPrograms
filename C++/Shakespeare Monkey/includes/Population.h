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
    
    //MODIFIERS
    void startPopulation();
    void prepareNextGen();
    void addNewCells(Cell newCells[], int newCells_size);
    void getNextGen();
    void checkFinished();
    Cell getBestCell();
    
    //GETTERS
    bool getFinished() const;
    
    //OBSERVERS
    void show() const;
 
private:
    static const int arraySize = 500;
    Cell pop[arraySize];
    Cell nextGen[arraySize];
    std::string target;
    int size;
    int nextGen_size;
    int mutationRate;
    bool finished;
   
};

#endif