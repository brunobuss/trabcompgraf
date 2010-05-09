all: linux

linux: src/main.c src/tresmeios.c src/movimentos.c src/rostorobo.c src/butterfly.c headers/main.h headers/tresmeios.h headers/movimentos.h headers/rostorobo.h headers/debug.h headers/butterfly.h
	gcc -o trabalho1compgraf_linux src/main.c src/tresmeios.c src/movimentos.c src/rostorobo.c src/butterfly.c -lglut -lGLU -lm

#win: src/main.c headers/main.h

clean: 
	rm trabalho1compgraf_linux
