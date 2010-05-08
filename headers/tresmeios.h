#ifndef H_3MEIOS
#define H_3MEIOS

#include<GL/glut.h>
#include<math.h>
#include "debug.h"

/* ===Funções=== */

/* Funções referentes ao trabalho 3 meios */

void desenha3Meios(GLdouble x, GLdouble y, int n, GLdouble lado);

void defineCorInterpolada(int n, GLdouble *p);


/* ===Constantes=== */

/* Como o número de operações é O(3^N), 
   para N > 12 a eficiência do programa fica seriamente
   comprometida. 10 é recomendável para uma velocidade aceitável */
#define NMAX_RECOMENDADO 12

#endif /* H_3MEIOS */
