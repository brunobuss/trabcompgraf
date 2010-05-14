all: linux

linux: main tresmeios rostorobo movimentos curvas headers/debug.h
	gcc -o trabalho1compgraf_linux -fwhole-program -lglut -lGLU -lm -O2 -Wall -Wextra main.o tresmeios.o movimentos.o rostorobo.o curvas.o 

main: src/main.c headers/main.h
	gcc -c -o main.o -O2 -Wall -Wextra src/main.c 

tresmeios: src/tresmeios.c headers/tresmeios.h
	gcc -c -o tresmeios.o -O2 -Wall -Wextra src/tresmeios.c

rostorobo: src/rostorobo.c headers/rostorobo.h
	gcc -c -o movimentos.o -O2 -Wall -Wextra src/movimentos.c

movimentos: src/movimentos.c headers/movimentos.h
	gcc -c -o rostorobo.o -O2 -Wall -Wextra src/rostorobo.c

curvas: src/curvas.c headers/curvas.h
	gcc -c -o curvas.o -O2 -Wall -Wextra src/curvas.c

#win: src/main.c headers/main.h

clean: 
	rm trabalho1compgraf_linux
	rm main.o
	rm tresmeios.o
	rm movimentos.o
	rm rostorobo.o
	rm curvas.o
