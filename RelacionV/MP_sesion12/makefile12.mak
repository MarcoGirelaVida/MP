#***************************************************************************/
#***************************************************************************/
# METODOLOGIA DE LA PROGRAMACION
#
# AUTOR: MARCO GIRELA VIDA
# GRUPO: 1ºB
# FECHA: xx/05/2023
#
# RELACION DE PROBLEMAS 4
#
# makefile0_.mak
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
      $(BIN)/Cuentalineas \
	  $(BIN)/CopiaLineasSinAlmohadilla\
	  $(BIN)/CuentaCaracteresConcretos\
	  $(BIN)/CuentaPalabrasLongitudConcreta\
	  $(BIN)/Cuenta_palabras_por_linea\
	  $(BIN)/VerificaDatosMatriz2D\
	  final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas V
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

$(BIN)/Cuentalineas : $(SRC)/Cuentalineas.cpp                    
	@echo 
	@echo Creando ejecutable: Cuentalineas
	@echo 
	g++ -o $(BIN)/Cuentalineas $(SRC)/Cuentalineas.cpp -std=c++14

$(BIN)/CuentaPalabrasLongitudConcreta : $(SRC)/CuentaPalabrasLongitudConcreta.cpp                    
	@echo 
	@echo Creando ejecutable: CuentaPalabrasLongitudConcreta
	@echo 
	g++ -o $(BIN)/CuentaPalabrasLongitudConcreta $(SRC)/CuentaPalabrasLongitudConcreta.cpp -std=c++14

$(BIN)/CopiaLineasSinAlmohadilla : $(SRC)/CopiaLineasSinAlmohadilla.cpp                    
	@echo 
	@echo Creando ejecutable: CopiaLineasSinAlmohadilla
	@echo 
	g++ -o $(BIN)/CopiaLineasSinAlmohadilla $(SRC)/CopiaLineasSinAlmohadilla.cpp -std=c++14

$(BIN)/Cuenta_palabras_por_linea : $(SRC)/Cuenta_palabras_por_linea.cpp                    
	@echo 
	@echo Creando ejecutable: Cuenta_palabras_por_linea
	@echo 
	g++ -o $(BIN)/Cuenta_palabras_por_linea $(SRC)/Cuenta_palabras_por_linea.cpp -std=c++14

$(BIN)/VerificaDatosMatriz2D : $(SRC)/VerificaDatosMatriz2D.cpp                    
	@echo 
	@echo Creando ejecutable: VerificaDatosMatriz2D
	@echo 
	g++ -o $(BIN)/VerificaDatosMatriz2D $(SRC)/VerificaDatosMatriz2D.cpp -std=c++14

$(BIN)/CuentaCaracteresConcretos : $(SRC)/CuentaCaracteresConcretos.cpp                    
	@echo 
	@echo Creando ejecutable: CuentaCaracteresConcretos
	@echo 
	g++ -o $(BIN)/CuentaCaracteresConcretos $(SRC)/CuentaCaracteresConcretos.cpp -std=c++14

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