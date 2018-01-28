import random
from Cell import *

class Population:
    def __init__(self, _target, _size):
        self.target = _target
        self.size = _size
        self.finished = False
        self.generation = 1

        self.members = []
        self.candidates = []

        #When a population is created, all of its cells are randomly generated
        self.startPopulation()

        #We calculate which cell is the best (as members is empty, this cell is random)
        self.bestCell = self.calculateBestCell()

    def startPopulation(self):
        for x in range(0, self.size):
            newCell = Cell(self.target, True)
            self.members.append(newCell)

    def generateCandidates(self):
        self.candidates.clear()

        for cell in self.members:
            #I add n times the given cell, depending on its fitness
            for x in range(0, cell.fitness()):
                self.candidates.append(cell)

    def newGeneration(self):
        self.generateCandidates()
        self.members.clear()

        topIndex = len(self.candidates) - 1

        for x in range(0, self.size):
            index1 = random.randint(0, topIndex)
            index2 = random.randint(0, topIndex)

            newCell = Cell(self.target, True)
            newCell.reproduce(self.candidates[index1], self.candidates[index2])

            self.members.append(newCell)

            del self.candidates[index1]
            del self.candidates[index2]

            topIndex = topIndex - 2


        generation = generation + 1

    def checkFinished(self):
        self.calculateBestCell()

        if self.bestCell.DNA == self.target:
            self.finished = True


    def calculateBestCell(self):
        currentBestCell = self.members[0]
        bestFit = self.members[0].fitness()

        for cell in self.members:
            fitVal = cell.fitness()

            if fitVal > bestFit:
                bestFit = fitVal
                currentBestCell = cell

                self.bestCell = currentBestCell


    def show(self):
        print("Generation:", self.generation)
        print("Population:", self.size)
        print("This are the cells in our population:")

        for cell in self.members:
            print("\t", cell.DNA)
