#ifndef H_3MEIOS
#define H_3MEIOS

#include <GL/glui.h>
#include <GL/glut.h>
#include <math.h>
#include "debug.h"

/* ===Funções=== */

/* Funções referentes ao trabalho 3 meios */

/* Função recursiva para o desenho do 3Meios */
void desenha3Meios(GLdouble x, GLdouble y, int n, GLdouble lado);

/* Função para a transição de cores */
void defineCorInterpolada(int n, GLdouble *p);

/* Constroe componentes do menu GLUI, referentes a parametros internos do 3 Meios */
void menuParametros3Meios(GLUI *menu, GLUI_Panel *painel);

/* ===Constantes=== */

/* Como o número de operações é O(3^N), 
   para N > 12 a eficiência do programa fica seriamente
   comprometida. 10 é recomendável para uma velocidade aceitável */
#define NMAX_RECOMENDADO 10

#endif /* H_3MEIOS */
