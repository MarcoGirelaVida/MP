#Primer fichero-makefile
#USO: make objetivo/nombre-deseado n=nombre-deseado
AUTOR = Marco
HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin
extras = $(HOME)/P-$(n)/src $(HOME)/P-$(n)/include $(HOME)/P-$(n)/lib $(HOME)/P-$(n)/obj $(HOME)/P-$(n)/bin

all: $(BIN)/$(n) $(BIN)/$(n)-en-dos-pasos
	@cho Terminado
	
presentacion:
	@echo Autor = $(AUTOR)
	
$(BIN)/$(n): $(SRC)/$(n).cpp
	g++ -o $(BIN)/$(n) $(SRC)/$(n).cpp
	
$(OBJ)/$(n).o: $(SRC)/$(n).cpp
	g++ -c -o $(OBJ)/$(n).o $(SRC)/$(n).cpp
	
$(BIN)/$(n)-en-dos-pasos: $(OBJ)/$(n).o
	g++ -o $(BIN)/$(n)-en-dos-pasos $(OBJ)/$(n).o
	
nuevo-P:
	if [ -d $(HOME)/P-$(n) ]; then \
		echo "La carpeta P-$(n) ya existe, ¿Quieres continuar? (y/n)"; \
		read -n 1 respuesta; \
		if [ "$$respuesta" == "y" ]; then \
			rm -rf $(HOME)/P-$(n); \
			mkdir $(HOME)/P-$(n); \
			mkdir $(extras); \
			cp $(HOME)/makefile $(HOME)/P-$(n)/makefile; \
			echo "Hecho"; \
		elif [ "$$respuesta" == "n" ]; then \
			echo "Saliendo..."; \
		else \
			echo "Respuesta inválida. Saliendo..."; \
		fi \
	else \
		mkdir $(HOME)/P-$(n); \
		mkdir $(extras); \
		cp $(HOME)/makefile $(HOME)/P-$(n)/makefile; \
		echo "Hecho"; \
	fi

borrar-P:
	echo "Estas seguro de que quieres borrar la carpeta P-$(n)? (y/n)"; \
	read -n 1 respuesta; \
	if [ "$$respuesta" == "y" ]; then \
		rm -rf $(HOME)/P-$(n); \
	elif [ "$$respuesta" == "n" ]; then \
		echo "Saliendo..."; \
	else \
		echo "Respuesta inválida. Saliendo..."; \
	fi 
	
mr.proper: clean
	-rm $(BIN)/*
	@echo Los ejecutables han sido eliminados
	-rm $(LIB)/*
	@echo Las $(LIB)rerias han sido eliminadas
	
clean:
	-rm $(OBJ)/*
	@echo $(OBJ)etos borrados
