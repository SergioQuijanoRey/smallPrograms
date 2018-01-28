#include "Population.h"

//Constructors
Population::Population(int _size, string _target){
    size = _size;
    target = _target;
    finished = false;
    generation = 1;

    for(int i = 0; i < size; i++){
        Cell cellIn(target, true);
        population.push_back(cellIn);
    }

    calculateBestCell();
}

//Observers
void Population::displayInfo() const{
    cout << "Generation: " << generation << endl;
    cout << "The best representant is: " << bestCell.getDNA() << endl;
    cout << "The rest of the population is:" << endl;

    for(int i = 0; i < size; i++){
        cout << "\t" <<  population[i].getDNA() << endl;
    }
}

//Get methods
bool Population::getFinished() const{
    return finished;
}

Cell Population::getBestCell() const{
    return bestCell;
}

//Modifiers
void Population::calculateBestCell(){
    double bestFitness = population[0].getFitness();
    Cell currentBestCell = population[0];

    for(int i = 0; i < size; i++){
        if(population[i].getFitness() > bestFitness){
            bestFitness = population[i].getFitness();
            currentBestCell = population[i];
        }
    }

    bestCell = currentBestCell;
}

void Population::nextGeneration(){
    generateCandidates();

    int index1 = randomInt(0, candidates.size());
    int index2 = randomInt(0, candidates.size());

    population.clear();

    Cell newCell = candidates[index1].reproduce(candidates[index2]);
    population.push_back(newCell);

    calculateBestCell();

    generation++;
}

void Population::generateCandidates(){
    int fit;

    candidates.clear();

    for(int i = 0; i < size; i++){
        fit = population[i].getFitness() + 1;    //The lowest fitness is 1
        for(int j = 0; j < fit; j++){
            candidates.push_back(population[i]);
        }
    }
}

void Population::checkFinished(){
    if(bestCell.getDNA() == target){
        finished = true;
    }
}
