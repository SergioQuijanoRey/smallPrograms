all: main

main: main.o functions.o
	g++ -I./ main.o functions.o -o main

main.o: main.cpp functions.h
	g++ -c -I./ main.cpp

functions.o: functions.h
	g++ -c -I./ functions.cpp

clean:
	rm *.o

cleanAll:
	rm *.o main

exe: main
	./main
