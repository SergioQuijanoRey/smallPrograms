from Cell import *
from Population import *

#Problem variables
target = "Ser o no ser, esa es la cuestion"
popSize = 200

population = Population(target, popSize)

while population.finished == False:
    population.show()
    population.newGeneration()
    population.checkFinished()


print("The result is:", population.bestCell.DNA)
