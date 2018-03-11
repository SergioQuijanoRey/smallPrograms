/**
 * @file Population.h
 * @author Sergio Quijano Rey
 */

#ifndef POPULATION_H
#define POPULATION_H

class Population {
public:
    //Constructors
    /**
     * @brief Default constructor 
     */
    Population();
    Population(std::string _target, int _size, int _mutationRate);
    
    //Observers
    void show() const;
    
    //Modifiers
    void startPopulation();
    
private:
    std::string target;
    int size;
    int mutationRate;
    std::vector<Cell> pop;
};

#endif /* POPULATION_H */

