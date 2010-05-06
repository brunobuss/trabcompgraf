#ifndef H_MAIN
#define H_MAIN

#include<GL/glut.h>
#include<stdio.h> /* Para printfs de debug e outras informações :) */
#include "tresmeios.h"


/* ===Funções=== */
/* Funcão de inicialização do OpeniGL/GLUT/GLUI */
void setupGlut(int *argc, char *argv[]);

/* Ciclo de redraw da janela */
void desenhaCallBack(void);
/* Processamento enquanto a aplicação está em idle */
void idleCallBack();
/* Resposta a ações do teclado */
void tecladoCallBack(unsigned char tecla, int x, int y);
/* Resposta a ações do mouse */
void mouseCallBack(int button, int state, int x, int y);
/* Redimensionamento da janela */
void redimensionaCallBack(int w, int h);
/* Temporizador responsavel pelo controle da contagem de FPS */
void timerFPS(int valor);


/* Prepara um dos 4 quadrantes para desenho
   i = 1 -> superior esquerdo
     = 2 -> superior direito
     = 3 -> inferior esquerdo
     = 4 -> inferior direito */
void selecionaViewport(int i);

/* Define os limites das coordenadas que irão aparecer na viewport */
void defineCoordenadas(GLdouble inicial, GLdouble final);

/* Cria uma borda em torno da área de desenho com espessura tam e cores (red,green,blue) */
void desenhaBorda(GLdouble inicial, GLdouble final, GLfloat red, GLfloat green, GLfloat blue, GLfloat tam);

/* ===Constantes=== */
/* Indica se o programa deve imprimir informações de debug */
#define DEBUG 1

/* Configurações inicial dos programa */
#define CONFIG_DISPLAYMODE GLUT_DOUBLE | GLUT_RGB
#define CONFIG_TAMHOR_INICIAL 500
#define CONFIG_TAMVER_INICIAL 500
#define CONFIG_POSX_INICIAL 100
#define CONFIG_POSY_INICIAL 100
#define CONFIG_TITULO_JANELA "Trabalho 1 de Computacao Grafica (DCC-UFRJ) 2010/1"

/* Quadros por segundo desejado */
#define CONFIG_FPS 50
#define CONFIG_FPS_TIMER 1000/CONFIG_FPS

#define VIEWPORT_SUPERIOR_ESQUERDA 0
#define VIEWPORT_SUPERIOR_DIREITA  1
#define VIEWPORT_INFERIOR_ESQUERDA 2
#define VIEWPORT_INFERIOR_DIREITA  3

#define CONFIG_TAM_BORDA 1.0

/* Macros */
#define DBG(x) if(DEBUG) { x; }


#endif /* H-MAIN */
