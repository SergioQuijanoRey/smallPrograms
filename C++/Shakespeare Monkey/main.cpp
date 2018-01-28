#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Population.h" //Population object
#include "Functions.h"  //Some utilities
using namespace std;

int main(){
    const string target = "To be or not to be, that's the question";
    const int popSize = 10;
    const int delayTime = 1000; //Delay time in miliseconds

    Population population(target, popSize);

    while(population.getFinished() == false){
        clearScreen();

        population.nextGen();
        population.show();
        population.checkFinished();

        delayMili(delayTime);
    }
}
