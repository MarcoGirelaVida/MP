######################################################################### 
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2016-2017
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_2lib_2mod.mak
#
######################################################################### 

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


all: clean $(LIB)/libadic_2mod.a $(LIB)/libproducto_2mod.a $(BIN)/ppal_2lib_2mod 


$(BIN)/ppal_2lib_2mod : $(OBJ)/ppal.o $(LIB)/libadic_2mod.a $(LIB)/libproducto_2mod.a
	g++ -o $(BIN)/ppal_2lib_2mod $(OBJ)/ppal.o -ladic_2mod -lproducto_2mod -L$(LIB)

$(OBJ)/ppal.o : $(SRC)/ppal.cpp $(INCLUDE)/adic_2mod.h $(INCLUDE)/producto_2mod.h
	g++ -c -o $(OBJ)/ppal.o $(SRC)/ppal.cpp -I$(INCLUDE)


# CONSTRUCCION DE LAS BIBLIOTECAS

$(LIB)/libadic_2mod.a : $(OBJ)/suma.o $(OBJ)/resta.o 
	ar -rvs $(LIB)/libadic_2mod.a $(OBJ)/suma.o $(OBJ)/resta.o
	
$(OBJ)/suma.o : $(SRC)/suma.cpp 
	g++ -c -o $(OBJ)/suma.o $(SRC)/suma.cpp 

$(OBJ)/resta.o : $(SRC)/resta.cpp 
	g++ -c -o $(OBJ)/resta.o $(SRC)/resta.cpp 


$(LIB)/libproducto_2mod.a : $(OBJ)/multiplica.o $(OBJ)/divide.o
	ar -rvs $(LIB)/libproducto_2mod.a $(OBJ)/multiplica.o $(OBJ)/divide.o
	
$(OBJ)/multiplica.o : $(SRC)/multiplica.cpp 
	g++ -c -o $(OBJ)/multiplica.o $(SRC)/multiplica.cpp 

$(OBJ)/divide.o: $(SRC)/divide.cpp 
	g++ -c -o $(OBJ)/divide.o $(SRC)/divide.cpp 


# LIMPEZA

clean : 
	rm $(LIB)/libadic_2mod.a $(LIB)/libproducto_2mod.a\
           $(BIN)/ppal_2lib_2mod $(OBJ)/ppal.o\
           $(OBJ)/suma.o $(OBJ)/resta.o\
           $(OBJ)/multiplica.o $(OBJ)/divide.o
