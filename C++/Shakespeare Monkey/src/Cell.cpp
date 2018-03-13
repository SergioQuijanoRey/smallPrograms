#include "Cell.h"
using namespace std;

//CONSTRUCTORS
Cell::Cell(){
    target = "Nothing to say";
    size = target.size();
    mutationRate = 5;
    fitness = 0;

    randomDNA();
}

Cell::Cell(std::string _target, int _mutationRate, bool randomize){
    target = _target;
    mutationRate = _mutationRate;
    size = target.size();
    fitness = 0;

    if(randomize){
        randomDNA();
    }else{
        DNA = "";
    }
}

//MODIFIERS
void Cell::calculateFitness(){
    fitness = 0;

    for(int i = 0; i < size; i++){
        if(DNA[i] == target[i]){
            fitness++;
        }
    }
}

void Cell::randomDNA(){
    char carIn;

    for(int i = 0; i < size; i++){
        carIn = randomInt('A', 'z');
        DNA+=carIN;
    }
}
    