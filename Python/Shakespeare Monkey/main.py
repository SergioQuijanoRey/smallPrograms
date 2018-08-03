from Population import Population

#Some configuration
target = "To be or not to be"
size = 200
mrate = 0.1
step_by_step = True

population = Population("Hola soy sergio", size, mrate)
population.random_population()
print(population)

population.get_candidates()

for idx, candidate in enumerate(population.candidates):
    print("Candidate {}: ".format(idx) + str(candidate))