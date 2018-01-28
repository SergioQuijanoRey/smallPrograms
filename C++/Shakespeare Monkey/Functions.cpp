#include "Functions.h"

void clearScreen(){
    system("clear");
}

void startRandom(){
    srand(time(NULL));
}
int randomInt(int min, int max){
     int value =  min + rand() % (max +1 - min) ;
     return value;
}

void delayMili(int miliseconds){
    usleep(miliseconds * 1000);
}
