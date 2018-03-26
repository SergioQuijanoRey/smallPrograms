#include "Cell.h"
#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;

//CONSTRUCTOS
Cell::Cell(){
    target = "Nothing to say";
    mutationRate = 5;
    size = target.size();
    fitness = 0;
    
    DNA = "";
    createRandomDNA();
}

Cell::Cell(std::string _target, int _mutationRate, bool newCell, std::string _DNA){
    target = _target;
    mutationRate = _mutationRate;
    fitness = 0;
    size = target.size();
    DNA = "";
    
    if(newCell){
        createRandomDNA();
    }else{
        DNA = _DNA;
    }
}

//MODIFIERS
void Cell::createRandomDNA(){
    char carIn;
    int numIn;
    
    //DNA is cleaned
    DNA = "";
            
    //New DNA is created and added
    for(int i = 0; i < size; i++){
        numIn = randomInt('A', 'z');
        carIn = numIn;
        
        DNA += carIn;
    }
}

void Cell::calculateFitness(){
    fitness = 0;
    for(int i = 0; i < size; i++){
        if(DNA[i] == target[i]){
            fitness++;
        }
    }
    
    if(fitness == 0)
        fitness = 1;    //We want to return at least one cell per cell
}

void Cell::returnCells(Cell temp[]){
    calculateFitness();
    
    for(int i = 0; i < fitness; i++){
        temp[i] = *(this);
    }
}

//OPERATORS
void Cell::operator=(Cell otherCell){
    target = otherCell.getTarget();
    mutationRate = otherCell.getMutationRate();
    fitness = otherCell.getFitness();
    size = target.size();
    DNA = otherCell.getDNA();
}

//GETTERS
int Cell::getFitness() const{
    return fitness;
}

string Cell::getDNA() const{
    return DNA;
}

string Cell::getTarget() const{
    return target;
}

int Cell::getMutationRate() const{
    return mutationRate;
}
    

//OBSERVERS
void Cell::show() const{
    cout << "DNA size: " << size << endl;
    cout << "Fitness: " << fitness << endl;
    cout << "DNA content: " << DNA << endl;
    cout << "==================================" << endl;
}

Cell Cell::reproduce(Cell otherCell) const{
    int choice;
    int randomChoice;
    string newDNA = "";
    
    for(int i = 0; i < size; i++){
        choice = randomInt(0,1);
        randomChoice = randomInt(0, 100);
        if(randomChoice <= mutationRate){
            char carIn = randomInt('A', 'z');
            newDNA += carIn;
        }else if(choice == 0){
            newDNA += DNA[i];
        }else{
            newDNA += otherCell.getDNA()[i];
        }
    }
    
    Cell newCell(target, mutationRate, false, newDNA);
    return newCell;    
}
