#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# basico_Matriz2D.mak
#
# Generacion del proyecto descrito en los videos 
# "Gestión de matrices dinámicas"
#
#############################################################################

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_CLASES_UTILS =  $(HOME_CLASES_UTILS)/src
OBJ_CLASES_UTILS =  $(HOME_CLASES_UTILS)/obj
LIB_CLASES_UTILS =  $(HOME_CLASES_UTILS)/lib
INCLUDE_CLASES_UTILS = $(HOME_CLASES_UTILS)/include

#................................................
all:  preambulo \
      $(BIN)/Demo-BasicoMatriz2D \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Proyecto descrito en el video: \"Gestión de matrices dinámicas\"
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo "("c")" Francisco José CORTIJO BON
	@echo Depto. Ciencias de la Computación e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo

#................................................
final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/Demo-BasicoMatriz2D : $(OBJ)/Demo-BasicoMatriz2D.o \
             $(OBJ)/Matriz2D.o 
	@echo 
	@echo Creando ejecutable: Demo-BasicoMatriz2D
	@echo 
	g++ -o $(BIN)/Demo-BasicoMatriz2D $(OBJ)/Demo-BasicoMatriz2D.o \
           $(OBJ)/Matriz2D.o 

#................................................
# OBJETOS 

$(OBJ)/Demo-BasicoMatriz2D.o : $(SRC)/Demo-BasicoMatriz2D.cpp \
             $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: Demo-BasicoMatriz2D.o
	@echo 
	g++ -c -o $(OBJ)/Demo-BasicoMatriz2D.o $(SRC)/Demo-BasicoMatriz2D.cpp \
            -I$(INCLUDE) -std=c++11

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++11

#................................................
# LIMPEZA

clean: clean-objs 

clean-objs: 

	@echo Borrando objetos...

	-rm $(OBJ)/Demo-BasicoMatriz2D.o
	-rm $(OBJ)/Matriz2D.o

	@echo ...Borrados objetos
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/Demo-BasicoMatriz2D

	@echo ...Borrados ejecutables

mr.proper:  clean-objs clean-bins

