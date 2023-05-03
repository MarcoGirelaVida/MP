#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# Metropolitano.mak
#
# makefile para generar el proyecto "Metropolitano".
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
	  $(BIN)/III_Demo-Metropolitano \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Proyecto METROPOLITANO
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo Grado en Ingeniería Informática
	@echo
	@echo "("c")" Francisco José CORTIJO BON
	@echo Depto. Ciencias de la Computación e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo

final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/III_Demo-Metropolitano : $(OBJ)/III_Demo-Metropolitano.o \
                $(OBJ)/InfoParada.o $(OBJ)/Linea.o $(OBJ)/RedMetro.o 
	@echo 
	@echo Creando ejecutable: III_Demo-Metropolitano
	@echo 
	g++ -o $(BIN)/III_Demo-Metropolitano $(OBJ)/III_Demo-Metropolitano.o \
           $(OBJ)/InfoParada.o $(OBJ)/Linea.o $(OBJ)/RedMetro.o

#................................................
# OBJETOS

$(OBJ)/III_Demo-Metropolitano.o : $(SRC)/III_Demo-Metropolitano.cpp \
           $(INCLUDE)/RedMetro.h $(INCLUDE)/Linea.h $(INCLUDE)/InfoParada.h  
	@echo 
	@echo Creando objeto: III_Demo-Metropolitano.o
	@echo 
	g++ -c -o $(OBJ)/III_Demo-Metropolitano.o \
	          $(SRC)/III_Demo-Metropolitano.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/RedMetro.o : $(SRC)/RedMetro.cpp $(INCLUDE)/RedMetro.h\
                    $(INCLUDE)/Linea.h $(INCLUDE)/InfoParada.h 
	@echo 
	@echo Creando objeto: RedMetro.o
	@echo 
	g++ -c -o $(OBJ)/RedMetro.o $(SRC)/RedMetro.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Linea.o : $(SRC)/Linea.cpp $(INCLUDE)/Linea.h $(INCLUDE)/InfoParada.h
	@echo 
	@echo Creando objeto: Linea.o
	@echo 
	g++ -c -o $(OBJ)/Linea.o $(SRC)/Linea.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/InfoParada.o : $(SRC)/InfoParada.cpp $(INCLUDE)/InfoParada.h
	@echo 
	@echo Creando objeto: InfoParada.o
	@echo 
	g++ -c -o $(OBJ)/InfoParada.o $(SRC)/InfoParada.cpp -I$(INCLUDE) -std=c++11

#................................................
# LIMPEZA

clean: clean-objs 

clean-objs: 

	@echo Borrando objetos...

	-rm $(OBJ)/InfoParada.o
	-rm $(OBJ)/Linea.o
	-rm $(OBJ)/RedMetro.o
	-rm $(OBJ)/III_Demo-Metropolitano.o

	@echo ...Borrados objetos
	@echo  

clean-bins : 
	
	@echo Borrando ejecutables...

	-rm $(BIN)/III_Demo-Metropolitano

	@echo ...Borrados ejecutables 
	@echo 	

mr.proper:  clean clean-bins

