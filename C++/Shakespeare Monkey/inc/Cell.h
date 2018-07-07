#ifndef _CELL_H_
#define _CELL_H_

class Cell{
public:
    //CONSTRUCTORS
    Cell();
    Cell(std::string _target);
    Cell(const Cell & cell1, const Cell & cell2, int mutation_rate);

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

#endif
