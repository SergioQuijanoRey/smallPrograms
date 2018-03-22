#ifndef _CELL_H_
#define _CELL_H_

class Cell{
public:
    //Constructors
    Cell();
    Cell(std::string _target, int _mutationRate, bool newCell);
private:
    std::string target;
    std::string DNA;
    int mutationRate;
};

#endif