#ifndef H_ROSTOROBO
#define H_ROSTOROBO

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include "debug.h"

/* ===Funções=== */

/* Desenha o rosto do Robo */
void RostoRobo();

/* Adiciona uma picada no ponto (x, y) do tipo t*/
void adicionaPicada(GLdouble x, GLdouble y, int t);
/* Sinaliza que o "mousequito" terminou a picada */
void terminouPicada();


/* Funções para desenhar os objetos geométricos da cara do robo */
void desenhaFundoRosto();
void desenhaFundoBoca();
void desenhaDentes();
void desenhaCirculo(GLdouble x, GLdouble y, GLdouble *cor);
void desenhaElipse(GLdouble x, GLdouble y, GLdouble *cor);
void desenhaPicadas();

/* Dispara o movimento de abrir/fechar a boca a cada BT segundos */
void mexeBocaTimer(int valor);

/* Calcula o movimento dos olhos */
void movimentaOlhos();

/* Verifica se o olho centrado em p2, esta contido na elipse centrada em p1 */
int verificaColisao(GLdouble p1x, GLdouble p1y, GLdouble p2x, GLdouble p2y);

/* ===Constantes=== */
#define N_PICADAS 20000

#define BOCA_FECHADA  0
#define BOCA_ABRINDO  1
#define BOCA_ABERTA   2
#define BOCA_FECHANDO 3

#define PICADA_COORDENADA_X 0
#define PICADA_COORDENADA_Y 1

#define PICADA_ESQUERDA 1
#define PICADA_DIREITA  2

#endif
