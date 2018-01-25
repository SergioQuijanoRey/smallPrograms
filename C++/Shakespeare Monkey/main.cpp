#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

//FUNCTIONS
void clearScreen(){
    system("clear");
}
void delay(int miliseconds){
    usleep(1000 * miliseconds);
}

void startRandom(){
    srand(time(NULL));
}

int randomInt(int min, int max){
    int value =  min + rand() % (max +1 - min) ;
    return value;
}

//CLASS CELL
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
    Cell reproduce(Cell cell2){
        Cell child(target, false);
        int choice;
        int mutationChoice;
        char dnaFragment;
        string completeDNA;

        for(int i = 0; i < size; i++){
            choice = randomInt(0,1);
            mutationChoice = randomInt(0, 100);

            if(choice = 0){
                dnaFragment = DNA[i];
            }else{
                completeDNA = cell2.getDNA;
                dnaFragment = completeDNA[i];
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

//CLASS POPULATION
class Population{
public:
    //Constructors
    Population(int _size, string _target){
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
    void displayInfo() const{
        cout << "Generation: " << generation << endl;
        cout << "The best representant is: " << bestCell.getDNA() << endl;
        cout << "The rest of the population is:" << endl;

        for(int i = 0; i < size; i++){
            cout << "\t" <<  population[i].getDNA() << endl;
        }
    }

    //Get methods
    bool getFinished() const{
        return finished;
    }

    Cell getBestCell() const{
        return bestCell;
    }

    //Modifiers
    void calculateBestCell(){
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

    void nextGeneration(){
        generateCandidates();

        int index1 = randomInt(0, candidates.size());
        int index2 = randomInt(0, candidates.size());

        population.clear();

        Cell newCell = candidates[index1].reproduce(candidates[index2]);
        population.push_back(newCell);

        calculateBestCell();

        generation++;
    }

    void generateCandidates(){
        int fit;

        candidates.clear();

        for(int i = 0; i < size; i++){
            fit = population[i].getFitness() + 1;    //The lowest fitness is 1
            for(int j = 0; j < fit; j++){
                candidates.push_back(population[i]);
            }
        }
    }

    void checkFinished(){
        if(bestCell.getDNA() == target){
            finished = true;
        }
    }

private:
    int size;
    int generation;
    string target;
    bool finished;
    vector<Cell> population;
    vector<Cell> candidates;
    Cell bestCell;

};

//MAIN FUNCTION
int main(){
    const double mutationRate = 0.05;
    const int sizeOfPopulation = 200;
    const string target = "Ser o no ser, esa es la cuestion";
    const int delayTime = 3000;

    //Random integer generation is started;
    startRandom();

    //The genetic algorithm starts
    Population population(sizeOfPopulation, target);

    while(population.getFinished() == false){
        clearScreen();
        population.displayInfo();
        population.nextGeneration();
        population.checkFinished();

        delay(delayTime);
    }

    cout << "The result is: " << population.getBestCell().getDNA() << endl;
}
