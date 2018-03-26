#ifndef _CELL_H_
#define _CELL_H_

#include <string>

class Cell{
public:
    //Constructors
    Cell();
    Cell(std::string _target, int _mutationRate, bool newCell, std::string _DNA);
   
    //Modifiers
    void createRandomDNA();
    void calculateFitness();
    void returnCells(Cell temp[]);
    
    //Operators
    void operator=(Cell OtherCell);
    
    //Getters
    int getFitness() const;
    std::string getDNA() const;
    std::string getTarget() const;
    int getMutationRate() const;
    
    //Observers
    void show() const;
    Cell reproduce(Cell otherCell) const;
    
private:
    int size;
    int fitness;
    std::string target;
    std::string DNA;
    int mutationRate;
};

#endif