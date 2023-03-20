#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: xx/03/2023
#
# RELACION DE PROBLEMAS 1
#
# makefileX_.mak
#
# makefile para la sesión de prácticas X
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
      $(BIN)/I_ \
	  $(BIN)/I_O \
	  $(BIN)/I_M \
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
                    $(LIB_CLASES_UTILS)/libBIBLIDU.a                     
	@echo 
	@echo Creando ejecutable: I_
	@echo 
	g++ -o $(BIN)/I_ $(OBJ)/I_.o \
	       $(OBJ)/.o   \
	       -lBIBLIDU -L$(LIB_CLASES_UTILS)

$(BIN)/I_O : $(OBJ)/I_O \
                    $(OBJ)/.o \
                    $(LIB_CLASES_UTILS)/libBIBLIDU.a 
	@echo 
	@echo Creando ejecutable: I_O
	@echo 
	g++ -o $(BIN)/I_O $(OBJ)/I_O.o \
	       $(OBJ)/.o \
	       -lBIBLIDU -L$(LIB_CLASES_UTILS)

$(BIN)/I_M : $(OBJ)/I_M.o \
                    $(OBJ)/.o \
                    $(LIB_CLASES_UTILS)/libBIBLIDU.a 
	@echo 
	@echo Creando ejecutable: I_M
	@echo 
	g++ -o $(BIN)/I_M $(OBJ)/I_M.o \
	       $(OBJ)/.o \
	       -lBIBLIDU -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS 

$(OBJ)/I_.o : $(SRC)/I_.cpp \
                      $(INCLUDE_CLASES_UTILS)/.h \
                      $(INCLUDE_CLASES_UTILS)/.h
	@echo 
	@echo Creando objeto: I_.o
	@echo 
	g++ -c -o $(OBJ)/I_.o $(SRC)/I_.cpp \
	    -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ)/I_O.o : $(SRC)/I_O.cpp \
                  $(INCLUDE_CLASES_UTILS)/.h \
                  $(INCLUDE_CLASES_UTILS)/.h 
	@echo 
	@echo Creando objeto: I_O.o
	@echo 
	g++ -c -o $(OBJ)/I_O.o $(SRC)/I_O.cpp \
	    -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ)/I_M.o : $(SRC)/I_M.cpp \
                  $(INCLUDE_CLASES_UTILS)/.h \
                  $(INCLUDE_CLASES_UTILS)/.h 
	@echo 
	@echo Creando objeto: I_M.o
	@echo 
	g++ -c -o $(OBJ)/I_M.o \
	          $(SRC)/I_M.cpp \
	          -I$(INCLUDE_CLASES_UTILS) -I$(INCLUDE) -std=c++14

#..................................................

$(OBJ)/.o : $(SRC)/.cpp \
                      $(INCLUDE_CLASES_UTILS)/.h
	@echo 
	@echo Creando objeto: .o
	@echo 
	g++ -c -o $(OBJ)/.o \
	          $(SRC)/.cpp \
	          -I$(INCLUDE_CLASES_UTILS) -std=c++14

#................................................
# BIBLIOTECAS 

$(LIB_CLASES_UTILS)/lib.a : \
	$(OBJ_CLASES_UTILS)/.o
	@echo 
	@echo Creando biblioteca: libBIBLIDU.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libBIBLIDU.a \
        $(OBJ_CLASES_UTILS)/BIBLIDU.o
 
$(OBJ_CLASES_UTILS)/.o : \
    $(SRC_CLASES_UTILS)/.cpp \
    $(INCLUDE_CLASES_UTILS)/.h
	@echo 
	@echo Creando objeto: .o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/.o \
        $(SRC_CLASES_UTILS)/.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14

#................................................
# LIMPEZA

comprimir:
	tar -cvf MP_sesion$(n).tar src include obj lib bin makefile$(n).mak

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos de $(PROYECTO)...
	-rm $(OBJ)/I_.o
	-rm $(OBJ)/I_O.o
	-rm $(OBJ)/I_M.o
	-rm $(OBJ)/.o	
	-rm $(OBJ_CLASES_UTILS)/.o 
	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...
	-rm $(LIB_CLASES_UTILS)/libBIBLIDU.a
	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...
	-rm $(BIN)/I_
	-rm $(BIN)/I_O
	-rm $(BIN)/I_M
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins
