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
      $(BIN)/II_Demo_VectorDinamico \
	  $(BIN)/II_Demo_VectorDinamicoCadenas \
	  $(LIB)/libVectorDinamico.a \
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

$(BIN)/II_Demo_VectorDinamico : $(OBJ)/II_Demo_VectorDinamico.o \
                    $(OBJ)/FuncsVectorDinamico.o                   
	@echo 
	@echo Creando ejecutable: II_Demo_VectorDinamico
	@echo 
	g++ -o $(BIN)/II_Demo_VectorDinamico $(OBJ)/II_Demo_VectorDinamico.o \
	       $(OBJ)/FuncsVectorDinamico.o

$(BIN)/II_Demo_VectorDinamicoCadenas : $(OBJ)/II_Demo_VectorDinamicoCadenas.o \
                    $(OBJ)/FuncsVectorDinamico.o                   
	@echo 
	@echo Creando ejecutable: II_Demo_VectorDinamicoCadenas
	@echo 
	g++ -o $(BIN)/II_Demo_VectorDinamicoCadenas \
	       $(OBJ)/II_Demo_VectorDinamicoCadenas.o \
	       $(OBJ)/FuncsVectorDinamico.o
#................................................
# OBJETOS 

$(OBJ)/II_Demo_VectorDinamico.o : $(SRC)/II_Demo_VectorDinamico.cpp \
	                              $(INCLUDE)/FuncsVectorDinamico.h
	@echo 
	@echo Creando objeto: II_Demo_VectorDinamico.o
	@echo 
	g++ -c -o $(OBJ)/II_Demo_VectorDinamico.o $(SRC)/II_Demo_VectorDinamico.cpp \
	    -I$(INCLUDE) -std=c++14

$(OBJ)/II_Demo_VectorDinamicoCadenas.o : $(SRC)/II_Demo_VectorDinamicoCadenas.cpp \
	                              $(INCLUDE)/FuncsVectorDinamico.h
	@echo 
	@echo Creando objeto: II_Demo_VectorDinamicoCadenas.o
	@echo 
	g++ -c -o $(OBJ)/II_Demo_VectorDinamicoCadenas.o \
	          $(SRC)/II_Demo_VectorDinamicoCadenas.cpp \
	          -I$(INCLUDE) -std=c++14

$(OBJ)/FuncsVectorDinamico.o : $(SRC)/FuncsVectorDinamico.cpp \
	                           $(INCLUDE)/FuncsVectorDinamico.h
	@echo 
	@echo Creando objeto: FuncsVectorDinamico.o
	@echo 
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o $(SRC)/FuncsVectorDinamico.cpp \
	    -I$(INCLUDE) -std=c++14

#................................................
# BIBLIOTECAS 

$(LIB)/libVectorDinamico.a : \
	$(OBJ)/FuncsVectorDinamico.o
	@echo 
	@echo Creando biblioteca: libVectorDinamico.a
	@echo
	ar rvs $(LIB)/libVectorDinamico.a \
           $(OBJ)/FuncsVectorDinamico.o

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