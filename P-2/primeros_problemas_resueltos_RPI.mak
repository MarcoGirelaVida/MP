#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# primeros_problemas_resueltos_RPI.mak
#
# makefile para generar las soluciones a los primeros problemas de la 
# Relación de Problemas I: Punteros y funciones
#
#############################################################################

HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

#................................................

all:  preambulo \
      $(BIN)/I_CambiaNegs\
      $(BIN)/I_CambiaNegs_PtrFinal \
      $(BIN)/I_MezclaSencillaVectores \
      $(BIN)/I_ReorganizaVector \
      $(BIN)/I_ReorganizaVector_FuncionSwap \
      final

#................................................

preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Primeros ejercicios de la Relación de Problemas I
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


$(BIN)/I_CambiaNegs : $(SRC)/I_CambiaNegs.cpp
	@echo 
	@echo Creando ejecutable: I_CambiaNegs
	@echo 
	g++ -o $(BIN)/I_CambiaNegs \
	       $(SRC)/I_CambiaNegs.cpp -std=c++14

$(BIN)/I_CambiaNegs_PtrFinal : \
             $(SRC)/I_CambiaNegs_PtrFinal.cpp
	@echo 
	@echo Creando ejecutable: I_CambiaNegs_PtrFinal
	@echo 
	g++ -o $(BIN)/I_CambiaNegs_PtrFinal \
		 $(SRC)/I_CambiaNegs_PtrFinal.cpp -std=c++14

$(BIN)/I_MezclaSencillaVectores : \
             $(SRC)/I_MezclaSencillaVectores.cpp
	@echo 
	@echo Creando ejecutable: I_MezclaSencillaVectores
	@echo 
	g++ -o $(BIN)/I_MezclaSencillaVectores \
             $(SRC)/I_MezclaSencillaVectores.cpp -std=c++14

$(BIN)/I_ReorganizaVector : \
             $(SRC)/I_ReorganizaVector.cpp
	@echo 
	@echo Creando ejecutable: I_ReorganizaVector
	@echo 
	g++ -o $(BIN)/I_ReorganizaVector \
	       $(SRC)/I_ReorganizaVector.cpp -std=c++14

$(BIN)/I_ReorganizaVector_FuncionSwap : \
             $(SRC)/I_ReorganizaVector_FuncionSwap.cpp
	@echo 
	@echo Creando ejecutable: I_ReorganizaVector_FuncionSwap
	@echo 
	g++ -o $(BIN)/I_ReorganizaVector_FuncionSwap \
	       $(SRC)/I_ReorganizaVector_FuncionSwap.cpp \
	       -std=c++14


#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 	
	@echo Borrando objetos ...

	@echo ... Borrados objetos 

clean-libs: 
	@echo Borrando bibliotecas ...

	@echo ... Borradas bibliotecas 

clean-bins : 
	@echo Borrando ejecutables ...

	-rm $(BIN)/I_CambiaNegs
	-rm $(BIN)/I_CambiaNegs_PtrFinal
	-rm $(BIN)/I_MezclaSencillaVectores
	-rm $(BIN)/I_ReorganizaVector
	-rm $(BIN)/I_ReorganizaVector_FuncionSwap

	@echo ... Borrados ejecutables

mr.proper:  clean-objs clean-libs clean-bins

