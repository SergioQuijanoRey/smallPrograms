#Variables
CC = "g++"
CFLAGS = "-std=c++14"

#Binaries compilation
all: main

main: main.o Functions.o Cell.o Population.o
	$(CC) $(CFLAGS) main.o Functions.o Cell.o Population.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Functions.o: Functions.cpp Functions.h
	$(CC) $(CFLAGS) -c Functions.cpp

Cell.o: Cell.h Cell.cpp
	$(CC) $(CFLAGS) -c Cell.cpp

Population.o: Population.h Population.cpp
	$(CC) $(CFLAGS) -c Population.cpp

#Utilities:
exe: main
	./main

clean:
	rm *.o

cleanAll:
	rm main *.o
