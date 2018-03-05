#Compilation process
all: ./bin/main

./bin/main: ./Obj/main.o ./Obj/Functions.o ./Obj/Grid.o
	g++ -I./Includes ./Obj/main.o ./Obj/Functions.o ./Obj/Grid.o -o ./bin/main

./Obj/main.o: ./Source/main.cpp
	g++ -c -I./Includes ./Source/main.cpp -I./Includes -o ./Obj/main.o

./Obj/Functions.o: ./Source/Functions.cpp ./Includes/Functions.h
	g++ -c -I./Includes ./Source/Functions.cpp -o ./Obj/Functions.o

./Obj/Grid.o: ./Source/Grid.cpp ./Includes/Grid.h ./Includes/Functions.h
	g++ -c -I./Includes ./Source/Grid.cpp -o ./Obj/Grid.o

#Utilities
exe:
	./bin/main

clean:
	rm ./Obj/*

cleanAll:
	rm ./Obj/*
	rm ./bin/main
