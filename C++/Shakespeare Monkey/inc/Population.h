#ifndef _POPULATION_H_
#define _POPULATION_H_

class Population{
public:
    //CONSTRUCTORS
    Population();

    //DESTRUCTORS
    ~Population();

    //GETTERS
    int get_mutation_rate() const;
    int get_size();
    std::string get_target() const;

    //SETTERS
    void change_target(std::string new_target);
    void change_size(int change);

    //GENETIC METHODS
    void new_population();
    Cell get_best_cell() const;

    //OPERATORS' OVERLOAD
    friend ostream& operator<<() const;

private:
    int mutation_rate;
    int size;
    std::string target;
    Cell * cells;
};

#endif
