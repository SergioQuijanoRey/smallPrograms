import random
import utilities

#Class cell
class Cell:
    def __init__(self, _target, _random = False):
        self.target = _target
        self.mutationrate = 5
        self.random = _random
        self.size = len(self.target)
        self.DNA = ""

        if self.random:
            self.generateRandom()

    def generateRandom(self):
        for x in range(0, self.size):
            asciiNum = random.randint(32,127)
            newchar = chr(asciiNum)

            self.DNA += newchar

    def reproduce(self, cell2):
        maxSize = utilities.getMax(self.size, cell2.size)
        newCell = Cell(self.target)

        for x in range(0, maxSize):
            choice = random.randint(0,1)

            if choice == 0:
                newchar = self.getDNAFragment(x)
            else:
                newchar = cell2.getDNAFragment(x)

            newCell.DNA.append(newChar)

        return newCell

    def getDNAFragment(index):
        election = random.randint(0, 100)

        if election < self.mutationrate:    #The DNA mutates
            asciiNum = random.randint(32,127)
            char = chr(asciiNum)
        else:
            char = self.DNA[index]

        return char

    def fitness(self):
        fitVal = 0

        for x in self.DNA.size():
            if self.DNA[x] == self.target[x]:
                fitVal = fitVal + 1

        return fitVal
