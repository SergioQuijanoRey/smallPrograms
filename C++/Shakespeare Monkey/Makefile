#Compilation Vars
#==============================================================================
#Direcories and names
INC = ./includes
SRC = ./src
BIN = ./bin
OBJ = ./obj
PRJ = main

OPT = -Wall -g

#Compilation
#==============================================================================
all: $(BIN)/$(PRJ)

$(BIN)/$(PRJ): $(OBJ)/Cell.o $(OBJ)/Population.o $(OBJ)/main.o $(OBJ)/functions.o $(INC)/Cell.h $(INC)/Population.h $(INC)/functions.h
	g++ $(OPT) -I(INC) $(OBJ)/Cell.o $(OBJ)/Population.o $(OBJ)/main.o $(OBJ)/functions.o -o $(BIN)/$(PRJ) 

$(OBJ)/main.o: $(SRC)/main.cpp
	g++ $(OPT) -I$(INC) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/Cell.o: $(SRC)/Cell.cpp $(INC)/Cell.h $(INC)/functions.h
	g++ $(OPT) -I$(INC) -c $(SRC)/Cell.cpp -o $(OBJ)/Cell.o

$(OBJ)/Population.o: $(SRC)/Population.cpp $(INC)/Population.h $(INC)/functions.h $(INC)/Cell.h
	g++ $(OPT) -I$(INC) -c $(SRC)/Population.cpp -o $(OBJ)/Population.o

$(OBJ)/Functions.o: $(SRC)/Functions.cpp $(INC)/functions.h
	g++ $(OPT) -I$(INC) -c $(SRC)/Functions.cpp -o $(OBJ)/Functions.o



#Utilities
#==============================================================================
exe: all
	@$(BIN)/$(PRJ)

clean:
	@rm -rf $(OBJ)/*

cleanAll:
	@rm -rf $(OBJ)/* $(BIN)/*