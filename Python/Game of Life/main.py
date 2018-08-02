import os
from MyClasses import Gameboard
import Combinations as cb

game = Gameboard(30, 80, cb.acorn)
limit = 200

for x in range(0, limit):
    os.system("clear")
    print(game)
    game.next_generation()