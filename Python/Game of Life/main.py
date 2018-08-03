#Author:
#   Sergio Quijano Rey
#   sergiquijano@gmail.com
#Version:
#   v1.0 3th August 2018 - First version

import os
from MyClasses import Gameboard
import Combinations as cb

#Some configuration
num_rows = 30
num_cols = 80
max_generations = 200
step_by_step = False

#The actual game runs
game = Gameboard(num_rows, num_cols, cb.acorn)
for _ in range(max_generations):
    os.system("clear")
    print(game)
    game.next_generation()

    if step_by_step:
        input("Press ENTER to continue")