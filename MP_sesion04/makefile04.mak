# Make file de Práctica 4

AUTOR = Marco

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

#......................................

all: presentacion $(BIN)/I_DEMO $(BIN)/I_EncuentraInicioPalabras \
	 clean
	@echo Terminado


#......................................
# EJECUTABLES

$(BIN)/I_EncuentraInicioPalabras : $(OBJ)/I_EncuentraInicioPalabras.o \
								   $(OBJ)/MiCadenaClasica.o \
								   $(LIB)/libMiCadenaClasica.a
	g++ -o $(BIN)/I_EncuentraInicioPalabras $(OBJ)/I_EncuentraInicioPalabras.o \
	$(OBJ)/MiCadenaClasica.o -lMiCadenaClasica -L$(LIB)

$(BIN)/I_DEMO : $(OBJ)/I_DEMO.o \
						   $(OBJ)/MiCadenaClasica.o \
						   $(LIB)/libMiCadenaClasica.a
	g++ -o $(BIN)/I_DEMO $(OBJ)/I_DEMO.o \
	$(OBJ)/MiCadenaClasica.o -lMiCadenaClasica -L$(LIB)


#......................................
# OBJETOS
	
$(OBJ)/I_DEMO.o : $(SRC)/I_DEMO.cpp \
						  	 $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/I_DEMO.o $(SRC)/I_DEMO.cpp \
	-I./include -std=c++11

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp \
						   $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp \
	-I./include -std=c++11

$(OBJ)/I_EncuentraInicioPalabras.o : $(SRC)/I_EncuentraInicioPalabras.cpp \
								     $(INCLUDE)/MiCadenaClasica.h
	g++ -c -o $(OBJ)/I_EncuentraInicioPalabras.o \
	$(SRC)/I_EncuentraInicioPalabras.cpp -I./include -std=c++11


#......................................
# BIBLIOTECAS

$(LIB)/libMiCadenaClasica.a : $(OBJ)/MiCadenaClasica.o
	ar rvs $(LIB)/libMiCadenaClasica.a $(OBJ)/MiCadenaClasica.o 

#......................................
# LIMPIEZA


clean:
	-rm $(OBJ)/*
	@echo objetos eliminados
		
mr.proper: clean
	-rm $(BIN)/*
	@echo ejecutables eliminados
	-rm $(LIB)/*
	@echo librerias eliminadas

presentacion:
	@echo El autor de este software es: $(AUTOR)