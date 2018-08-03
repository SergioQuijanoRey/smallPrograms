import random
import string

class Cell:
    def __init__(self, target):
        self.target = target
        self.dna = ""
        self.fitness = 0
    
    def __str__(self):
        data = "Dna: {}, fitness: {}".format(self.dna, self.fitness)
        return data

    def calculate_fitness(self):
        """Calculates the fitness of the cell"""
        self.fitness = 0
        for idx, char in enumerate(self.dna):
            if char == self.target[idx]:
                self.fitness = self.fitness + 1
    
    def random_dna(self):
        """Generates a random dna sequence from scratch"""
        self.dna = ""
        for _ in range(len(self.target)):
            new_char = random.choice(string.ascii_letters)
            self.dna = self.dna + new_char

    def reproduce(self, other_cell, mutation_rate):
        """Generates a new cell

        Args:
            self: the cell itself
            other_cell: other cell
            mutation_rate: probability of changin de DNA

        Return:
            A new cell"""


        child = Cell(self.target)
        child_dna = ""

        for idx, char in enumerate(self.dna):
            if random.random() < mutation_rate: #Mutation happens
                child_dna = child_dna + random.choice(string.ascii_letters)
            else:
                choice = random.randint(0,1)   
                if choice == 0:
                    child_dna = child_dna + self.dna[idx]
                else:
                    child_dna = child_dna + other_cell.dna[idx]

        #Child's parameters are set
        child.dna = child_dna
        child.calculate_fitness()
        return child