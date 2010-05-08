all: linux

linux: src/main.c src/tresmeios.c headers/main.h headers/tresmeios.h
	gcc -o trabalho1compgraf_linux src/main.c src/tresmeios.c -lglut -lm -lGLU

win: src/main.c headers/main.h

clean: 
	rm trabalho1compgraf_linux
