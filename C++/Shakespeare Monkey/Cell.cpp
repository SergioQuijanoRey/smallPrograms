#include "Cell.h"
#include "Functions.h"

//Constructor
Cell::Cell(string _target, bool randomGenerate){
    target = _target;
    size = target.size();
    DNA = "";

    if(randomGenerate == true){
        generateRandomDNA();
    }
}

//Get methods
string Cell::getDNA() const{
    return this->DNA;
}

char Cell::getFragment(int index) const{
    int election = randomInt(0, 100);
    char fragment;

    if(election < mutationRate){    //This DNA fragment mutates
        fragment = randomInt(32, 127);
    }else{
        fragment = DNA[index];
    }

    return fragment;
}

//Modifiers
void Cell::calculateFitness(){
    int fitVal = 0;

    for(int i = 0; i < size; i++){
        if(DNA[i] == target[i])
            fitVal++;
    }

    fitness = fitVal;
}

void Cell::generateRandomDNA(){
    startRandom();
    char randomChar;

    DNA.clear();

    for(int i = 0; i < size; i++){
        randomChar = randomInt(32, 127);
        DNA.push_back(randomChar);
    }
}

void Cell::changeDNA(string newDNA){
    DNA = newDNA;
}

int Cell::getFitness(){
    calculateFitness();
    return fitness;
}

//Observers
Cell Cell::reproduce(Cell cell2){
    Cell newCell(target, true);
    string mixedDNA = "";
    int choice;
    char newChar;

    for(int i = 0; i < size; i++){
        choice = randomInt(0,1);

        if(choice == 0){
            newChar = getFragment(i);
        }else{
            newChar = cell2.getFragment(i);
        }

        mixedDNA.push_back(newChar);
    }

    newCell.changeDNA(mixedDNA);
    return newCell;
}
