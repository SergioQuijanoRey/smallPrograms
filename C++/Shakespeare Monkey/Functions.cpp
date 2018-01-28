#include "Functions.h"

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
