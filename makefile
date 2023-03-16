#Primer fichero-makefile
#USO: make objetivo/nombre-deseado n=nombre-deseado
AUTOR = Marco
HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
BIN = $(HOME)/bin
extras = $(HOME)/MP_sesion$(n)/src $(HOME)/MP_sesion$(n)/include $(HOME)/MP_sesion$(n)/lib $(HOME)/MP_sesion$(n)/obj $(HOME)/MP_sesion$(n)/bin

presentacion:
	@echo Autor: $(AUTOR)

nuevo:
	if [ -d $(HOME)/MP_sesion$(n) ]; then \
		echo "El proyecto $(n) ya existe, ¿Quieres continuar? (y/n)"; \
		read -n 1 respuesta; \
		if [ "$$respuesta" == "y" ]; then \
			rm -rf $(HOME)/MP_sesion$(n); \
			mkdir $(HOME)/MP_sesion$(n); \
			mkdir $(extras); \
			cp $(HOME)/makefile $(HOME)/MP_sesion$(n)/makefile$(n).mak; \
			echo "Hecho"; \
		elif [ "$$respuesta" == "n" ]; then \
			echo "Saliendo..."; \
		else \
			echo "Respuesta inválida. Saliendo..."; \
		fi \
	else \
		mkdir $(HOME)/MP_sesion$(n); \
		mkdir $(extras); \
		cp $(HOME)/makefile $(HOME)/MP_sesion$(n)/makefile$(n).mak; \
		echo "Hecho"; \
	fi; \

	for ((i=0; i<$(p); i++)); do \
		cp .plantilla.cpp $(HOME)/MP_sesion$(n)/src/$$i.cpp; \
	done

borrar:
	echo "Estas seguro de que quieres borrar la carpeta MP_sesion$(n)? (y/n)"; \
	read -n 1 respuesta; \
	if [ "$$respuesta" == "y" ]; then \
		rm -rf $(HOME)/MP_sesion$(n); \
	elif [ "$$respuesta" == "n" ]; then \
		echo "Saliendo..."; \
	else \
		echo "Respuesta inválida. Saliendo..."; \
	fi 

comprimir:
	tar -cvf MP_sesion$(n).tar MP_sesion$(n)/

	
mr.proper: clean
	-rm $(BIN)/*
	@echo Los ejecutables han sido eliminados
	-rm $(LIB)/*
	@echo Las librerias han sido eliminadas
	
clean:
	-rm $(OBJ)/*
	@echo Objetos borrados
