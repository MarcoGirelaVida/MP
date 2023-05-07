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
	  $(BIN)/MP_Proyecto_Fase4 \
	  #$(BIN)/MP_Proyecto_Fase3# \
	  #$(BIN)/MP_Proyecto_Fase2# \
	  #$(BIN)/MP_Proyecto_Fase1# \
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Proyecto Fase 04
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

$(BIN)/MP_Proyecto_Fase2 : $(OBJ)/main_MP_Proyecto_Fase2.o \
	        $(OBJ)/main_MP_Proyecto_Fase2.o  \
            $(LIB_CLASES_UTILS)/libutils.a \
            $(LIB_CLASES_UTILS)/libAdscripcion.a \
            $(LIB_CLASES_UTILS)/libDepartamento.a \
            $(LIB_CLASES_UTILS)/libEncargo.a \
            $(LIB_CLASES_UTILS)/libFecha.a \
            $(LIB_CLASES_UTILS)/libProfesor.a           
	@echo 
	@echo Creando ejecutable: MP_Proyecto_Fase2
	@echo 
	g++ -o $(BIN)/MP_Proyecto_Fase2 $(OBJ)/main_MP_Proyecto_Fase2.o \
	       -lAdscripcion \
	       -lDepartamento \
	       -lProfesor \
	       -lEncargo \
	       -lutils \
	       -lFecha \
	       -L$(LIB_CLASES_UTILS)

$(BIN)/MP_Proyecto_Fase1 : $(OBJ)/main_MP_Proyecto_Fase1.o \
            $(LIB_CLASES_UTILS)/libutils.a \
            $(LIB_CLASES_UTILS)/libAdscripcion.a \
            $(LIB_CLASES_UTILS)/libDepartamento.a \
            $(LIB_CLASES_UTILS)/libEncargo.a \
            $(LIB_CLASES_UTILS)/libFecha.a \
            $(LIB_CLASES_UTILS)/libProfesor.a           
	@echo 
	@echo Creando ejecutable: MP_Proyecto_Fase1
	@echo 
	g++ -o $(BIN)/MP_Proyecto_Fase1 $(OBJ)/main_MP_Proyecto_Fase1.o \
	       -lAdscripcion \
	       -lDepartamento \
	       -lProfesor \
	       -lEncargo \
	       -lutils \
	       -lFecha \
	       -L$(LIB_CLASES_UTILS)

$(BIN)/MP_Proyecto_Fase3 : $(OBJ)/main_MP_Proyecto_Fase3.o \
            $(LIB_CLASES_UTILS)/libutils.a \
            $(LIB_CLASES_UTILS)/libAdscripcion.a \
            $(LIB_CLASES_UTILS)/libDepartamento.a \
            $(LIB_CLASES_UTILS)/libEncargo.a \
            $(LIB_CLASES_UTILS)/libFecha.a \
            $(LIB_CLASES_UTILS)/libProfesor.a           
	@echo 
	@echo Creando ejecutable: MP_Proyecto_Fase3
	@echo 
	g++ -o $(BIN)/MP_Proyecto_Fase3 $(OBJ)/main_MP_Proyecto_Fase3.o \
	       -lAdscripcion \
	       -lDepartamento \
	       -lProfesor \
	       -lEncargo \
	       -lutils \
	       -lFecha \
	       -L$(LIB_CLASES_UTILS)

$(BIN)/MP_Proyecto_Fase4 : $(OBJ)/main_MP_Proyecto_Fase4.o \
            $(LIB_CLASES_UTILS)/libutils.a \
            $(LIB_CLASES_UTILS)/libAdscripcion.a \
            $(LIB_CLASES_UTILS)/libDepartamento.a \
            $(LIB_CLASES_UTILS)/libEncargo.a \
            $(LIB_CLASES_UTILS)/libFecha.a \
            $(LIB_CLASES_UTILS)/libProfesor.a           
	@echo 
	@echo Creando ejecutable: MP_Proyecto_Fase4
	@echo 
	g++ -o $(BIN)/MP_Proyecto_Fase4 $(OBJ)/main_MP_Proyecto_Fase4.o \
	       -lAdscripcion \
	       -lDepartamento \
	       -lProfesor \
	       -lEncargo \
	       -lutils \
	       -lFecha \
	       -L$(LIB_CLASES_UTILS)

#................................................
# OBJETOS

$(OBJ)/main_MP_Proyecto_Fase4.o : $(SRC)/main_MP_Proyecto_Fase4.cpp \
	           $(wildcard $(INCLUDE)/*.h)
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase4.o
	@echo 
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase4.o \
	          $(SRC)/main_MP_Proyecto_Fase4.cpp \
        -I$(INCLUDE) -std=c++14

$(OBJ)/main_MP_Proyecto_Fase3.o : $(SRC)/main_MP_Proyecto_Fase3.cpp \
	           $(wildcard $(INCLUDE)/*.h)
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase3.o
	@echo 
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase3.o \
	          $(SRC)/main_MP_Proyecto_Fase3.cpp \
        -I$(INCLUDE) -std=c++14

$(OBJ)/main_MP_Proyecto_Fase2.o : $(SRC)/main_MP_Proyecto_Fase2.cpp \
	           $(wildcard $(INCLUDE)/*.h)
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase2.o
	@echo 
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase2.o \
	          $(SRC)/main_MP_Proyecto_Fase2.cpp \
        -I$(INCLUDE) -std=c++14

$(OBJ)/main_MP_Proyecto_Fase1.o : $(SRC)/main_MP_Proyecto_Fase1.cpp \
	           $(wildcard $(INCLUDE)/*.h)
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase1.o
	@echo 
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase1.o \
	          $(SRC)/main_MP_Proyecto_Fase1.cpp \
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
	tar -cvf MP_Proyecto_Fase2.tar src include obj lib bin MP_Proyecto_Fase2.mak todos_datos.txt