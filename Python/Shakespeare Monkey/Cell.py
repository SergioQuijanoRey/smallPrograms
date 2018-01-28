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

    def reproduce(self, cell1, cell2):
        length = len(self.DNA) - 1
        copy = self.DNA
        self.DNA = ""

        for x in range(0, length):
            choice = random.randint(0,1)

            if choice == 0:
                self.DNA += self.getDNAFragment(x, copy)
            else:
                self.DNA += cell2.getDNAFragment(x, copy)

    def getDNAFragment(self, index, text):
        election = random.randint(0, 100)

        if election < self.mutationrate:    #The DNA mutates
            asciiNum = random.randint(32,127)
            char = chr(asciiNum)
        else:
            char = text[index]

        return char

    def fitness(self):
        fitVal = 0

        for x in range(0, len(self.DNA)):
            if self.DNA[x] == self.target[x]:
                fitVal = fitVal + 1

        return fitVal
