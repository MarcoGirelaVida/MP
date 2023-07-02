#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# Basico_VectorDinamico.mak
#
# makefile para la la versión básico de VectorDinamico
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
      $(BIN)/Demo-BasicoVectorDinamico \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas II
	@echo Versión básica de VectorDinamico	
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


$(BIN)/Demo-BasicoVectorDinamico : $(OBJ)/Demo-BasicoVectorDinamico.o \
                                    $(LIB)/libVectorDinamico_basico.a
	@echo 
	@echo Creando ejecutable: Demo-BasicoVectorDinamico
	@echo 
	g++ -o $(BIN)/Demo-BasicoVectorDinamico \
	       $(OBJ)/Demo-BasicoVectorDinamico.o \
	       -L$(LIB) -lVectorDinamico_basico

#................................................
# OBJETOS 

$(OBJ)/Demo-BasicoVectorDinamico.o : $(SRC)/Demo-BasicoVectorDinamico.cpp \
           $(INCLUDE)/VectorDinamico_basico.h 
	@echo 
	@echo Creando objeto: Demo-BasicoVectorDinamico.o
	@echo 
	g++ -c -o $(OBJ)/Demo-BasicoVectorDinamico.o \
              $(SRC)/Demo-BasicoVectorDinamico.cpp -I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS

# (Funciones para procesar un Vector Dinamico) ........................

$(LIB)/libVectorDinamico_basico.a : $(OBJ)/VectorDinamico_basico.o
	@echo 
	@echo Creando biblioteca: libFuncsVectorDinamico.a 
	@echo  
	ar rvs $(LIB)/libVectorDinamico_basico.a $(OBJ)/VectorDinamico_basico.o

$(OBJ)/VectorDinamico_basico.o : $(SRC)/VectorDinamico_basico.cpp \
		$(INCLUDE)/VectorDinamico_basico.h 
	@echo 
	@echo Creando objeto: VectorDinamico_basico.o
	@echo  
	g++ -c -o $(OBJ)/VectorDinamico_basico.o $(SRC)/VectorDinamico_basico.cpp \
	         -I$(INCLUDE) -std=c++11

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos ...

	-rm $(OBJ)/Demo-BasicoVectorDinamico.o	
	-rm $(OBJ)/VectorDinamico_basico.o 

	@echo ...Borrados objetos 
	@echo 

clean-libs: 
	@echo Borrando bibliotecas ...

	-rm $(LIB)/libVectorDinamico_basico.a

	@echo ...Borradas bibliotecas 
	@echo 

clean-bins : 
	@echo Borrando ejecutables ...

	-rm $(BIN)/Demo-BasicoVectorDinamico

	@echo ...Borrados ejecutables

mr.proper:  clean-objs clean-libs clean-bins

