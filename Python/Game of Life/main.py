import os
from MyClasses import Gameboard
import Combinations as cb

game = Gameboard(30, 80, cb.acorn)
limit = 2000

for x in range(0, limit):
    os.system("clear")
    print(game)
    input("ENTER:")
    game.next_generation()