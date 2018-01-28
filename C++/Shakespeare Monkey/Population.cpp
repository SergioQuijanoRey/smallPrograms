#include "Population.h"

//Constructors
Population::Population(string _target, int _size){
    target = _target;
    size = _size;
    generation = 0;
    finished = false;

    vector<Cell> members;
    vector<Cell> candidates;
    bestCell = Cell(target, true);  //The first best cell is ramdon
}

//Get methods
bool Population::getFinished() const{
    return finished;
}

//Observers
void Population::show() const{
    cout << "Generation: " << generation << endl;
    cout << "The best candidate is: " << bestCell.getDNA() << endl;

    cout << "The rest of the cells are:" << endl;
    for(int i = 0; i < size; i++){
        cout << "\t" << members[i].getDNA() << endl;
    }
}

//Modifiers
void Population::nextGen(){
    int choice1;
    int choice2;

    members.clear();

    for(int i = 0; i < size; i++){
        choice1 = randomInt(0, candidates.size() - 1);
        choice2 = randomInt(0, candidates.size() - 1);

        Cell newCell = candidates[choice1].reproduce(candidates[choice2]);

        members.push_back(newCell);
    }

    generation++;
    calculateBestCell();
}

void Population::generateCandidates(){
    candidates.clear();

    for(int i = 0; i < size; i++){
        for(int j = 0; j < members[i].getFitness(); j++){
            candidates.push_back(members[i]);
        }
    }
}

void Population::calculateBestCell(){
    int bestFitness = members[0].getFitness();
    int bestIndex = 0;

    for(int i = 0; i < size; i++){
        if(members[i].getFitness() > bestFitness){
            bestFitness = members[i].getFitness();
            bestIndex = i;
        }
    }

    bestCell = members[bestIndex];
}
void Population::checkFinished(){
    calculateBestCell();

    if(bestCell.getDNA() == target){
        finished = true;
    }else{
        finished = false;
    }
}
