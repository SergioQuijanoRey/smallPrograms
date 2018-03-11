/**
 * @file functions.cpp
 * @author Sergio Quijano Rey
 */
#include "functions.h"
#include<stdlib.h>
#include<time.h>
using namespace std;

void startRandom(){
     srand(time(NULL));
}
int randomInt(int min, int max){
     int value =  min + rand() % (max +1 - min) ;
     return value;
}