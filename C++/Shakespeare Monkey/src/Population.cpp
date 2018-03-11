/**
 * @file Population.cpp
 * @author Sergio Quijano Rey
 */

#include "Population.h"
#include "Cell.h"
#include <vector>
using namespace std;

//CONSTRUCTORS
Population::Population(){
    target = "Nothing to say";
    size = 100;
    mutationRate = 5;
    startPopulation();
}

Population::Population(string _target, int _size, int _mutationRate){
    target = _target;
    size = _size;
    mutationRate = _mutationRate;
    startPopulation();
}

//OBSERVERS
void Population::show() const{
    cout << "There are " << size << " cells in the population" << endl;
    cout << "Population content: " << endl;
    cout << "===============" << endl << endl;
    for(int i = 0; i < size; i++){
        pop[i].show();
        cout << endl;
    }
    cout << endl;
}

//MODIFIERS
void Population::startPopulation(){
    //Population vector is cleared
    pop.clear();
    
    //Population vector is filled with new cells
    for(int i = 0; i < size; i++){
        Cell newCell(target, mutationRate, true);
        pop.push_back(newCell);
    }
}
