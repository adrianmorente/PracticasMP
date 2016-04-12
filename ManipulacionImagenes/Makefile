
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC) -std=c++11


all: $(BIN)/testarteASCII $(BIN)/arteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o
	$(CXX) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o

$(BIN)/testplano: $(OBJ)/testplano.o
	$(CXX) -o $(BIN)/testplano $(OBJ)/testplano.o

$(OBJ)/testplano.o: $(SRC)/testplano.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testplano.cpp -o $(OBJ)/testplano.o

$(BIN)/arteASCII: $(OBJ)/arteASCII.o
	$(CXX) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o

$(BIN)/testimagen: $(OBJ)/testimagen.o
	$(CXX) -o $(BIN)/testimagen $(OBJ)/testimagen.o

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper: clean
	rm -f $(BIN)/*
