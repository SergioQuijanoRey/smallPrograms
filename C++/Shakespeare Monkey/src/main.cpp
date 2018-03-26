/**
 * @file main.cpp
 * @brief main file of the program
 * @author Sergio Quijano Rey
 */

#include <iostream>
#include <string>
#include "Population.h"
#include "Functions.h"
using namespace std;

int main(){
    string target = "To be or not to be";
    int mutationRate = 10;
    int size = 100;
    
    //Random numbers are now available
    startRandom();
    
    //The population is created
    Population population(target, size, mutationRate);
    int controlador = 0;
    while(population.getFinished() == false && controlador < 200){
        population.show();
        population.getNextGen();
        population.checkFinished();
        
        controlador++;
    }
}