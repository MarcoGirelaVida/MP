#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: xx/04/2023
#
# RELACION DE PROBLEMAS 3
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
      $(BIN)/III_Demo-Matriz2D \
	  $(BIN)/III_Demo-Secuencia \
	  $(LIB)/libMatriz2D.a \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas III
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

$(BIN)/III_Demo-Matriz2D : $(OBJ)/III_Demo-Matriz2D.o \
             $(OBJ)/Matriz2D.o 
	@echo 
	@echo Creando ejecutable: III_Demo-Matriz2D
	@echo 
	g++ -o $(BIN)/III_Demo-Matriz2D $(OBJ)/III_Demo-Matriz2D.o \
           $(OBJ)/Matriz2D.o 

$(BIN)/III_Demo-Secuencia : \
              $(OBJ)/III_Demo-Secuencia.o \
              $(LIB)/libSecuencia.a
	@echo 
	@echo Creando ejecutable: III_Demo-Secuencia
	@echo 
	g++ -o $(BIN)/III_Demo-Secuencia \
         $(OBJ)/III_Demo-Secuencia.o -L$(LIB) -lSecuencia

#................................................
# OBJETOS 
$(OBJ)/III_Demo-Matriz2D.o : $(SRC)/III_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: II_Demo-Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/III_Demo-Matriz2D.o $(SRC)/III_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp \
	                $(INCLUDE)/Matriz2D.h \
	                $(INCLUDE)/TipoBase_Matriz2D.h
	@echo 
	@echo Creando objeto: Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/III_Demo-Secuencia.o : \
              $(SRC)/III_Demo-Secuencia.cpp \
              $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: III_Demo-Secuencia.o
	@echo
	g++ -c -o $(OBJ)/III_Demo-Secuencia.o $(SRC)/III_Demo-Secuencia.cpp  \
        -I$(INCLUDE) -std=c++11

$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS 

$(LIB)/libMatriz2D.a : \
                       $(OBJ)/Matriz2D.o
	@echo 
	@echo Creando biblioteca: libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a \
	       $(OBJ)/Matriz2D.o

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o


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
	tar -cvf MP_$(n).tar src include obj lib bin makefile$(n).mak