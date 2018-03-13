#include "Population.h"
using namespace std;

//CONSTRUCTORS
Population::Population(){
    size = 100;
    mutationRate = 5;
    target = "Nothing to say";

    for(int i = 0; i < size; i++){
        Cell newcell();
        pop.push_back(newCell)
    }
}

Population::Population(int _size; int _mutationRate; std::string _target){
    size = _size;
    mutationRate = _mutationRate;
    target = _target;

    for(int i = 0; i < size; i++){
        Cell newcell();
        pop.push_back(newCell)
    }
}

//OBSERVERS
void Population::show(){
    for(int i = 0; i < size; i++){
        pop[i].show();
    }
}