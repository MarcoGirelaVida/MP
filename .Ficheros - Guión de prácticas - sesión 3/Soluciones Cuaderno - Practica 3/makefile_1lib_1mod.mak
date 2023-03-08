######################################################################### 
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2016-2017
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_1lib_1mod.mak
#
######################################################################### 

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(LIB)/libopers_1mod.a $(BIN)/ppal_1lib_1mod 


$(BIN)/ppal_1lib_1mod : $(OBJ)/ppal.o $(LIB)/libopers_1mod.a
	g++ -o $(BIN)/ppal_1lib_1mod $(OBJ)/ppal.o -lopers_1mod -L$(LIB)


$(OBJ)/ppal.o : $(SRC)/ppal.cpp $(INCLUDE)/opers_1mod.h
	g++ -c -o $(OBJ)/ppal.o $(SRC)/ppal.cpp -I$(INCLUDE)


# CONSTRUCCION DE LA BIBLIOTECA

$(LIB)/libopers_1mod.a : $(OBJ)/opers.o
	ar -rvs $(LIB)/libopers_1mod.a $(OBJ)/opers.o

$(OBJ)/opers.o : $(SRC)/opers.cpp $(INCLUDE)/opers.h
	g++ -c -o $(OBJ)/opers.o $(SRC)/opers.cpp -I$(INCLUDE)

  
# LIMPEZA

clean : 
	rm $(LIB)/libopers_1mod.a\
           $(BIN)/ppal_1_1lib_1mod $(OBJ)/ppal.o\
           $(OBJ)/opers.o   
