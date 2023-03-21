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
	  $(BIN)/I_MezclaArrays_ref	\
	  $(BIN)/I_DemoSecuenciaEnteros	\
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

$(BIN)/I_DemoSecuenciaEnteros : $(OBJ)/I_DemoSecuenciaEnteros.o	\
                    $(OBJ)/SecuenciaEnteros.o	\
					$(OBJ)/GeneradorAleatorioEnteros.o
	@echo 
	@echo Creando ejecutable: I_DemoSecuenciaEnteros
	@echo 
	g++ -o $(BIN)/I_DemoSecuenciaEnteros $(OBJ)/I_DemoSecuenciaEnteros.o \
	       $(OBJ)/SecuenciaEnteros.o	\
		   $(OBJ)/GeneradorAleatorioEnteros.o
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

$(OBJ)/I_DemoSecuenciaEnteros.o : $(SRC)/I_DemoSecuenciaEnteros.cpp	\
						$(INCLUDE)/SecuenciaEnteros.h
	@echo 
	@echo Creando objeto: I_DemoSecuenciaEnteros.o
	@echo 
	g++ -c -o $(OBJ)/I_DemoSecuenciaEnteros.o \
	    $(SRC)/I_DemoSecuenciaEnteros.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/SecuenciaEnteros.o : \
    $(SRC)/SecuenciaEnteros.cpp \
    $(INCLUDE)/SecuenciaEnteros.h	\
	$(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: SecuenciaEnteros.o 
	@echo
	g++ -c -o $(OBJ)/SecuenciaEnteros.o \
        $(SRC)/SecuenciaEnteros.cpp -I$(INCLUDE) -std=c++14
#................................................
# BIBLIOTECAS 

$(LIB_CLASES_UTILS)/libSecuenciaEnteros.a : \
	$(OBJ_CLASES_UTILS)/SecuenciaEnteros.o
	@echo 
	@echo Creando biblioteca: libSecuenciaEnteros.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libSecuenciaEnteros.a \
        $(OBJ_CLASES_UTILS)/SecuenciaEnteros.o
 
$(OBJ_CLASES_UTILS)/SecuenciaEnteros.o : \
    $(SRC_CLASES_UTILS)/SecuenciaEnteros.cpp \
    $(INCLUDE_CLASES_UTILS)/SecuenciaEnteros.h	\
	$(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: SecuenciaEnteros.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/SecuenciaEnteros.o \
        $(SRC_CLASES_UTILS)/SecuenciaEnteros.cpp \
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
	-rm $(OBJ)/I_DemoSecuenciaEnteros.o
	-rm $(OBJ_CLASES_UTILS)/SecuenciaEnteros.o
	-rm $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o 
	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...
	-rm $(LIB_CLASES_UTILS)/libSecuenciaEnteros.a
	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...
	-rm $(BIN)/I_MezclaArrays
	-rm $(BIN)/I_MezclaArrays_ref
	-rm $(BIN)/I_DemoSecuenciaEnteros
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins
