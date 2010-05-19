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

#include "../headers/help.h"

/* Texto a ser exibido na janela de HELP */
char texto[N_LINHAS][TAM_LINHAS] = {
		"Trabalho 1 de Computacao Grafica - 2010/1. Prof: Paulo Roma.\0",
		"\0",
		"Alunos:\0",
		"Bruno C. Buss (DRE 106087954) <bruno dot buss at gmail dot com>\0",
		"Diego P. Cardoso (DRE 106028188) <diegopc86 at gmail dot com>\0",
		"\0",
		"Site do projeto: http://github.com/brunobuss/trabcompgraf\0",
		"\0",
		"Viewport 1: 3Meios.\0",
		"    Botao esquerdo do mouse: Zoom In\0",
		"    Botao direito do mouse: Zoom Out\0",
		"    Pressione R para Retornar ao zoom original\0",
		"\0",
		"Viewport 2: RostoRobo\0",
		"    Botao esquerdo/direito do mouse: Picada do 'Mousequito' tipo 1 e 2\0",
		"    Pressione L para Limpar o rosto do robo\0",
		"\0",
		"Viewport 3: Composicao de movimentos\0",
		"    Pressione A para Apagar o rastro\0",
		"\0",
		"Viewport 4: Curvas (Butterfly e Chrysanthemum)\0",
		"    Duas curvas com transicao dinamica e alteracao suave de cores\0",
		"    Botao esquerdo do mouse (ou a tecla T): Trocar entre as duas curvas\0",
		"\0",
		"Algumas opcoes das animacoes podem ser configuradas/alteradas pelo menu\0",
		"Pressione H para retornar as animacoes\0"};
		
void desenhaHelp(GLdouble l, GLdouble a)
{
	int i, j;
	GLdouble posx =  10.0,
		 posy = 420.0;
	 
		 
	glColor4f(0.0, 0.0, 0.0, 0.8);
	
	glBegin(GL_POLYGON);
		glVertex2d(0.0, 0.0);
		glVertex2d(  l, 0.0);
		glVertex2d(  l,   a);
		glVertex2d(0.0,   a);
	glEnd();

	
	glColor4f(1.0, 1.0, 1.0, 0.95);
		 
	for(i = 0; i < N_LINHAS; i++)
	{
		glRasterPos2d(posx, posy);

		for(j = 0; texto[i][j] != 0; j++)
		{
			glutBitmapCharacter(FONTE_TEXTO, texto[i][j]);
		}

		posy -= 15.0;
	}
	
	
  
  
  
  
  
  
}
