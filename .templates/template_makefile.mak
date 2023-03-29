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
# makefile0_.mak
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
      $(BIN)/II_ \
	  $(LIB)/lib.a \
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

$(BIN)/I_ : $(OBJ)/I_.o \
	        $(OBJ)/.o  \
	        $(LIB_CLASES_UTILS)/lib.a                     
	@echo 
	@echo Creando ejecutable: I_
	@echo 
	g++ -o $(BIN)/I_ $(OBJ)/I_.o \
	       $(OBJ)/.o   \
	       -l -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS 

$(OBJ)/II_.o : $(SRC)/II_.cpp \
	           $(INCLUDE)/.h
	@echo 
	@echo Creando objeto: II_.o
	@echo 
	g++ -c -o $(OBJ)/II_.o $(SRC)/II_.cpp \
        -I$(INCLUDE) -std=c++14

#................................................
# BIBLIOTECAS 

$(LIB)/lib.a : \
	           $(OBJ)/.o
	@echo 
	@echo Creando biblioteca: lib.a
	@echo
	ar rvs $(LIB)/lib.a \
           $(OBJ)/.o

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos de $(PROYECTO)...
	-rm $(OBJ)/*
	-rm $(OBJ_CLASES_UTILS)/*
	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...
	-rm $(LIB)/*
	-rm $(LIB_CLASES_UTILS)/*
	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...
	-rm $(BIN)/*
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

#................................................
# OTROS

comprimir :
	tar -cvf MP_sesion$(n).tar src include obj lib bin makefile$(n).mak