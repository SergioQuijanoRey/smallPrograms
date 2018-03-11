/**
 * @file Cell.h
 * @author Sergio Quijano Rey
 */
#ifndef CELL_H
#define CELL_H

class Cell {
public:
    //Constructors
    Cell();
    Cell(std::string _target, int _mutationRate, bool create);
    
    //Observers
    void show() const;
    
    //Modifiers
    void randomDNA(int DNAsize);
    
private:
    std::string target;
    std::string DNA;
    int len;
    int mutationRate;
};

#endif /* CELL_H */

