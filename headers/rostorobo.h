#ifndef H_ROSTOROBO
#define H_ROSTOROBO

#include<GL/glut.h>
#include<math.h>
#include "debug.h"

/* ===Funções=== */
void RostoRobo();

void adicionaPicada(GLdouble x, GLdouble y);

void desenhaFundoRosto();
void desenhaFundoBoca();
void desenhaDentes();
void desenhaCirculo(GLdouble x, GLdouble y, GLdouble *cor);
void desenhaElipse(GLdouble x, GLdouble y, GLdouble *cor);


/* ===Constantes=== */
#define N_PICADAS 1024

#define BOCA_FECHADA  0
#define BOCA_ABRINDO  1
#define BOCA_ABERTA   2
#define BOCA_FECHANDO 3

#define PICADA_TIPO 0
#define PICADA_COORDENADA_X 1
#define PICADA_COORDENADA_Y 2

#endif
