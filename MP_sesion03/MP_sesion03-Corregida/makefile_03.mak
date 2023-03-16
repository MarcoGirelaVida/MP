#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_03.mak
#
# makefile para la sesión de prácticas 3
#
#############################################################################

PROYECTO = PRACTICA 3

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
      $(BIN)/I_PosMayor_Basico \
	  $(BIN)/I_OrdenaVector \
	  $(BIN)/I_OrdenayMezclaVectores \
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

$(BIN)/I_PosMayor_Basico : $(OBJ)/I_PosMayor_Basico.o \
                    $(OBJ)/ProcesamientoArrayInt.o  \
                    $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a                     
	@echo 
	@echo Creando ejecutable: I_PosMayor_Basico
	@echo 
	g++ -o $(BIN)/I_PosMayor_Basico $(OBJ)/I_PosMayor_Basico.o \
	       $(OBJ)/ProcesamientoArrayInt.o   \
	       -lGeneradorAleatorioEnteros -L$(LIB_CLASES_UTILS)

$(BIN)/I_OrdenaVector : $(OBJ)/I_OrdenaVector.o \
                    $(OBJ)/ProcesamientoArrayInt.o \
                    $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a 
	@echo 
	@echo Creando ejecutable: I_OrdenaVector
	@echo 
	g++ -o $(BIN)/I_OrdenaVector $(OBJ)/I_OrdenaVector.o \
	       $(OBJ)/ProcesamientoArrayInt.o \
	       -lGeneradorAleatorioEnteros -L$(LIB_CLASES_UTILS)

$(BIN)/I_OrdenayMezclaVectores : $(OBJ)/I_OrdenayMezclaVectores.o \
                    $(OBJ)/ProcesamientoArrayInt.o \
                    $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a 
	@echo 
	@echo Creando ejecutable: I_OrdenayMezclaVectores
	@echo 
	g++ -o $(BIN)/I_OrdenayMezclaVectores $(OBJ)/I_OrdenayMezclaVectores.o \
	       $(OBJ)/ProcesamientoArrayInt.o \
	       -lGeneradorAleatorioEnteros -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS 

$(OBJ)/I_PosMayor_Basico.o : $(SRC)/I_PosMayor_Basico.cpp \
                      $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h \
                      $(INCLUDE_CLASES_UTILS)/ProcesamientoArrayInt.h
	@echo 
	@echo Creando objeto: I_PosMayor_Basico.o
	@echo 
	g++ -c -o $(OBJ)/I_PosMayor_Basico.o $(SRC)/I_PosMayor_Basico.cpp \
	    -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ)/I_OrdenaVector.o : $(SRC)/I_OrdenaVector.cpp \
                  $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h \
                  $(INCLUDE_CLASES_UTILS)/ProcesamientoArrayInt.h 
	@echo 
	@echo Creando objeto: I_OrdenaVector.o
	@echo 
	g++ -c -o $(OBJ)/I_OrdenaVector.o $(SRC)/I_OrdenaVector.cpp \
	    -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ)/I_OrdenayMezclaVectores.o : $(SRC)/I_OrdenayMezclaVectores.cpp \
                  $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h \
                  $(INCLUDE_CLASES_UTILS)/ProcesamientoArrayInt.h 
	@echo 
	@echo Creando objeto: I_OrdenayMezclaVectores.o
	@echo 
	g++ -c -o $(OBJ)/I_OrdenayMezclaVectores.o \
	          $(SRC)/I_OrdenayMezclaVectores.cpp \
	          -I$(INCLUDE_CLASES_UTILS) -I$(INCLUDE) -std=c++14

#..................................................

$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp \
                      $(INCLUDE_CLASES_UTILS)/ProcesamientoArrayInt.h
	@echo 
	@echo Creando objeto: ProcesamientoArrayInt.o
	@echo 
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o \
	          $(SRC)/ProcesamientoArrayInt.cpp \
	          -I$(INCLUDE_CLASES_UTILS) -std=c++14

#................................................
# BIBLIOTECAS 

# (Números aleatorios) ........................

$(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a : \
	$(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o
	@echo 
	@echo Creando biblioteca: libGeneradorAleatorioEnteros.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a \
        $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o
 
$(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o : \
    $(SRC_CLASES_UTILS)/GeneradorAleatorioEnteros.cpp \
    $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: GeneradorAleatorioEnteros.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o \
        $(SRC_CLASES_UTILS)/GeneradorAleatorioEnteros.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos de $(PROYECTO)...
	-rm $(OBJ)/I_PosMayor_Basico.o
	-rm $(OBJ)/I_OrdenaVector.o
	-rm $(OBJ)/I_OrdenayMezclaVectores.o
	-rm $(OBJ)/ProcesamientoArrayInt.o	
	-rm $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o 
	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...
	-rm $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a
	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...
	-rm $(BIN)/I_PosMayor_Basico
	-rm $(BIN)/I_OrdenaVector
	-rm $(BIN)/I_OrdenayMezclaVectores
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

