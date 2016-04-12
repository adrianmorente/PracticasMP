
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o
	g++ -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp
	g++ -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -Iinclude/

$(BIN)/testplano: $(SRC)/testplano.o
	g++ -o $(BIN)/testplano $(OBJ)/testplano.o

$(OBJ)/testplano.o: $(SRC)/testplano.cpp
	g++ -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -Iinclude/

$(BIN)/arteASCII: $(OBJ)/arteASCII.o
	g++ -o $(BIN)/arteASCII $(OBJ)/arteASCII.o

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp
	g++ -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -Iinclude/

$(BIN)/testimagen: $(OBJ)/testimagen.o
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp
	g++ -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -Iinclude/

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper: clean
	rm -f $(BIN)/*
