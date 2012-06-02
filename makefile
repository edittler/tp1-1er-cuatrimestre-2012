# Makefile para la compilación del proyecto del arbo kd
# que almacena estadística sobre fallas y accidentes de trenes.

# Compilador a usar
GPP = g++ 

# Carpetas 
SRC = src
CAM = src/campo
OBJ = obj

# Flags
CFLAGS = -Wall -g -c
GFLAGS = -Wall -g

all: campos.o arbol.o kdarbol
	@echo El TP0 ya a sido compilado!

kdarbol:
	@$(GPP) *.o -o main

arbol.o:
	$(GPP) $(CFLAGS) $(SRC)/*.cpp 

campos.o:
	$(GPP) $(CFLAGS) $(CAM)/*.cpp

clean:
	rm -rf *.o *.bin

	
	
