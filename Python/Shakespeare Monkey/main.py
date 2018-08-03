#Author:
#   Sergio Quijano
#   sergiquijano@gmail.com
#Version:
#   v1.0 3th August 2018 - First version

import os
from Population import Population

#Some configuration
target = "To be or"
size = 200
mrate = 0.2
step_by_step = True
show_info = True 

population = Population(target, size, mrate)
population.random_population()

if show_info:
    print(population)
if step_by_step:
    input("Press ENTER or \"exit\"")

usr = ""
while usr != "exit" and not population.finished:
    population.next_gen()
    population.check_finished()
    
    if show_info:
        print(population)
        os.system("clear")

    if step_by_step:
        usr = input("Press ENTER or \"exit\"")

#Results are shown
if population.finished == True:
    print("We hit the target")
    print("Correct cell | " + str(population.best_cell))
    print("Took {} generations".format(population.generation))
else:
    print("You exited the simulation")