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

#ifndef H_BUTTERFLY
#define H_BUTTERFLY

#include <GL/glui.h>
#include <GL/glut.h>
#include <math.h>
#include "debug.h"

/* Desenha as curvas :) */
void desenhaCurvas();

/* Varia a cor da curva */
void defineCor(GLdouble *p);

/* Alterna entre as duas curvas */
void trocaCurva();

/* Constroe componentes do menu GLUI, referentes a parametros internos das curvas */
void menuParametrosCurvas(GLUI *menu, GLUI_Panel *painel);

/* Reseta a rotação do "mundo" */
void resetaRotacao(int id);

#define PI    (3.14159)
#define TWOPI (6.28318)
/* Equações da Butterfly:
   http://local.wasp.uwa.edu.au/~pbourke//geometry/butterfly/ */
#define CURVA_BUTTERFLY 1
#define BF_U (i * 24.0 * PI / N_Butterfly) 
#define BF_PX (cos(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))
#define BF_PY (sin(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))
#define BF_PZ (fabs(py) / 2.0)


/* Equações da Chrysanthemum
   http://local.wasp.uwa.edu.au/~pbourke//geometry/chrysanthemum/ */
#define CURVA_CHRYSANTHEMUM 2
#define CH_U (i * 21.0 * PI / N_Chrysanthemum)
#define CH_P4 (sin(17 * u / 3))
#define CH_P8 (sin(2 * cos(3 * u) - 28 * u))
#define CH_R (5*(1 + sin(11*u/5)) - 4*CH_P4*CH_P4*CH_P4*CH_P4 * CH_P8*CH_P8*CH_P8*CH_P8*CH_P8*CH_P8*CH_P8*CH_P8)
#define CH_PX (CH_R * cos(u)) 
#define CH_PY (CH_R * sin(u))
#define CH_PZ ((CH_R/20.0 + 2) * sin(CH_R * TWOPI/7.0))



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
