#Primer fichero-makefile
AUTOR = Marco
HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

all: $(BIN)/saludo $(BIN)/saludo_en_dos_pasos
	@cho Terminado
	
presentacion:
	@echo Autor = $(AUTOR)
	
$(BIN)/saludo: $(SRC)/saludo.cpp
	g++ -o $(BIN)/saludo $(SRC)/saludo.cpp
	
$(OBJ)/saludo.o: $(SRC)/saludo.cpp
	g++ -c -o $(OBJ)/saludo.o $(SRC)/saludo.cpp
	
$(BIN)/saludo_en_dos_pasos: $(OBJ)/saludo.o
	g++ -o $(BIN)/saludo_en_dos_pasos $(OBJ)/saludo.o
	
mr.proper: clean
	-rm $(BIN)/*
	@echo Los ejecutables han sido eliminados
	-rm $(LIB)/*
	@echo Las $(LIB)rerias han sido eliminadas
	
clean:
	-rm $(OBJ)/*
	@echo $(OBJ)etos borrados
