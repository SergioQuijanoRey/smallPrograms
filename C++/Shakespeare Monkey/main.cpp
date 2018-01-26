#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Population.h"
using namespace std;

//FUNCTIONS

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
