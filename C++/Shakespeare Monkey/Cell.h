#include <string>
using namespace std;

class Cell{
public:
    //Constructor
    Cell(string _target, bool randomGenerate);

    //Get methods
    string getDNA() const;
    char getFragment(int index) const;

    //Modifiers
    void calculateFitness();
    void generateRandomDNA();
    void changeDNA(string newDNA);
    int getFitness();

    //Observers
    Cell reproduce(Cell cell2);

private:
    string DNA;
    string target;
    int fitness;
    int size;
    static const int mutationRate = 5;
};
