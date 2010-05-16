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

void movimentos(GLdouble lado, GLfloat ang, GLfloat desl, GLfloat tempo);

void setPontosBola(int i, GLdouble angulo, int cor);

void apagaRastro();

/* ===Constantes=== */


#define ARESTA_DIREITA      0
#define ARESTA_INFERIOR     1
#define ARESTA_ESQUERDA     2
#define ARESTA_SUPERIOR     3
#define ARESTA_NULA         4 //Quando o sistema é iniciado.

#endif
