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
