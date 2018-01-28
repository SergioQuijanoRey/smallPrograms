#include "Cell.h"

//Constructors
Cell::Cell(string _target, bool random){
    target = _target;
    size = target.size();

    if(random == false){
        DNA = "";
    }else{
        for(int i = 0; i < size; i++){
            char charIn = randomInt(32, 126);
            DNA += charIn;
        }
    }
}

//Get methods
string Cell::getDNA() const{
    return DNA;
}

/*int Cell::getFitness() {
    this->calculateFitness();
    return fitness;
}*/

//Modifiers
void Cell::calculateFitness(){
    int fit = 0;

    for(int i = 0; i < size; i++){
        if(DNA[i] == target[i]){
            fit++;
        }
    }

    fitness = fit;
}

void Cell::addDNA(char newFragment){
    DNA += newFragment;
}

//Observers
Cell Cell::reproduce(Cell cell1, Cell cell2){
    Cell child(cell1.target, false);
    int choice;
    int mutationChoice;
    char dnaFragment;
    string completeDNA;

    for(int i = 0; i < cell1.size; i++){
        choice = randomInt(0,1);
        mutationChoice = randomInt(0, 100);

        if(choice = 0){
            dnaFragment = cell1.DNA[i];
        }else{
            dnaFragment = 'p';
        }

        if(mutationChoice < mutationRate){
            dnaFragment = randomInt(32, 126);
        }

        child.addDNA(dnaFragment);

    }

    return child;
}
