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
# makefile05_.mak
#
# makefile para la sesión de prácticas 5
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
      $(BIN)/I_MezclaArrays \
	  $(BIN)/ProcesamientoArrayInt \
	  $(BIN)/GeneradorAleatorioEnteros \
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

$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o	\
                    $(OBJ)/ProcesamientoArrayInt.o	\
					$(OBJ)/GeneradorAleatorioEnteros.o            
	@echo 
	@echo Creando ejecutable: I_MezclaArrays
	@echo 
	g++ -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o \
	       $(OBJ)/ProcesamientoArrayInt.o   \
		   $(OBJ)/GeneradorAleatorioEnteros.o   \

$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o	\
                    $(OBJ)/ProcesamientoArrayInt.o	\
					$(OBJ)/GeneradorAleatorioEnteros.o	\
					$(OBJ)/MiCadenaClasica.o        
	@echo 
	@echo Creando ejecutable: I_MezclaArrays_ref
	@echo 
	g++ -o $(BIN)/I_MezclaArrays_ref $(OBJ)/I_MezclaArrays_ref.o \
	       $(OBJ)/ProcesamientoArrayInt.o   \
		   $(OBJ)/GeneradorAleatorioEnteros.o   \
		   $(OBJ)/MiCadenaClasica.o
#................................................
# OBJETOS 

$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp \
                      $(INCLUDE)/GeneradorAleatorioEnteros.h \
                      $(INCLUDE)/ProcesamientoArrayInt.h
	@echo 
	@echo Creando objeto: I_MezclaArrays.o
	@echo 
	g++ -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp \
	    -I$(INCLUDE) -std=c++14

$(OBJ)/I_MezclaArrays_ref.o : $(SRC)/I_MezclaArrays_ref.cpp \
                      $(INCLUDE)/GeneradorAleatorioEnteros.h \
                      $(INCLUDE)/ProcesamientoArrayInt.h \
					  $(INCLUDE)/MiCadenaClasica.h
	@echo 
	@echo Creando objeto: I_MezclaArrays_ref.o
	@echo 
	g++ -c -o $(OBJ)/I_MezclaArrays_ref.o $(SRC)/I_MezclaArrays_ref.cpp \
	    -I$(INCLUDE) -std=c++14

$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp \
                  $(INCLUDE)/ProcesamientoArrayInt.h \
                  $(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo 
	@echo Creando objeto: ProcesamientoArrayInt.o
	@echo 
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o $(SRC)/ProcesamientoArrayInt.cpp \
	    -I$(INCLUDE) -std=c++14

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
						$(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: GeneradorAleatorioEnteros.o
	@echo 
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
	          $(SRC)/GeneradorAleatorioEnteros.cpp \
	          -I$(INCLUDE) -std=c++14

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp \
						$(INCLUDE)/MiCadenaClasica.h
	@echo 
	@echo Creando objeto: MiCadenaClasica.o
	@echo 
	g++ -c -o $(OBJ)/MiCadenaClasica.o \
	          $(SRC)/MiCadenaClasica.cpp \
	          -I$(INCLUDE) -std=c++14
#..................................................

$(OBJ)/.o : $(SRC)/.cpp \
                      $(INCLUDE)/.h \
					  $(INCLUDE)/.h \
	@echo 
	@echo Creando objeto: .o
	@echo 
	g++ -c -o $(OBJ)/.o \
	          $(SRC)/.cpp \
	          -I$(INCLUDE) -std=c++14

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
	-rm $(OBJ)/I_MezclaArrays.o
	-rm $(OBJ)/ProcesamientoArrayInt.o
	-rm $(OBJ)/GeneradorAleatorioEnteros.o
	-rm $(OBJ)/I_MezclaArrays_ref.o	
	-rm $(OBJ)/MiCadenaClasica.o
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
	-rm $(BIN)/I_MezclaArrays
	-rm $(BIN)/ProcesamientoArrayInt
	-rm $(BIN)/GeneradorAleatorioEnteros
	-rm $(BIN)/I_MezclaArrays_ref
	-rm $(BIN)/MiCadenaClasica
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins
