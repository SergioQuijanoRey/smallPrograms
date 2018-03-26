#include "Functions.h"
#include<stdlib.h>
#include<time.h>

void startRandom(){
    srand(time(NULL));     //Inicializo los numeros aleatorios
}
int randomInt(int min, int max){
    int value =  min + rand() % (max +1 - min) ;
    return value;
}