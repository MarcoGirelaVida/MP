#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# previos_04.mak
#
# Ejercicios resueltos (previos) para la sesión de prácticas 4
#
#############################################################################

PROYECTO = EJERCICIOS RESUELTOS PRACTICA 4

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
      $(BIN)/Ley_Dhondt_sin_modularizar \
      $(BIN)/I_Ley_Dhondt \
      $(BIN)/I_PosicionPrimerBlanco \
	$(BIN)/I_SaltaPrimeraPalabra \
	$(LIB)/libMiCadenaClasica.a \
	final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas I
	@echo PROYECTO: $(PROYECTO)	
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

$(BIN)/I_Ley_Dhondt : $(SRC)/I_Ley_Dhondt.cpp
	@echo 
	@echo Creando ejecutable: I_Ley_Dhondt
	@echo 
	g++ -o $(BIN)/I_Ley_Dhondt \
		 $(SRC)/I_Ley_Dhondt.cpp -std=c++14

$(BIN)/Ley_Dhondt_sin_modularizar : $(SRC)/Ley_Dhondt_sin_modularizar.cpp
	@echo 
	@echo Creando ejecutable: Ley_Dhondt_sin_modularizar
	@echo 
	g++ -o $(BIN)/Ley_Dhondt_sin_modularizar \
		 $(SRC)/Ley_Dhondt_sin_modularizar.cpp -std=c++14
		   
$(BIN)/I_PosicionPrimerBlanco : $(SRC)/I_PosicionPrimerBlanco.cpp
	@echo 
	@echo Creando ejecutable: I_PosicionPrimerBlanco
	@echo 
	g++ -o $(BIN)/I_PosicionPrimerBlanco \
		 $(SRC)/I_PosicionPrimerBlanco.cpp -std=c++14

$(BIN)/I_SaltaPrimeraPalabra : $(SRC)/I_SaltaPrimeraPalabra.cpp
	@echo 
	@echo Creando ejecutable: I_SaltaPrimeraPalabra
	@echo 
	g++ -o $(BIN)/I_SaltaPrimeraPalabra \
		 $(SRC)/I_SaltaPrimeraPalabra.cpp -std=c++14 

#................................................
# OBJETOS 

# (Cadenas clásicas) ........................

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp \
                           $(INCLUDE)/MiCadenaClasica.h
	@echo 
	@echo Creando objeto: MiCadenaClasica.o
	@echo 
	g++ -c -o $(OBJ)/MiCadenaClasica.o \
                $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE) -std=c++14


#................................................
# BIBLIOTECAS 

$(LIB)/libMiCadenaClasica.a : $(OBJ)/MiCadenaClasica.o
	@echo 
	@echo Creando biblioteca: libMiCadenaClasica.a
	@echo 
	ar rvs $(LIB)/libMiCadenaClasica.a $(OBJ)/MiCadenaClasica.o 

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos de $(PROYECTO)...

	-rm $(OBJ_CLASES_UTILS)/MiCadenaClasica.o 		

	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...

	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 
	-rm $(LIB)/libMiCadenaClasica.a	

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...

	-rm $(BIN)/Ley_Dhondt_sin_modularizar
	-rm $(BIN)/I_Ley_Dhondt
	-rm $(BIN)/I_PosicionPrimerBlanco
	-rm $(BIN)/I_SaltaPrimeraPalabra

	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

