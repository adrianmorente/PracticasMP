#Makefile BUSCAMINAS
.PHONY: clean
CXX = g++
CXXFLAGS =-Wall -g -I $(INC)
INC = include
SRC = src
OBJ = obj
BIN = bin

all: $(BIN) $(OBJ) $(BIN)/buscaminas

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

# ************ Compilación de módulos ************
$(BIN)/buscaminas : $(OBJ)/buscaminas.o $(OBJ)/campominas.o $(OBJ)/tablero.o
	$(CXX) -o $(BIN)/buscaminas $(OBJ)/buscaminas.o $(OBJ)/campominas.o $(OBJ)/tablero.o
$(OBJ)/campominas.o : $(SRC)/campominas.cpp $(INC)/campominas.h
	$(CXX) $(CXXFLAGS) $(SRC)/campominas.cpp -c -o $(OBJ)/campominas.o
$(OBJ)/tablero.o : $(SRC)/tablero.cpp $(INC)/tablero.h
	$(CXX) $(CXXFLAGS) $(SRC)/tablero.cpp -c -o $(OBJ)/tablero.o
$(OBJ)/buscaminas.o : $(SRC)/buscaminas.cpp
	$(CXX) $(CXXFLAGS) $(SRC)/buscaminas.cpp -c -o $(OBJ)/buscaminas.o

clean:
	echo "Limpiando..."
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
