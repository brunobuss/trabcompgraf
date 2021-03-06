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

#ifndef H_MOVIMENTOS
#define H_MOVIMENTOS

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "debug.h"

/* ===Funções=== */

/* Funções referentes ao trabalho Movimentos */


/*
 *
 * Função principal que realiza o movimento do quadrado e
 * da "bolinha"pelas arestas do quadrado.
 *
 * A função desenha um quadrado de tamanho "lado" e o faz girar
 * "ang" graus a cada "tempo" frames, enquanto que uma bola se
 * desloca "desl" pelas arestas do quadrado no sentido horário
 */

void movimentos(GLdouble lado, GLfloat ang, GLfloat desl, int movimenta, int desenhaQuadrado, int desenhaBola, int desenhaRastro);

void setPontosBola(int i, GLdouble angulo, int cor);

void apagaRastro();

/* ===Constantes=== */

#define TAM_FILA 2048

#define ARESTA_DIREITA      0
#define ARESTA_INFERIOR     1
#define ARESTA_ESQUERDA     2
#define ARESTA_SUPERIOR     3
#define ARESTA_NULA         4 //Quando o sistema é iniciado.

#endif
