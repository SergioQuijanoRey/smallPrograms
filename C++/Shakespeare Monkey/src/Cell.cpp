#include "Cell.h"
using namespace std;

//CONSTRUCTORS
//==============================================================================
Cell::Cell(){
    dna = "";
    target = "";
    fitness = 0;
}

Cell::Cell(std::string _target){
    dna = "";
    target = _target;
    fitness = 0;
}

Cell(const Cell & cell1, const Cell & cell2, int mutation_rate){
    
}

    //GETTERS
    std::string get_dna() const;
    std::string get_target() const;
    int get_fitness() const;

    //SETTERS
    void change_target(std::string new_target);
    void calculate_fitness();

    //OPERATORS' OVERLOAD
    friend istream& operator<<() const;

private:
    std::string dna;
    std::string target;
    int fitness;
};
