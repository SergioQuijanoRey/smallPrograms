CFLAGS = "-std=c++11"
#Program compilation
all: main

main: main.o
	g++ $(CFLAGS) main.cpp Grid.cpp -o main

#Other utilities
exe:
	./main

clean:
	@rm *.o

cleanAll:
	@rm *.o main
