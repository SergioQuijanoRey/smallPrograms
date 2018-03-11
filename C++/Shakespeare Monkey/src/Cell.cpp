#include "Cell.h"
#include <string>
using namespace std;

//CONSTRUCTORS
Cell::Cell(){
    target = "Nothing to say";
    mutationRate = _mutationRate;
    randomDNA(target.size());
}

Cell::Cell(string _target, int _mutationRate, bool create){
    target = _target;
    mutationRate = _mutationRate;
    
    if(create){
        randomDNA(len);
    }else{
        DNA = "";
        len = 0;
    }
}
   
//OBSERVERS
void Cell::show() const{
    for(int i = 0; i < len; i++){
        cout << DNA[i];
    }
}

//MODIFIERS
void Cell::randomDNA(int DNAsize){
    char carIn;
    
    //DNA is cleaned
    DNA = "";
    
    //Random DNA is generated
    for(int i = 0; i < DNAsize; i++){
        carIn = randomInt(65, 122);
        DNA += carIn;
    }
    
    len = DNAsize;
}