#include "../headers/help.h"

/* Texto a ser exibido na janela de HELP */
char texto[N_LINHAS][TAM_LINHAS] = {
		"Trabalho 1 de Computacao Grafica - 2010/1\0",
		"\0",
		"Alunos:\0",
		"Bruno C. Buss <bruno dot buss at gmail dot com>\0",
		"Diego Cardoso <diegopc86 at gmail dot com>\0",
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
		
void desenhaHelp()
{
	int i, j;
	GLdouble posx =  10.0,
		 posy = 420.0;
	 
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