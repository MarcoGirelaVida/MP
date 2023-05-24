#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: xx/04/2023
#
# RELACION DE PROBLEMAS 6
#
# makefile13_.mak
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
	  $(LIB)/libMatriz2D.a \
	  $(LIB)/libSecuencia.a \
      $(BIN)/IV_Demo-Matriz2D \
	  $(BIN)NumeraLineas_Ampliacion\
	  $(BIN)MensajesOcultos-2\
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas VI
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

$(BIN)/IV_Demo-Matriz2D : $(OBJ)/IV_Demo-Matriz2D.o \
	                       $(OBJ)/Matriz2D.o \
	                       $(OBJ)/Secuencia.o
	@echo 
	@echo Creando ejecutable: IV_Demo-Matriz2D
	@echo 
	g++ -o $(BIN)/IV_Demo-Matriz2D $(OBJ)/IV_Demo-Matriz2D.o \
	        -lSecuencia \
	        -lMatriz2D \
	        -L$(LIB_CLASES_UTILS)

$(BIN)/NumeraLineas_Ampliacion : $(SRC)/NumeraLineas_Ampliacion.cpp
	@echo 
	@echo Creando ejecutable: NumeraLineas_Ampliacion
	@echo 
	g++ -o $(BIN)/NumeraLineas_Ampliacion $(SRC)/NumeraLineas_Ampliacion.cpp --std=c++14

$(BIN)/ParteFicheroPorNumLineas : $(SRC)/ParteFicheroPorNumLineas.cpp
	@echo 
	@echo Creando ejecutable: ParteFicheroPorNumLineas
	@echo 
	g++ -o $(BIN)/ParteFicheroPorNumLineas $(SRC)/ParteFicheroPorNumLineas.cpp --std=c++14

$(BIN)/MensajesOcultos-2 : $(OBJ)/MensajesOcultos-2.o \
	                       $(OBJ)/Matriz2D.o \
	                       $(OBJ)/Secuencia.o
	@echo 
	@echo Creando ejecutable: MensajesOcultos-2
	@echo 
	g++ -o $(BIN)/MensajesOcultos-2 $(OBJ)/MensajesOcultos-2.o \
	        -lSecuencia \
	        -lMatriz2D \
	        -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS 
$(OBJ)/IV_Demo-Matriz2D.o : $(SRC)/IV_Demo-Matriz2D.cpp \
             $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: IV_Demo-Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/IV_Demo-Matriz2D.o $(SRC)/IV_Demo-Matriz2D.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/MensajesOcultos-2.o : $(SRC)/MensajesOcultos-2.cpp \
             $(INCLUDE)/Matriz2D.h
	@echo 
	@echo Creando objeto: MensajesOcultos-2.o
	@echo 
	g++ -c -o $(OBJ)/MensajesOcultos-2.o $(SRC)/MensajesOcultos-2.cpp \
            -I$(INCLUDE) -std=c++14

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp \
	                $(INCLUDE)/Matriz2D.h \
	                $(INCLUDE)/TipoBase_Matriz2D.h \
	                $(INCLUDE)/Secuencia.h
	@echo 
	@echo Creando objeto: Matriz2D.o
	@echo 
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++14

$(OBJ)/Secuencia_strings.o : $(SRC)/Secuencia_strings.cpp \
                     $(INCLUDE)/Secuencia_strings.h $(INCLUDE)/TipoBase_Secuencia_strings.h
	@echo 
	@echo Creando objeto: Secuencia_strings.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia_strings.o  $(SRC)/Secuencia_strings.cpp \
       -I$(INCLUDE) -std=c++14

#................................................
# BIBLIOTECAS 

$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o
	@echo 
	@echo Creando biblioteca: libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a \
	       $(OBJ)/Matriz2D.o

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o $(OBJ)/Secuencia_strings.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o $(OBJ)/Secuencia_strings.o


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
	tar -cvf MP_sesion11.tar src include obj lib bin makefile11.mak