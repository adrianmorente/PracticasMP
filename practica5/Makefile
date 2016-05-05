
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC) -std=c++11


all: $(OBJ) $(BIN) $(BIN)/testimagen $(BIN)/arteASCII2 $(BIN)/testarteASCII

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	$(CXX) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

$(BIN)/arteASCII2: $(OBJ)/arteASCII2.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	$(CXX) -o $(BIN)/arteASCII2 $(OBJ)/arteASCII2.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

$(BIN)/testimagen: $(OBJ)/testimagen.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	$(CXX) -o $(BIN)/testimagen $(OBJ)/testimagen.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
		$(CXX) $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/lista.cpp -o $(OBJ)/lista.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o

$(OBJ)/arteASCII2.o: $(SRC)/arteASCII2.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o

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
	rm -f *.pgm
	rm -f ascii*
