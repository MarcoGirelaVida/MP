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

all: $(BIN)/EJ-6	 $(BIN)/EJ-7 $(BIN)/EJ-8
	@echo Terminado
	
presentacion:
	@echo Autor = $(AUTOR)
	
$(BIN)/$(n): $(SRC)/$(n).cpp
	g++ -o $(BIN)/$(n) $(SRC)/$(n).cpp
	
$(OBJ)/$(n).o: $(SRC)/$(n).cpp
	g++ -c -o $(OBJ)/$(n).o $(SRC)/$(n).cpp
	
$(BIN)/$(n)-en-dos-pasos: $(OBJ)/$(n).o
	g++ -o $(BIN)/$(n)-en-dos-pasos $(OBJ)/$(n).o

$(OBJ)/ProcesamientoArrayInt.o: $(SRC)/ProcesamientoArrayInt.cpp
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o $(SRC)/ProcesamientoArrayInt.cpp -I./include

$(OBJ)/EJ-6.o: $(SRC)/EJ-6.cpp
	g++ -c -o $(OBJ)/EJ-6.o $(SRC)/EJ-6.cpp -I./include

$(OBJ)/EJ-7.o: $(SRC)/EJ-7.cpp
	g++ -c -o $(OBJ)/EJ-7.o $(SRC)/EJ-7.cpp -I./include

$(OBJ)/EJ-8.o: $(SRC)/EJ-8.cpp
	g++ -c -o $(OBJ)/EJ-8.o $(SRC)/EJ-8.cpp -I./include

$(BIN)/EJ-6: $(OBJ)/EJ-6.o $(OBJ)/ProcesamientoArrayInt.o
	g++ -o $(BIN)/EJ-6 $(OBJ)/EJ-6.o $(OBJ)/ProcesamientoArrayInt.o -I./include
	
$(BIN)/EJ-7: $(OBJ)/EJ-7.o $(OBJ)/ProcesamientoArrayInt.o
	g++ -o $(BIN)/EJ-7 $(OBJ)/EJ-7.o $(OBJ)/ProcesamientoArrayInt.o -I./include
	
$(BIN)/EJ-8: $(OBJ)/EJ-8.o $(OBJ)/ProcesamientoArrayInt.o
	g++ -o $(BIN)/EJ-8 $(OBJ)/EJ-8.o $(OBJ)/ProcesamientoArrayInt.o -I./include
	
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
