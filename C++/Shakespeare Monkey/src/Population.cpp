#include "Population.h"
#include "Functions.h"
#include <iostream>
using namespace std;

//CONSTRUCTORS
Population::Population(){
    target = "Nothing to say";
    size = 100;
    mutationRate = 5;
    finished = false;
    startPopulation();
}

Population::Population(std::string _target, int _size, int _mutationRate){
    target = _target;
    size = _size;
    mutationRate = _mutationRate;
    finished = false;
    
    //Size is checked
    if(size > arraySize){
        size = arraySize;
    }
    
    startPopulation();        
}
    

//MODIFIERS
void Population::startPopulation(){
    for(int i = 0; i < size; i++){
        Cell newCell(target, mutationRate, true, "");
        pop[i] = newCell;
    }
}

void Population::prepareNextGen(){
    nextGen_size = 0;
    Cell temp[200];
    
    for(int i = 0; i < size; i++){
        pop[i].returnCells(temp);
        addNewCells(temp, pop[i].getFitness());
    }
}

void Population::addNewCells(Cell newCells[], int newCells_size){
    for(int i = 0; i < newCells_size; i++){
        nextGen[nextGen_size + i] = newCells[i];
    }
    
    nextGen_size += newCells_size;
}

void Population::getNextGen(){
    prepareNextGen();
    int index1;
    int index2;
    
    for(int i = 0; i < size; i++){
        index1 = randomInt(0, nextGen_size);
        index2 = randomInt(0, nextGen_size);
        
        pop[i] = nextGen[index1].reproduce(nextGen[index2]);
    }

}

void Population::checkFinished(){
    Cell bestCell = getBestCell();

    if(bestCell.getDNA() == target){
        finished = true;
    }else{
        finished = false;
    }
}

Cell Population::getBestCell(){
    int bestFitness = 0;
    int bestIndex = 0;
    
    //Fitness values are calculated
    for(int i = 0; i < size; i++){
        pop[i].calculateFitness();
    }
    
    //Best cell is searched
    for(int i = 0; i < size; i++){
        if(pop[i].getFitness() > bestFitness){
            bestFitness = pop[i].getFitness();
            bestIndex = i;
        }
    }
    
    return pop[bestIndex];
}

//GETTERS
bool Population::getFinished() const{
    return finished;
}

//OBSERVERS
void Population::show() const{
    cout << "================================================" << endl;
    cout << "Showing content of the " << size << " elements of population" << endl;
    cout << "================================================" << endl;
    
    for(int i = 0; i < size; i++){
        pop[i].show();
    }
}