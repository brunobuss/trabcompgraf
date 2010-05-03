all: linux

linux: src/main.c headers/main.h
	gcc -o trabalho1compgraf_linux src/main.c -lglut

win: src/main.c headers/main.h

clean: 
	rm trabalho1compgraf_linux
