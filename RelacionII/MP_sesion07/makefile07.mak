#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: xx/04/2023
#
# RELACION DE PROBLEMAS 2
#
# makefile07.mak
#
# makefile para la sesión de prácticas 
#
#############################################################################

PROYECTO = PRACTICA $(shell basename "$$PWD")

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
      $(BIN)/II_Demo-Matriz2D \
	  $(BIN)/II_Viajante-Comercio \
	  $(LIB)/libMatriz2D.a \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas I
	@echo PROYECTO: $(shell basename "$$PWD")
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo Autor: Marco Girela Vida
	@echo Grupo: 1ºB
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo


#................................................
final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/II_Demo-Matriz2D : $(OBJ)/II_Demo-Matriz2D.o \
             $(OBJ)/Matriz2D.o 
	@echo 
	@echo Creando ejecutable: II_Demo-Matriz2D
	@echo 
	g++ -o $(BIN)/II_Demo-Matriz2D $(OBJ)/II_Demo-Matriz2D.o \
           $(OBJ)/Matriz2D.o 

$(BIN)/II_Viajante-Comercio : $(OBJ)/II_Viajante-Comercio.o \
             $(OBJ)/Matriz2D.o 
	@echo 
	@echo Creando ejecutable: II_Viajante-Comercio
	@echo 
	g++ -o $(BIN)/II_Viajante-Comercio $(OBJ)/II_Viajante-Comercio.o \
           $(OBJ)/Matriz2D.o 

#................................................
# OBJETOS 

$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: II_Demo-Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/II_Demo-Matriz2D.o $(SRC)/II_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/II_Viajante-Comercio.o : $(SRC)/II_Viajante-Comercio.cpp \
             $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: II_Viajante-Comercio.o
	@echo 
	g++ -c -o $(OBJ)/II_Viajante-Comercio.o $(SRC)/II_Viajante-Comercio.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++14

#................................................
# BIBLIOTECAS 

$(LIB)/libMatriz2D.a : \
                       $(OBJ)/Matriz2D.o
	@echo 
	@echo Creando biblioteca: libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a \
	       $(OBJ)/Matriz2D.o

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs : 
	@echo Borrando objetos de $(PROYECTO)...
	-rm $(wildcard $(OBJ)/*)
	-rm $(wildcard $(OBJ_CLASES_UTILS)/*)
	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs : 
	@echo Borrando bibliotecas de $(PROYECTO)...
	-rm $(wildcard $(LIB)/*)
	-rm $(wildcard $(LIB_CLASES_UTILS)/*)
	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...
	-rm $(wildcard $(BIN)/*)
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

#................................................
# OTROS

comprimir :
	tar -cvf MP_sesion$(n).tar src include obj lib bin makefile$(n).mak