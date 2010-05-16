all: linux

linux: main tresmeios rostorobo movimentos curvas help menu headers/debug.h
	g++ -o trabalho1compgraf_linux -fwhole-program -lglui -lglut -lGLU -lm -O2 -Wall -Wextra main.o tresmeios.o movimentos.o rostorobo.o curvas.o help.o menu.o

main: src/main.c headers/main.h
	g++ -c -o main.o -O2 -Wall -Wextra src/main.c 

tresmeios: src/tresmeios.c headers/tresmeios.h
	g++ -c -o tresmeios.o -O2 -Wall -Wextra src/tresmeios.c

rostorobo: src/rostorobo.c headers/rostorobo.h
	g++ -c -o movimentos.o -O2 -Wall -Wextra src/movimentos.c

movimentos: src/movimentos.c headers/movimentos.h
	g++ -c -o rostorobo.o -O2 -Wall -Wextra src/rostorobo.c

curvas: src/curvas.c headers/curvas.h
	g++ -c -o curvas.o -O2 -Wall -Wextra src/curvas.c

help: src/help.c headers/help.h
	g++ -c -o help.o -O2 -Wall -Wextra src/help.c

menu: src/menu.c headers/menu.h
	g++ -c -o menu.o -O2 -Wall -Wextra src/menu.c

#win: src/main.c headers/main.h

clean: 
	rm trabalho1compgraf_linux
	rm main.o
	rm tresmeios.o
	rm movimentos.o
	rm rostorobo.o
	rm curvas.o
	rm help.o
	rm menu.o
