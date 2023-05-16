AUTOR = Marco Girela Vida
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
	@if [ -d $(HOME)/MP_sesion$(n) ]; then \
		echo "El proyecto $(n) ya existe, ¿Quieres continuar? (y/n)"; \
		read -n 1 respuesta; \
		if [ "$$respuesta" == "y" ]; then \
			rm -rf $(HOME)/MP_sesion$(n); \
			mkdir $(HOME)/MP_sesion$(n); \
			mkdir $(extras); \
			cp $(HOME)/.templates/template_makefile.mak $(HOME)/MP_sesion$(n)/makefile$(n).mak; \
			cp $(HOME)/.templates/template_code.cpp $(HOME)/MP_sesion$(n)/src/V_.cpp; \
			cp $(HOME)/.templates/template_headers.h $(HOME)/MP_sesion$(n)/include/headers.h; \
			echo "Hecho"; \
		elif [ "$$respuesta" == "n" ]; then \
			echo "Saliendo..."; \
		else \
			echo "Respuesta inválida. Saliendo..."; \
		fi \
	else \
		mkdir $(HOME)/MP_sesion$(n); \
		mkdir $(extras); \
		cp $(HOME)/.templates/template_makefile.mak $(HOME)/MP_sesion$(n)/makefile$(n).mak; \
		cp $(HOME)/.templates/template_code.cpp $(HOME)/MP_sesion$(n)/src/V_.cpp; \
		cp $(HOME)/.templates/template_headers.h $(HOME)/MP_sesion$(n)/include/headers.h; \
	fi; \


borrar:
	@echo "Estas seguro de que quieres borrar la carpeta MP_sesion$(n)? (y/n)"; \
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
