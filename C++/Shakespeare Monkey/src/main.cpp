/**
* @file main.cpp
* @author Sergio Quijano Rey 
*/

#include <iostream>
#include <string>
#include "Population.h"
#include "Cell.h"
using namespace std;

int main(){
    string target = "To be or not to be, that's the question";
    int popSize = 300;
    int mutRate = 5;
    
    Population population(target, popSize, mutRate);
    population.show();    
}