#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_sesion13_previa_estudiantes.mak
#
# makefile (estudiantes) para la sesión de prácticas 13 (ejercicios dados)
#
#############################################################################

PROYECTO = "SESION 13 -PREVIA- PARA ESTUDIANTES"

HOME = .
HOME_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_UTILS =  $(HOME_UTILS)/src
OBJ_UTILS =  $(HOME_UTILS)/obj
LIB_UTILS =  $(HOME_UTILS)/lib
INCLUDE_UTILS = $(HOME_UTILS)/include

#................................................
all: \
	preambulo \
	bibliotecas\
	$(LIB)/libSecuencia.a \
	fin-bibliotecas \
	ejecutables \
    $(BIN)/PuntoMedio \
    $(BIN)/SeleccionPuntos \
	$(BIN)/NumeraLineas \
	$(BIN)/Diferencias \
	$(BIN)/MezclaFicheros \
	$(BIN)/VI_Demo-Secuencia \
	$(BIN)/Busca \
	$(BIN)/Cabecera \
	$(BIN)/Final \
	fin-ejecutables 	

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
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

ejecutables:
	@echo Creando ejecutables de $(PROYECTO)...

fin-ejecutables:
	@echo ...Ejecutables creados de $(PROYECTO)
	@echo 	

bibliotecas:
	@echo Creando modulos objeto y bibliotecas de $(PROYECTO)...

fin-bibliotecas:
	@echo ...Creados modulos objeto y bibliotecas de $(PROYECTO)
	@echo 	

#................................................
# EJECUTABLES


$(BIN)/PuntoMedio : $(OBJ)/PuntoMedio.o $(LIB)/libPunto2D.a \
                    $(LIB)/libSecuenciaPunto2D.a
	@echo 
	@echo Creando ejecutable: PuntoMedio
	@echo 
	g++ -o $(BIN)/PuntoMedio $(OBJ)/PuntoMedio.o \
	     -L$(LIB) -lPunto2D -lSecuenciaPunto2D

$(BIN)/SeleccionPuntos : $(OBJ)/SeleccionPuntos.o $(LIB)/libPunto2D.a \
                         $(LIB)/libSecuenciaPunto2D.a
	@echo 
	@echo Creando ejecutable: SeleccionPuntos
	@echo 
	g++ -o $(BIN)/SeleccionPuntos $(OBJ)/SeleccionPuntos.o \
	     -L$(LIB) -lPunto2D -lSecuenciaPunto2D




$(BIN)/NumeraLineas : $(SRC)/NumeraLineas.cpp
	@echo 
	@echo Creando ejecutable: NumeraLineas
	@echo 
	g++ -o $(BIN)/NumeraLineas  $(SRC)/NumeraLineas.cpp -std=c++14

$(BIN)/Diferencias : $(SRC)/Diferencias.cpp
	@echo 
	@echo Creando ejecutable: Diferencias
	@echo 
	g++ -o$(BIN)/Diferencias $(SRC)/Diferencias.cpp -std=c++14

$(BIN)/MezclaFicheros : $(SRC)/MezclaFicheros.cpp
	@echo 
	@echo Creando ejecutable: MezclaFicheros
	@echo 
	g++ -o$(BIN)/MezclaFicheros $(SRC)/MezclaFicheros.cpp -std=c++14

$(BIN)/VI_Demo-Secuencia : $(OBJ)/VI_Demo-Secuencia.o $(LIB)/libSecuencia.a
	@echo 
	@echo Creando ejecutable: VI_Demo-Secuencia
	@echo 
	g++ -o $(BIN)/VI_Demo-Secuencia $(OBJ)/VI_Demo-Secuencia.o \
	      -L$(LIB) -lSecuencia 

$(BIN)/Busca  : $(OBJ)/Busca.o $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: Busca
	@echo 
	g++ -o $(BIN)/Busca $(OBJ)/Busca.o -L$(LIB_UTILS) -lUtils  

$(BIN)/Cabecera  : $(OBJ)/Cabecera.o $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: Cabecera
	@echo 
	g++ -o $(BIN)/Cabecera $(OBJ)/Cabecera.o -L$(LIB_UTILS) -lUtils 

$(BIN)/Final : $(OBJ)/Final.o
	@echo 
	@echo Creando ejecutable: Final
	@echo 
	g++ -o $(BIN)/Final  $(OBJ)/Final.o -L$(LIB_UTILS) -lUtils 

#................................................
# OBJETO


$(OBJ)/PuntoMedio.o : $(SRC)/PuntoMedio.cpp  \
                      $(INCLUDE)/Punto2D.h  $(INCLUDE)/SecuenciaPunto2D.h \
			          $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: PuntoMedio.o
	@echo
	g++ -c -o $(OBJ)/PuntoMedio.o $(SRC)/PuntoMedio.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/SeleccionPuntos.o : $(SRC)/SeleccionPuntos.cpp  \
                           $(INCLUDE)/Punto2D.h  $(INCLUDE)/SecuenciaPunto2D.h \
			               $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: SeleccionPuntos.o
	@echo
	g++ -c -o $(OBJ)/SeleccionPuntos.o $(SRC)/SeleccionPuntos.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14



