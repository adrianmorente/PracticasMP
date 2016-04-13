
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/testimagen $(BIN)/testplano $(BIN)/arteASCII $(BIN)/testarteASCII

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(OBJ)/imagen.o
	$(CXX) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o $(OBJ)/imagen.o

$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(OBJ)/imagen.o
	$(CXX) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o $(OBJ)/imagen.o

$(BIN)/testimagen: $(OBJ)/testimagen.o $(OBJ)/imagen.o
	$(CXX) -o $(BIN)/testimagen $(OBJ)/testimagen.o $(OBJ)/imagen.o

$(BIN)/testplano: $(OBJ)/testplano.o $(OBJ)/imagen.o
	$(CXX) -o $(BIN)/testplano $(OBJ)/testplano.o $(OBJ)/imagen.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
		$(CXX) $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o

$(OBJ)/testplano.o: $(SRC)/testplano.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testplano.cpp -o $(OBJ)/testplano.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o

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
