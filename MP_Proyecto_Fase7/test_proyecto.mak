#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: 1/06/2023
#
# TEST PROYECTO
#
# test_proyecto.mak
#
# makefile para el test del proyecto
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
	  $(BIN)/test_proyecto \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Proyecto Fase 06
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

$(BIN)/test_proyecto : $(OBJ)/test_proyecto.o \
            $(LIB_CLASES_UTILS)/libutils.a \
            $(LIB_CLASES_UTILS)/libAdscripcion.a \
            $(LIB_CLASES_UTILS)/libDepartamento.a \
            $(LIB_CLASES_UTILS)/libEncargo.a \
            $(LIB_CLASES_UTILS)/libFecha.a \
            $(LIB_CLASES_UTILS)/libProfesor.a           
	@echo 
	@echo Creando ejecutable: test_proyecto
	@echo 
	g++ -o $(BIN)/test_proyecto $(OBJ)/test_proyecto.o \
	       -lAdscripcion \
	       -lDepartamento \
	       -lProfesor \
	       -lEncargo \
	       -lutils \
	       -lFecha \
	       -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS

$(OBJ)/test_proyecto.o : $(SRC)/main_test_proyecto.cpp \
	           $(wildcard $(INCLUDE)/*.h)
	@echo 
	@echo Creando objeto: test_proyecto.o
	@echo 
	g++ -c -o $(OBJ)/test_proyecto.o \
	          $(SRC)/main_test_proyecto.cpp \
        -I$(INCLUDE) -std=c++14

#................................................
# OBJETOS_CLASES_UTILS

$(OBJ_CLASES_UTILS)/Departamento.o : $(SRC_CLASES_UTILS)/Departamento.cpp \
	           $(INCLUDE_CLASES_UTILS)/Departamento.h \
	           $(INCLUDE_CLASES_UTILS)/utils.h
	@echo 
	@echo Creando objeto: Departamento.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Departamento.o \
	          $(SRC_CLASES_UTILS)/Departamento.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/Profesor.o : $(SRC_CLASES_UTILS)/Profesor.cpp \
	           $(INCLUDE_CLASES_UTILS)/Profesor.h \
			   $(INCLUDE_CLASES_UTILS)/utils.h
	@echo 
	@echo Creando objeto: Profesor.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/Profesor.o \
	          $(SRC_CLASES_UTILS)/Profesor.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/Encargo.o : $(SRC_CLASES_UTILS)/Encargo.cpp \
	           $(INCLUDE_CLASES_UTILS)/Encargo.h \
	           $(INCLUDE_CLASES_UTILS)/utils.h
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
	g++ -c -o $(OBJ_CLASES_UTILS)/Adscripcion.o	\
	          $(SRC_CLASES_UTILS)/Adscripcion.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/VectorProfesor.o : $(SRC_CLASES_UTILS)/VectorProfesor.cpp \
	           $(INCLUDE_CLASES_UTILS)/VectorProfesor.h \
				$(INCLUDE_CLASES_UTILS)/Profesor.h
	@echo 
	@echo Creando objeto: VectorProfesor.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/VectorProfesor.o	\
	          $(SRC_CLASES_UTILS)/VectorProfesor.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/VectorDepartamento.o : $(SRC_CLASES_UTILS)/VectorDepartamento.cpp \
	           $(INCLUDE_CLASES_UTILS)/VectorDepartamento.h \
	           $(INCLUDE_CLASES_UTILS)/Departamento.h
	@echo 
	@echo Creando objeto: VectorDepartamento.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/VectorDepartamento.o	\
	          $(SRC_CLASES_UTILS)/VectorDepartamento.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/VectorEncargo.o : $(SRC_CLASES_UTILS)/VectorEncargo.cpp \
	           $(INCLUDE_CLASES_UTILS)/VectorEncargo.h \
	           $(INCLUDE_CLASES_UTILS)/Encargo.h
	@echo 
	@echo Creando objeto: VectorEncargo.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/VectorEncargo.o	\
	          $(SRC_CLASES_UTILS)/VectorEncargo.cpp \
        -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(OBJ_CLASES_UTILS)/VectorAdscripcion.o : $(SRC_CLASES_UTILS)/VectorAdscripcion.cpp \
	           $(INCLUDE_CLASES_UTILS)/VectorAdscripcion.h \
	           $(INCLUDE_CLASES_UTILS)/Adscripcion.h
	@echo 
	@echo Creando objeto: VectorAdscripcion.o
	@echo 
	g++ -c -o $(OBJ_CLASES_UTILS)/VectorAdscripcion.o	\
	          $(SRC_CLASES_UTILS)/VectorAdscripcion.cpp \
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
	           $(OBJ_CLASES_UTILS)/Profesor.o \
			   $(OBJ_CLASES_UTILS)/VectorProfesor.o \
	           $(OBJ_CLASES_UTILS)/Fecha.o \
			   $(OBJ_CLASES_UTILS)/utils.o
	@echo 
	@echo Creando biblioteca: libProfesor.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libProfesor.a \
	       $(OBJ_CLASES_UTILS)/Profesor.o \
		   $(OBJ_CLASES_UTILS)/VectorProfesor.o \
	       $(OBJ_CLASES_UTILS)/Fecha.o \
	       $(OBJ_CLASES_UTILS)/utils.o

$(LIB_CLASES_UTILS)/libDepartamento.a : \
	           $(OBJ_CLASES_UTILS)/Departamento.o \
			   $(OBJ_CLASES_UTILS)/VectorDepartamento.o \
			   $(OBJ_CLASES_UTILS)/utils.o
	@echo 
	@echo Creando biblioteca: libDepartamento.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libDepartamento.a \
	       $(OBJ_CLASES_UTILS)/Departamento.o \
		   $(OBJ_CLASES_UTILS)/VectorDepartamento.o \
		   $(OBJ_CLASES_UTILS)/utils.o

$(LIB_CLASES_UTILS)/libEncargo.a : \
	           $(OBJ_CLASES_UTILS)/Encargo.o \
			   $(OBJ_CLASES_UTILS)/VectorEncargo.o \
			   $(OBJ_CLASES_UTILS)/utils.o
	@echo 
	@echo Creando biblioteca: libEncargo.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libEncargo.a \
	       $(OBJ_CLASES_UTILS)/Encargo.o \
		   $(OBJ_CLASES_UTILS)/VectorEncargo.o \
		   $(OBJ_CLASES_UTILS)/utils.o

$(LIB_CLASES_UTILS)/libAdscripcion.a : \
	           $(OBJ_CLASES_UTILS)/Adscripcion.o \
			   $(OBJ_CLASES_UTILS)/VectorAdscripcion.o
	@echo 
	@echo Creando biblioteca: libAdscripcion.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libAdscripcion.a \
	       $(OBJ_CLASES_UTILS)/Adscripcion.o \
		   $(OBJ_CLASES_UTILS)/VectorAdscripcion.o

$(LIB_CLASES_UTILS)/libFecha.a : $(OBJ_CLASES_UTILS)/Fecha.o
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
	tar -cvf test_proyecto.tar src include obj lib bin test_proyecto.mak
