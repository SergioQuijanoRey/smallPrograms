#include "Functions.h"
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

void startRandom(){
    srand(time(NULL));
}
int randomInt(int min, int max){
    int value =  min + rand() % (max +1 - min) ;
    return value;
}

void sleepMili(int miliseconds){
    usleep(miliseconds * 1000);
}

void cleanScreen(){
    system("clear");
}
