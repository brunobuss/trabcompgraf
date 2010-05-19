all: linux

linux: main tresmeios rostorobo movimentos curvas help headers/debug.h
	g++ -o trabalho1compgraf_linux -fwhole-program -O2 -Wall -Wextra main.o tresmeios.o movimentos.o rostorobo.o curvas.o help.o -lglui -lglut -lGLU -lGL -lm 

#Compilação para Windows NAO FOI TESTADA pois nenhum dos membros utilizava ambiente Windows durante o desenvolvimento do projeto
win: main tresmeios rostorobo movimentos curvas help headers/debug.h
	g++ -o trabalho1compgraf_win.exe -O2 -Wall -Wextra main.o tresmeios.o movimentos.o rostorobo.o curvas.o help.o -lglui32 -lglut32 -lglu32 -lopengl32 -lm 

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

clean: 
	rm trabalho1compgraf_linux
	rm main.o
	rm tresmeios.o
	rm movimentos.o
	rm rostorobo.o
	rm curvas.o
	rm help.o

