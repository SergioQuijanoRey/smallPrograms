from Cell import *
from Population import *

#Problem variables
target = "Ser o no ser, esa es la cuestion"
popSize = 10

population = Population(target, popSize)
population.show()

while population.finished == False:
    population.show()
    population.newGeneration()
    population.checkFinished()


print("The result is:", population.bestCell.DNA)