$(OBJ)/Busca.o  : $(SRC)/Busca.cpp $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: Busca.o
	@echo 
	g++ -c -o $(OBJ)/Busca.o $(SRC)/Busca.cpp \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/Cabecera.o  : $(SRC)/Cabecera.cpp $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: Cabecera.o
	@echo 
	g++ -c -o $(OBJ)/Cabecera.o $(SRC)/Cabecera.cpp \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/Final.o  : $(SRC)/Final.cpp $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: Final.o
	@echo 
	g++ -c -o $(OBJ)/Final.o  $(SRC)/Final.cpp  \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/VI_Demo-Secuencia.o : $(SRC)/VI_Demo-Secuencia.cpp \
                             $(INCLUDE)/Secuencia.h
	@echo 
	@echo Creando objeto: VI_Demo-Secuencia.o 
	@echo 
	g++ -c -o $(OBJ)/VI_Demo-Secuencia.o $(SRC)/VI_Demo-Secuencia.cpp \
	       -I$(INCLUDE) -std=c++14 

#................................................
# BIBLIOTECAS


# (Punto2D) ........................

$(OBJ)/Punto2D.o : $(SRC)/Punto2D.cpp $(INCLUDE)/Punto2D.h \
                   $(INCLUDE_UTILS)/Utils.h 
	@echo 
	@echo Creando objeto: Punto2D.o
	@echo 
	g++ -c -o $(OBJ)/Punto2D.o $(SRC)/Punto2D.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

$(LIB)/libPunto2D.a : $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o
	@echo 
	@echo Creando biblioteca: libPunto2D.a
	@echo 
	ar rvs $(LIB)/libPunto2D.a $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o


$(OBJ)/SecuenciaPunto2D.o : $(SRC)/SecuenciaPunto2D.cpp \
                            $(INCLUDE)/SecuenciaPunto2D.h \
                            $(INCLUDE)/Punto2D.h
	@echo 
	@echo Creando objeto: SecuenciaPunto2D.o
	@echo 
	g++ -c -o $(OBJ)/SecuenciaPunto2D.o $(SRC)/SecuenciaPunto2D.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

$(LIB)/libSecuenciaPunto2D.a : $(OBJ)/SecuenciaPunto2D.o  \
                               $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o
	@echo 
	@echo Creando biblioteca: libSecuenciaPunto2D.a
	@echo 
	ar rvs $(LIB)/libSecuenciaPunto2D.a \
	 	 $(OBJ)/SecuenciaPunto2D.o  $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o


# (Utils) ........................

$(OBJ_UTILS)/Utils.o : $(SRC_UTILS)/Utils.cpp \
                       $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: Utils.o 
	@echo  
	g++ -c -o $(OBJ_UTILS)/Utils.o $(SRC_UTILS)/Utils.cpp \
        -I$(INCLUDE_UTILS) -std=c++14

$(LIB_UTILS)/libUtils.a : $(OBJ_UTILS)/Utils.o 
	@echo 
	@echo Creando biblioteca: libUtils.a 
	@echo  
	ar -rvs $(LIB_UTILS)/libUtils.a $(OBJ_UTILS)/Utils.o 

# (Secuencia) ........................
 
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++14

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos de $(PROYECTO)...

	-rm $(OBJ)/PuntoMedio.o
	-rm $(OBJ)/SeleccionPuntos.o
	-rm $(OBJ)/Busca.o 
	-rm $(OBJ)/Cabecera.o 
	-rm $(OBJ)/Final.o 
	-rm $(OBJ)/VI_Demo-Secuencia.o

	@echo ...Borrados objetos de $(PROYECTO)
	@echo

clean-libs: 
	@echo Borrando modulos objeto y bibliotecas de $(PROYECTO)...


	-rm $(OBJ)/Punto2D.o
	-rm $(LIB)/libPunto2D.a 
	
	-rm $(OBJ)/SecuenciaPunto2D.o	
	-rm $(LIB)/libSecuenciaPunto2D.a 

	-rm $(OBJ_UTILS)/Utils.o 
	-rm $(LIB_UTILS)/libUtils.a

	-rm $(OBJ)/Secuencia.o 
	-rm $(LIB)/libSecuencia.a

	@echo ...Borrados modulos objeto y bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...

	-rm $(BIN)/PuntoMedio
	-rm $(BIN)/SeleccionPuntos
	-rm $(BIN)/NumeraLineas 
	-rm $(BIN)/Diferencias 
	-rm $(BIN)/MezclaFicheros 
	-rm $(BIN)/Busca 
	-rm $(BIN)/Cabecera 
	-rm $(BIN)/Final 
	-rm $(BIN)/VI_Demo-Secuencia

	@echo ...Borrados ejecutables de $(PROYECTO)
	@echo 	

mr.proper:  clean clean-bins
