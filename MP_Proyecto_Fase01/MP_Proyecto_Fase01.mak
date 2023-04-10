#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: xx/04/2023
#
# PROYECTO I
#
# makefileP1.mak
#
# makefile para el proyecto 1
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
	  $(LIB_CLASES_UTILS)/libutils.a \
	  $(LIB_CLASES_UTILS)/libAdscripcion.a \
	  $(LIB_CLASES_UTILS)/libDepartamento.a \
	  $(LIB_CLASES_UTILS)/libEncargo.a \
	  $(LIB_CLASES_UTILS)/libFecha.a \
	  $(LIB_CLASES_UTILS)/libProfesor.a \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Proyecto Fase 01
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

$(BIN)/main_MP_Proyecto_Fase01 : $(OBJ)/main_MP_Proyecto_Fase01.o \
	        $(OBJ)/main_MP_Proyecto_Fase01.o  \
            $(LIB_CLASES_UTILS)/libutils.a \
            $(LIB_CLASES_UTILS)/libAdscripcion.a \
            $(LIB_CLASES_UTILS)/libDepartamento.a \
            $(LIB_CLASES_UTILS)/libEncargo.a \
            $(LIB_CLASES_UTILS)/libFecha.a \
            $(LIB_CLASES_UTILS)/libProfesor.a           
	@echo 
	@echo Creando ejecutable: main_MP_Proyecto_Fase01
	@echo 
	g++ -o $(BIN)/main_MP_Proyecto_Fase01 $(OBJ)/main_MP_Proyecto_Fase01.o \
	       -l$(wildcard $(LIB_CLASES_UTILS)/*) -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS

$(OBJ)/main_MP_Proyecto_Fase01.o : $(SRC)/main_MP_Proyecto_Fase01.cpp \
	           $(wildcard $(INCLUDE)/*.h)
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase01.o
	@echo 
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase01.o \
	          $(SRC)/main_MP_Proyecto_Fase01.cpp \
        -I$(INCLUDE) -std=c++14

#................................................
# OBJETOS_CLASES_UTILS

$(OBJ_CLASES_UTILS)/Departamento.o : $(SRC_CLASES_UTILS)/Departamento.cpp \
	           $(INCLUDE_CLASES_UTILS)/Departamento.h
	@echo 
	@echo Creando objeto: Departamento.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Departamento.o \
	          $(SRC_CLASES_UTILS)/Departamento.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/Profesor.o : $(SRC_CLASES_UTILS)/Profesor.cpp \
	           $(INCLUDE_CLASES_UTILS)/Profesor.h
	@echo 
	@echo Creando objeto: Profesor.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Profesor.o
	          $(SRC_CLASES_UTILS)/Profesor.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/Encargo.o : $(SRC_CLASES_UTILS)/Encargo.cpp \
	           $(INCLUDE_CLASES_UTILS)/Encargo.h
	@echo 
	@echo Creando objeto: Encargo.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Encargo.o $(SRC_CLASES_UTILS)/Encargo.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/Adscripcion.o : $(SRC_CLASES_UTILS)/Adscripcion.cpp \
	           $(INCLUDE_CLASES_UTILS)/Adscripcion.h
	@echo 
	@echo Creando objeto: Adscripcion.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Adscripcion.o
	          $(SRC_CLASES_UTILS)/Adscripcion.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/utils.o : $(SRC_CLASES_UTILS)/utils.cpp \
	           $(INCLUDE_CLASES_UTILS)/utils.h
	@echo 
	@echo Creando objeto: utils.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/utils.o $(SRC_CLASES_UTILS)/utils.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/Fecha.o : $(SRC_CLASES_UTILS)/Fecha.cpp \
	           $(INCLUDE_CLASES_UTILS)/Fecha.h
	@echo 
	@echo Creando objeto: Fecha.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Fecha.o $(SRC_CLASES_UTILS)/Fecha.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

#................................................
# BIBLIOTECAS 

$(LIB_CLASES_UTILS)/libutils.a : \
	           $(OBJ_CLASES_UTILS)/utils.o
	@echo 
	@echo Creando biblioteca: libutils.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libutils.a \
	       $(OBJ_CLASES_UTILS)/utils.o

$(LIB_CLASES_UTILS)/libProfesor.a : \
	           $(OBJ_CLASES_UTILS)/Profesor.o
	@echo 
	@echo Creando biblioteca: libProfesor.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libProfesor.a \
	       $(OBJ_CLASES_UTILS)/Profesor.o

$(LIB_CLASES_UTILS)/libDepartamento.a : \
	           $(OBJ_CLASES_UTILS)/Departamento.o
	@echo 
	@echo Creando biblioteca: libDepartamento.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libDepartamento.a \
	       $(OBJ_CLASES_UTILS)/Departamento.o

$(LIB_CLASES_UTILS)/libEncargo.a : \
	           $(OBJ_CLASES_UTILS)/Encargo.o
	@echo 
	@echo Creando biblioteca: libEncargo.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libEncargo.a \
	       $(OBJ_CLASES_UTILS)/Encargo.o

$(LIB_CLASES_UTILS)/libAdscripcion.a : \
	           $(OBJ_CLASES_UTILS)/Adscripcion.o
	@echo 
	@echo Creando biblioteca: libAdscripcion.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libAdscripcion.a \
	       $(OBJ_CLASES_UTILS)/Adscripcion.o

$(LIB_CLASES_UTILS)/libFecha.a : \
	           $(OBJ_CLASES_UTILS)/Fecha.o
	@echo 
	@echo Creando biblioteca: libFecha.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libFecha.a \
	       $(OBJ_CLASES_UTILS)/Fecha.o

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
	tar -cvf MP_sesion$(n).tar src include obj lib bin makefile$(n).mak