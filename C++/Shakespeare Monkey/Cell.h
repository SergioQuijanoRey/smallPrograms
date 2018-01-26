#include <iostream>
#include <vector>
#include <string>
#include "Functions.h"
using namespace std;

class Cell{
public:
    //Constructors
    Cell(string _target, bool random){
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
    string getDNA() const{
        return DNA;
    }

    int getFitness(){
        calculateFitness();
        return fitness;
    }

    //Modifiers
    void calculateFitness(){
        int fit = 0;

        for(int i = 0; i < size; i++){
            if(DNA[i] == target[i]){
                fit++;
            }
        }

        fitness = fit;
    }

    void addDNA(char newFragment){
        DNA += newFragment;
    }

    //Observers
    static Cell reproduce(Cell cell1, Cell cell2){
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

private:
    string DNA;
    string target;
    int size;
    double fitness;
    static const double mutationRate = 5;
};
