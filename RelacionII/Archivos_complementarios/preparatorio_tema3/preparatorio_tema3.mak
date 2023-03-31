#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# preparatorio_tema3.mak
#
# makefile para generar las soluciones al proyecto II_DemoColeccionCadenas
#
#############################################################################

HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

#................................................
all: preambulo \
     $(BIN)/II_DemoColeccionCadenas \
     final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejemplo preparatorio TEMA 3
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

$(BIN)/II_DemoColeccionCadenas :  \
          $(OBJ)/II_DemoColeccionCadenas.o \
          $(OBJ)/Funcs_ColeccionCadenas.o
	@echo
	@echo Creando ejecutable: II_DemoColeccionCadenas
	@echo 
	g++ -o $(BIN)/II_DemoColeccionCadenas \
           $(OBJ)/II_DemoColeccionCadenas.o \
           $(OBJ)/Funcs_ColeccionCadenas.o
#................................................
# OBJETOS 

$(OBJ)/II_DemoColeccionCadenas.o : \
            $(SRC)/II_DemoColeccionCadenas.cpp \
            $(INCLUDE)/Funcs_ColeccionCadenas.h
	@echo 
	@echo Creando objeto: II_DemoColeccionCadenas.o
	@echo 
	g++ -c -o $(OBJ)/II_DemoColeccionCadenas.o \
              $(SRC)/II_DemoColeccionCadenas.cpp \
             -I$(INCLUDE) -std=c++11

$(OBJ)/Funcs_ColeccionCadenas.o : \
            $(SRC)/Funcs_ColeccionCadenas.cpp \
            $(INCLUDE)/Funcs_ColeccionCadenas.h
	@echo 
	@echo Creando objeto: Funcs_ColeccionCadenas.o
	@echo 
	g++ -c -o $(OBJ)/Funcs_ColeccionCadenas.o \
              $(SRC)/Funcs_ColeccionCadenas.cpp  \
             -I$(INCLUDE) -std=c++11

#................................................
# LIMPEZA

clean: clean-objs 

clean-objs:
	@echo Borrando objetos ...

	-rm $(OBJ)/II_DemoColeccionCadenas.o
	-rm $(OBJ)/Funcs_ColeccionCadenas.o

	@echo ...Borrados objetos
	@echo 


clean-bins : 
	@echo Borrando ejecutables ...

	-rm $(BIN)/II_DemoColeccionCadenas

	@echo ...Borrados ejecutables 
	@echo 

mr.proper:  clean clean-bins 
