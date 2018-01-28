import random
from Cell import *

class Population:
    def __init__(self, _target, _size):
        self.target = _target
        self.size = _size
        self.finished = False

        self.members = []
        self.candidates = []

        #When a Population is created, a random set of cells is created
        self.startPopulation()

    def startPopulation(self):
        for x in range(0, self.size):
            newCell = Cell(self.target, True)
            self.candidates.append(newCell)

    def generateCandidates(self):
        self.candidates.clear()

        for cell in self.members:
            #I add n times the given cell, depending on its fitness
            for x in range(0, cell.fitness()):
                self.candidates.append(cell)

    def newGeneration(self):
        self.generateCandidates()
        self.memebers.clear()

        for x in range(0, self.size):
            index1 = random.randint(0, self.candidates.size())
            index2 = random.randint(0, self.candidates.size())

            newCell = self.memebers[index1].reproduce(self.candidates[index2])
            self.memebers.append(newCell)

            del self.memebers[index1]
            del self.memebers[index2]

    def checkFinished(self):
        self.calculateBestCell()

        if self.bestCell.DNA == self.target:
            self.finished = True


    def calculateBestCell(self):
        currentBestCell = self.members[0]
        bestFit = self.members[0].fitness()

        for cell in self.memebers:
            fitVal = cell.fitness()

            if fitVal > bestFit:
                bestFit = fitVal
                currentBestCell = cell

        self.bestCell = currentBestCell

    def show(self):
        self.calculateBestCell()

        print("The best coincidence is:", self.bestCell)
        print("This are the cells in our population:")

        for cell in self.memebers:
            dna = cell.DNA

            print("\t", dna)
