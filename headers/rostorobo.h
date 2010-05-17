/*
Copyright (c) 2010 Bruno C. Buss and Diego Cardoso

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef H_ROSTOROBO
#define H_ROSTOROBO

#include <GL/glui.h>
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

/* Funções para que os olhos do robo possam seguir o mouse */
void mousequitoNoRostoRobo(GLdouble x, GLdouble y);
void mousequitoSaiuDoRosto();

/* Função para apagar todas as picadas do RostoRobo */
void apagaPicadasRostoRobo(void);

/* Constroe componentes do menu GLUI, referentes a parametros internos do Rosto Robo */
void menuParametrosRostoRobo(GLUI *menu, GLUI_Panel *painel);

/* ===Constantes=== */
#define N_PICADAS 20000

#define BOCA_FECHADA  0
#define BOCA_ABRINDO  1
#define BOCA_ABERTA   2
#define BOCA_FECHANDO 3

#define PICADA_COORDENADA_X 0
#define PICADA_COORDENADA_Y 1

#define SEM_PICADA      0
#define PICADA_ESQUERDA 1
#define PICADA_DIREITA  2

#endif
