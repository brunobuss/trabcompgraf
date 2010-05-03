#ifndef H_MAIN
#define H_MAIN

#include<GL/glut.h>
#include<stdio.h> /* Para printfs de debug e outras informações :) */

/* Funcão de inicialização do OpenGL/GLUT/GLUI */
void setupGlut(int *argc, char *argv[]);

/* Funções de callback do GLUT: */
/* Ciclo de redraw da janela */
void displayCallBack(void);
/* Processamento enquanto a aplicação está em idle */
void idleCallBack();
/* Resposta a ações do teclado */
void tecladoCallBack(unsigned char tecla, int x, int y);
/* Resposta a ações do mouse */
void mouseCallBack(int button, int state, int x, int y);
/* Redimensionamento da janela */
void reshapeCallBack(int w, int h);
/* Temporizador responsavel pelo controle da contagem de FPS */
void timerFPS(int valor);



/* Constantes utilizadas */
/* Indica se o programa deve imprimir informações de debug */
#define DEBUG 1

#define CONFIG_DISPLAYMODE GLUT_DOUBLE | GLUT_RGB
#define CONFIG_TAMHOR_INICIAL 500
#define CONFIG_TAMVER_INICIAL 500
#define CONFIG_POSX_INICIAL 100
#define CONFIG_POSY_INICIAL 100
#define CONFIG_TITULO_JANELA "Trabalho 1 de Computacao Grafica (DCC-UFRJ) 2010/1"

#define CONFIG_FPS 50
#define CONFIG_FPS_TIMER 1000/CONFIG_FPS


/* Macros */
#define DBG(x) if(DEBUG) { x; }


#endif /* H-MAIN */
