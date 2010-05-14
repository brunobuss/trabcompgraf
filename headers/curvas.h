#ifndef H_BUTTERFLY
#define H_BUTTERFLY

#include <GL/glut.h>
#include <math.h>
#include "debug.h"

/* Desenha as curvas :) */
void desenhaCurvas();

/* Varia a cor da curva */
void defineCor(GLdouble *p);

/* Alterna entre as duas curvas */
void trocaCurva();

#define PI 3.14159
/* Equações da Butterfly:
   http://local.wasp.uwa.edu.au/~pbourke//geometry/butterfly/ */
#define CURVA_BUTTERFLY 1
#define BF_U (i * 24.0 * PI / N_Butterfly) 
#define BF_PX (cos(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))
#define BF_PY (sin(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))

/* Equações da Chrysanthemum
   http://local.wasp.uwa.edu.au/~pbourke//geometry/chrysanthemum/ */
#define CURVA_CHRYSANTHEMUM 2
#define CH_U (i * 21.0 * PI / N_Chrysanthemum)
#define CH_P4 (sin(17 * u / 3))
#define CH_P8 (sin(2 * cos(3 * u) - 28 * u))
#define CH_R (5*(1 + sin(11*u/5)) - 4*CH_P4*CH_P4*CH_P4*CH_P4 * CH_P8*CH_P8*CH_P8*CH_P8*CH_P8*CH_P8*CH_P8*CH_P8)
#define CH_PX (CH_R * cos(u)) 
#define CH_PY (CH_R * sin(u))



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

#define COR_FADE_TO_BLACK	20
#define COR_FADE_TO_COLOR	21
#endif
