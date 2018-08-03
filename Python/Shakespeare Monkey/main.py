import os
from Population import Population

#Some configuration
target = "To be or not to be"
size = 200
mrate = 0.2
step_by_step = False
show_info = False

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