class Gameboard:
    def __init__(self, rows, cols, starting_points):
        self.rows = rows
        self.cols = cols
        self.grid = []
        self.next_grid = []
        self.population = 0
        self.generation = 0

        #Start the board
        self.create_grid()
        self.put_cells(starting_points)

    def __str__(self):
        data = "Generation: {}\n".format(self.generation)
        data = data + "Population: {}\n".format(self.population)
        data = data + "==================================\n"
        for row in range(0, self.rows):
            new_line = ""
            for col in range(0, self.cols):
                new_line = new_line + self.grid[row][col]
            
            new_line = new_line + "\n"
            data = data + new_line

        return data    

    def create_grid(self):
        column = ["X" for x in range(0, self.cols)] 
        for x in range(0, self.rows):
            self.grid.append(column[:])

    def put_cells(self, starting_points):
        """Cells are put, in a list of format [row, col]"""

        for cordinates in starting_points:
            row = cordinates[0]
            col = cordinates[1]
            
            if 0 <= row < self.rows and 0 <= col < self.cols:
                self.grid[row][col] = "O"

    def next_generation(self):
        self.next_grid = self.grid[:]

        for row in range(0, self.rows):
            for col in range(0, self.cols):
                alive_cells_around = self.count_alive_cells(row, col)
                
                if self.next_grid[row][col] == "X" and alive_cells_around >= 3:
                    self.grid[row][col] = "O"
                elif self.next_grid[row][col] == "O" and not (alive_cells_around == 2 or alive_cells_around == 3):
                    self.grid[row][col] = "X"

        #Some updates are made
        self.generation = self.generation + 1
        self.population = self.count_population()
        
    def count_alive_cells(self, row, col):
        counter = 0

        for x in [-1, 0, 1]:
            for y in [-1, 0, 1]:
                other_row = row + y
                other_col = col + x

                #Check if we reach borders
                if 0 <= other_row < self.rows and 0 <= other_col < self.cols:
                    if self.next_grid[other_row][other_col] == "O":
                        counter += 1
        
        if self.next_grid[row][col] == "O":
            counter = counter - 1

        return counter

    def count_population(self):
        pop = 0

        for row in range(0, self.rows):
            for col in range(0, self.cols):
                if self.grid[row][col] == "O":
                    pop = pop + 1

        return pop