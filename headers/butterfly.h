#ifndef H_BUTTERFLY
#define H_BUTTERFLY

#include <GL/glut.h>
#include <math.h>
#include "debug.h"

/* Desenha a borboleta na tela :) */
void desenhaButterfly();

/* Varia a cor da borboleta */
void defineCorButterfly(GLdouble *p);

/* Equações da Butterfly:
   http://local.wasp.uwa.edu.au/~pbourke//geometry/butterfly/ */

#define PI 3.14159
#define FU(u) (i * 24.0 * PI / N) 
#define PX(u) (cos(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))
#define PY(u) (sin(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))


/* Combinação de cores */
#define COR_RED_BLUE 		0
#define COR_RED_GREEN		1
#define COR_RED_CYAN		2
#define COR_RED_MAGENTA 	3

#define COR_GREEN_BLUE 		4
#define COR_GREEN_RED		5
#define COR_GREEN_CYAN  	6
#define COR_GREEN_MAGENTA	7

#define COR_BLUE_RED		8
#define COR_BLUE_GREEN		9
#define COR_BLUE_CYAN		10
#define COR_BLUE_MAGENTA	11

#define COR_CYAN_RED		12
#define COR_CYAN_GREEN		13
#define COR_CYAN_BLUE		14
#define COR_CYAN_MAGENTA	15

#define COR_MAGENTA_RED		16
#define COR_MAGENTA_GREEN	17
#define COR_MAGENTA_BLUE	18
#define COR_MAGENTA_CYAN	19

#endif
