#Makefile bloqueLed
#
# Uso: 'make'

BIN = bin
INC = include
SRC = src
OBJ = obj
LIB = lib

all: $(BIN) $(OBJ) $(BIN)/bloqueLed

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN)/bloqueLed: $(OBJ)/bloqueLed.o $(OBJ)/main.o
	g++ -o $(BIN)/bloqueLed $(OBJ)/bloqueLed.o $(OBJ)/main.o

$(OBJ)/bloqueLed.o: $(SRC)/bloqueLed.cpp
	g++ -c $(SRC)/bloqueLed.cpp -o $(OBJ)/bloqueLed.o -Iinclude/

$(OBJ)/main.o: $(SRC)/main.cpp
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -Iinclude/

clean:
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/bloqueLed
