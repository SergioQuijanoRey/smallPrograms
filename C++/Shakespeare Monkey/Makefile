#PARAMETERS FOR COMPILING
OPTIONS = "-g"
INCLUDE = "-I./inc"
BINARYFILE = "./bin/shmonkey"
EXEPARAMETERS = ""

#COMPILATION
all: $(BINARYFILE)

$(BINARYFILE): ./obj/main.o ./obj/Cell.o ./obj/Population.o
	g++ $(OPTIONS) $(INCLUDE) ./obj/main.o ./obj/Cell.o ./obj/Population.o -o $(BINARYFILE)

./obj/main.o: ./src/main.cpp ./inc/Cell.h ./inc/Population.h
	g++ $(OPTIONS) $(INCLUDE) -c ./src/main.cpp -o ./obj/main.o

./obj/Cell.o: ./src/Cell.cpp ./inc/Cell.h
	g++ $(OPTIONS) $(INCLUDE) -c ./src/Cell.cpp -o ./obj/Cell.o

./obj/Population.o: ./src/Population.cpp ./inc/Population.h ./inc/Cell.h
	g++ $(OPTIONS) $(INCLUDE) -c ./src/Population.cpp -o ./obj/Population.o

#UTILITIES
clean:
	rm ./obj/* ./bin/* ./zip/*

valexe: $(BINARYFILE)
	valgrind --leak-check=full $(BINARYFILE) $(EXEPARAMETERS)
