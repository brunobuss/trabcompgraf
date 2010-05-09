all: linux

linux: main tresmeios rostorobo movimentos headers/debug.h
	gcc -o trabalho1compgraf_linux main.o tresmeios.o movimentos.o rostorobo.o -lglut -lGLU -lm -O2

main: src/main.c headers/main.h
	gcc -c -o main.o src/main.c

tresmeios: src/tresmeios.c headers/tresmeios.h
	gcc -c -o tresmeios.o src/tresmeios.c

rostorobo: src/rostorobo.c headers/rostorobo.h
	gcc -c -o movimentos.o src/movimentos.c

movimentos: src/movimentos.c headers/movimentos.h
	gcc -c -o rostorobo.o src/rostorobo.c

#win: src/main.c headers/main.h

clean: 
	rm trabalho1compgraf_linux
	rm main.o
	rm tresmeios.o
	rm movimentos.o
	rm rostorobo.o
