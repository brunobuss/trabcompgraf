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

#include "../headers/main.h"

/* Variáveis */
GLsizei tamJanelaX = CONFIG_TAMHOR_INICIAL;
GLsizei tamJanelaY = CONFIG_TAMVER_INICIAL;

GLdouble razaoX;
GLdouble razaoY;

/* Configuração das Viewports */
GLdouble vpLimites[5][4] = {    {-10.0,  10.0, -10.0,  10.0},
				{-30.0,  30.0, -30.0,  30.0},
				{-10.0,  10.0, -10.0,  10.0},
				{-40.0,  40.0, -30.0,  50.0},
				{  0.0, 450.0,   0.0, 450.0}};

GLfloat vpCorBorda[5][3] = {	{1.0, 1.0, 1.0},
				{1.0, 1.0, 1.0},
				{1.0, 1.0, 1.0},
				{1.0, 1.0, 1.0},
				{1.0, 1.0, 1.0}};


int redesenhaJanela = 1;
int mostraHelp	    = 0;

/* Referencia a nossa janela do GLUT, necessário devido ao GLUI */
int id_janela;

/* Objeto principal do GLUI */
GLUI *menu;

/* Parâmetros das chamadas das animações */
/* 3 Meios */
float	 	vp1_param_lado = 14.0;
/* Movimentos */
float		vp3_param_lado =  10.0;
float		vp3_param_ang  =   5.0;
float		vp3_param_desl =  -1.0;
int		vp3_nframes    =   1;
int		vp3_pframes    =  20; 
int		vp3_desenhaQuadrado    =   1; 
int		vp3_desenhaBolinha     =   1; 
int		vp3_desenhaRastro      =   1; 

int main(int argc, char *argv[])
{
	srand(time(NULL));

	setupGlut(&argc, argv);
	setupMenu();
	
	glutMainLoop();

	return 0;
}

void setupGlut(int *argc, char *argv[])
{

	DBG(printf("Configurando o GLUT...\n"));

	glutInit(argc, argv);
	glutInitDisplayMode(CONFIG_DISPLAYMODE);
	glutInitWindowSize(tamJanelaX, tamJanelaY);
	glutInitWindowPosition(CONFIG_POSX_INICIAL, CONFIG_POSY_INICIAL);
	id_janela = glutCreateWindow(CONFIG_TITULO_JANELA);

	glClearColor(0.0, 0.0, 0.0, 0.0); /* Define a cor do GL_COLOR_BUFFER_BIT */
	glShadeModel(GL_FLAT);
        glEnable(GL_POINT_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc(desenhaCallBack);
	glutReshapeFunc(redimensionaCallBack);
	glutKeyboardFunc(tecladoCallBack);
	glutMouseFunc(mouseCallBack);
	glutMotionFunc(rastreiaMouseCallBack);
	glutPassiveMotionFunc(rastreiaMouseCallBack);
	glutTimerFunc(CONFIG_FPS_TIMER, timerFPS, 1);

	DBG(printf("...GLUT configurado com sucesso\n"));
}

void setupMenu()
{
	GLUI_Panel *painelViewportSuperiorEsquerda;
	GLUI_Panel *painelViewportSuperiorDireita;
	GLUI_Panel *painelViewportInferiorEsquerda;
	GLUI_Panel *painelViewportInferiorDireita;
	GLUI_Spinner *vp1_lado;
	GLUI_Spinner *vp3_lado;
	GLUI_Spinner *vp3_ang;
	GLUI_Spinner *vp3_desl;
	GLUI_Spinner *vp3_frames;	
	GLUI_Panel   *vp3_desenha;
	
	menu = GLUI_Master.create_glui(MENU_NOME, 0, CONFIG_POSX_INICIAL + tamJanelaX + 10, CONFIG_POSY_INICIAL);

	/* Cabecalho */
	menu->add_statictext("Trabalho 1 de Computacao Grafica 2010/1");
	menu->add_statictext("Criado por: Bruno C. Buss e Diego Cardoso");
	menu->add_statictext("Aperte H para o Help sobre as funcionalidades da janela");

	
	/* Viewport 1 */
	menu->add_separator();
	painelViewportSuperiorEsquerda = menu->add_panel("Viewport 1: 3 Meios");
		
	vp1_lado = menu->add_spinner_to_panel(painelViewportSuperiorEsquerda, "Lado:" , GLUI_SPINNER_FLOAT, &vp1_param_lado);
	vp1_lado->set_float_limits(1.0, 200.0, GLUI_LIMIT_CLAMP);
	
	menuParametros3Meios(menu, painelViewportSuperiorEsquerda);
	
	
	
	/* Viewport 2 */
	menu->add_separator();
	painelViewportSuperiorDireita = menu->add_panel("Viewport 2: RostoRobo");
	menuParametrosRostoRobo(menu, painelViewportSuperiorDireita);
	
	
	/* Viewport 3 */
	menu->add_separator();
	painelViewportInferiorEsquerda = menu->add_panel("Viewport 3: Composicao de Movimentos");
	
	vp3_lado = menu->add_spinner_to_panel(painelViewportInferiorEsquerda, "Lado do quadrado:" , GLUI_SPINNER_FLOAT, &vp3_param_lado);
	vp3_lado->set_float_limits(1.0, 14.0, GLUI_LIMIT_CLAMP);
	vp3_lado->set_speed(0.5);
	
	vp3_ang = menu->add_spinner_to_panel(painelViewportInferiorEsquerda, "Angulo de rotacao:" , GLUI_SPINNER_FLOAT, &vp3_param_ang);
	vp3_ang->set_float_limits(-360, 360, GLUI_LIMIT_CLAMP);
	vp3_ang->set_speed(0.1);
	
	vp3_desl = menu->add_spinner_to_panel(painelViewportInferiorEsquerda, "Deslocamento da bolinha:" , GLUI_SPINNER_FLOAT, &vp3_param_desl);
	vp3_desl->set_float_limits(-10, 10, GLUI_LIMIT_CLAMP);
	vp3_desl->set_speed(0.1);

	vp3_frames = menu->add_spinner_to_panel(painelViewportInferiorEsquerda, "Frames por redesenho:" , GLUI_SPINNER_INT, &vp3_nframes);
	vp3_frames->set_int_limits(1, 50, GLUI_LIMIT_CLAMP);
	
	vp3_desenha = menu->add_panel_to_panel(painelViewportInferiorEsquerda, "Desenha:");
	menu->add_checkbox_to_panel(vp3_desenha, "Quadrado", &vp3_desenhaQuadrado);
	menu->add_column_to_panel(vp3_desenha, false);
	menu->add_checkbox_to_panel(vp3_desenha, "Bolinha", &vp3_desenhaBolinha);
	menu->add_column_to_panel(vp3_desenha, false);
	menu->add_checkbox_to_panel(vp3_desenha, "Rastro", &vp3_desenhaRastro);		
	
	
	/* Viewport 4 */
	menu->add_separator();
	painelViewportInferiorDireita = menu->add_panel("Viewport 4: Curvas");
	menuParametrosCurvas(menu, painelViewportInferiorDireita);
	
	
	menu->set_main_gfx_window(id_janela);
	GLUI_Master.set_glutIdleFunc(idleCallBack);
}

void desenhaCallBack(void)
{ 
	DBG(printf("Redesenhando a tela...\n"));
	glClear(GL_COLOR_BUFFER_BIT);
        
	selecionaViewport(VIEWPORT_SUPERIOR_ESQUERDA);
	defineCoordenadas(VIEWPORT_SUPERIOR_ESQUERDA);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenha3Meios(0.0, 0.0, 0, vp1_param_lado);
	desenhaBorda(VIEWPORT_SUPERIOR_ESQUERDA, CONFIG_TAM_BORDA);



	selecionaViewport(VIEWPORT_SUPERIOR_DIREITA);
	defineCoordenadas(VIEWPORT_SUPERIOR_DIREITA);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	RostoRobo();
	desenhaBorda(VIEWPORT_SUPERIOR_DIREITA, CONFIG_TAM_BORDA);



	selecionaViewport(VIEWPORT_INFERIOR_ESQUERDA);
	defineCoordenadas(VIEWPORT_INFERIOR_ESQUERDA);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	vp3_pframes++;
	if(vp3_pframes >= vp3_nframes)
	{
		movimentos(vp3_param_lado, vp3_param_ang, vp3_param_desl, 1, vp3_desenhaQuadrado, vp3_desenhaBolinha, vp3_desenhaRastro);
		vp3_pframes = 0;
	}
	else
	{
		movimentos(vp3_param_lado, vp3_param_ang, vp3_param_desl, 0, vp3_desenhaQuadrado, vp3_desenhaBolinha, vp3_desenhaRastro);
	}
        
	desenhaBorda(VIEWPORT_INFERIOR_ESQUERDA, CONFIG_TAM_BORDA);



	selecionaViewport(VIEWPORT_INFERIOR_DIREITA);
	defineCoordenadas(VIEWPORT_INFERIOR_DIREITA);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaCurvas();
	desenhaBorda(VIEWPORT_INFERIOR_DIREITA, CONFIG_TAM_BORDA);

	if(mostraHelp == 1)
	{
		selecionaViewport(VIEWPORT_HELP);
		defineCoordenadas(VIEWPORT_HELP);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		if(tamJanelaX == tamJanelaY)	desenhaHelp(vpLimites[VIEWPORT_HELP][1], vpLimites[VIEWPORT_HELP][3]);
		else if(tamJanelaX > tamJanelaY)desenhaHelp(vpLimites[VIEWPORT_HELP][1] * razaoX, vpLimites[VIEWPORT_HELP][3]);
		else				desenhaHelp(vpLimites[VIEWPORT_HELP][1], vpLimites[VIEWPORT_HELP][3] * razaoY);
	}

	glutSwapBuffers();

	
	DBG(printf("... terminou o redesenho.\n"));
}

void idleCallBack()
{
	if(redesenhaJanela == 1)
	{
		redesenhaJanela = 0;
		glutSetWindow(id_janela);
		glutPostRedisplay();
	}
}

void tecladoCallBack(unsigned char tecla, int x, int y)
{
	DBG(printf("Acao do teclado detectada: tecla = %d x = %d u = %d\n", tecla, x, y));
	
	if(tecla == 72 || tecla == 104) //h e H
	{
		if(mostraHelp == 0)     mostraHelp = 1;
		else			mostraHelp = 0;
	}
	
	if(mostraHelp == 1) return;
	
	if	(tecla == 82 || tecla == 114) resetaZoomViewport1(); //R ou r
	else if (tecla == 76 || tecla == 108) apagaPicadasRostoRobo(); //L ou l
	else if (tecla == 65 || tecla ==  97) apagaRastro(); //A ou a
	else if (tecla == 84 || tecla == 116) trocaCurva(); //T ou t
}

void mouseCallBack(int botao, int estado, int x, int y)
{
	DBG(printf("Acao do mouse detectada: botao = %d estado = %d x = %d u = %d\n", botao, estado, x, y));

	if(mostraHelp == 1) return;
	
	switch (botao)
	{
		case GLUT_LEFT_BUTTON:
			switch(viewportPelaPosMouse(x, y))
			{
				case VIEWPORT_SUPERIOR_ESQUERDA:
					if(estado == GLUT_DOWN) aplicaZoomViewport(VIEWPORT_SUPERIOR_ESQUERDA, x, y);
					break;
				case VIEWPORT_SUPERIOR_DIREITA:
					if(estado == GLUT_DOWN) mousequito(x, y, PICADA_ESQUERDA);
					break;
				case VIEWPORT_INFERIOR_ESQUERDA:
					break;
				case VIEWPORT_INFERIOR_DIREITA:
					if(estado == GLUT_DOWN) trocaCurva();
					break;
			}
			if(estado == GLUT_UP  ) terminouPicada();
			break;
		case GLUT_MIDDLE_BUTTON:
			switch(viewportPelaPosMouse(x, y))
			{
				case VIEWPORT_SUPERIOR_ESQUERDA:
					break;
				case VIEWPORT_SUPERIOR_DIREITA:
					break;
				case VIEWPORT_INFERIOR_ESQUERDA:
					break;
				case VIEWPORT_INFERIOR_DIREITA:
					break;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			switch(viewportPelaPosMouse(x, y))
			{
				case VIEWPORT_SUPERIOR_ESQUERDA:
					if(estado == GLUT_DOWN) aplicaUnZoomViewport(VIEWPORT_SUPERIOR_ESQUERDA);
					break;
				case VIEWPORT_SUPERIOR_DIREITA:
					if(estado == GLUT_DOWN) mousequito(x, y, PICADA_DIREITA);
					break;
				case VIEWPORT_INFERIOR_ESQUERDA:
					break;
				case VIEWPORT_INFERIOR_DIREITA:
					break;
			}
			if(estado == GLUT_UP  ) terminouPicada();
			break;
		default: break;
        }

}

void redimensionaCallBack(int w, int h)
{
	DBG(printf("Redimensionando a janela para: largura = %d altura = %d\n", w, h));

	tamJanelaX = w;
	tamJanelaY = h;

	razaoX = (GLdouble)w/h;
	razaoY = (GLdouble)h/w;
	
	redesenhaJanela = 1;
}

void rastreiaMouseCallBack(int x, int y)
{
	if(mostraHelp == 1) return;
  
  
	switch(viewportPelaPosMouse(x, y))
	{
		case VIEWPORT_SUPERIOR_ESQUERDA:
			mousequitoSaiuDoRosto();
			break;
		case VIEWPORT_SUPERIOR_DIREITA:
			mousequito(x, y, SEM_PICADA);		
			break;
		case VIEWPORT_INFERIOR_ESQUERDA:
			mousequitoSaiuDoRosto();
			break;
		case VIEWPORT_INFERIOR_DIREITA:
			mousequitoSaiuDoRosto();
			break;
	}

}

void timerFPS(int valor)
{
	DBG(printf("Temporizador disparado.\n"));

	redesenhaJanela = 1;
	glutTimerFunc(CONFIG_FPS_TIMER, timerFPS, 1);
}

void selecionaViewport(int viewport)
{
	GLsizei meioX = tamJanelaX/2;
	GLsizei meioY = tamJanelaY/2;

	DBG(printf("Preparando a viewport %d...\n", viewport));

	switch(viewport)
	{
		case VIEWPORT_SUPERIOR_ESQUERDA:
			glViewport(0, meioY, meioX, meioY);
			break;
		case VIEWPORT_SUPERIOR_DIREITA :
			glViewport(meioX, meioY, meioX, meioY);
			break;
		case VIEWPORT_INFERIOR_ESQUERDA:
			glViewport(0, 0, meioX, meioY);
			break;
		case VIEWPORT_INFERIOR_DIREITA :
			glViewport(meioX, 0, meioX, meioY);
			break;
		case VIEWPORT_HELP:
			glViewport(0, 0, tamJanelaX, tamJanelaY);
			break;			
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	DBG(printf("Viewport preparada com sucesso\n."));
}

void defineCoordenadas(int viewport)
{
	if(VIEWPORT_INFERIOR_DIREITA)
	{
		if(tamJanelaX == tamJanelaY)	glOrtho(vpLimites[viewport][0]		, vpLimites[viewport][1]         ,
							vpLimites[viewport][2]		, vpLimites[viewport][3]	 ,
							-100.0				, 100.0				);

		else if(tamJanelaX > tamJanelaY)glOrtho(vpLimites[viewport][0] * razaoX	, vpLimites[viewport][1] * razaoX,
							vpLimites[viewport][2]	  	, vpLimites[viewport][3]	 ,
							-100.0				, 100.0				);

		else				glOrtho(vpLimites[viewport][0]         	, vpLimites[viewport][1]         ,
							vpLimites[viewport][2] * razaoY	, vpLimites[viewport][3] * razaoY,
							-100.0				, 100.0				);
	}
	else
	{
	if(tamJanelaX == tamJanelaY)	gluOrtho2D(vpLimites[viewport][0]         , vpLimites[viewport][1]         ,
						   vpLimites[viewport][2]	  , vpLimites[viewport][3]);

	else if(tamJanelaX > tamJanelaY)gluOrtho2D(vpLimites[viewport][0] * razaoX, vpLimites[viewport][1] * razaoX,
						   vpLimites[viewport][2]	  , vpLimites[viewport][3]);

 	else				gluOrtho2D(vpLimites[viewport][0]         , vpLimites[viewport][1]         ,
						   vpLimites[viewport][2] * razaoY, vpLimites[viewport][3] * razaoY);
	}
}

void desenhaBorda(int viewport, GLfloat tam)
{
	GLdouble xi = vpLimites[viewport][0],
		 xf = vpLimites[viewport][1],
		 yi = vpLimites[viewport][2],
		 yf = vpLimites[viewport][3];

	if(tam <= 0.01) tam = 1.0;

	if(tamJanelaX > tamJanelaY)
	{
		xi *= razaoX;
		xf *= razaoX;
	}
	else
	{
		yi *= razaoY;
		yf *= razaoY;
	}

	glColor3f(vpCorBorda[viewport][0], vpCorBorda[viewport][1], vpCorBorda[viewport][2]);
	glLineWidth(tam);

	glBegin(GL_LINE_STRIP);
		glVertex2f(xi, yi);
		glVertex2f(xi, yf);
		glVertex2f(xf, yf);
		glVertex2f(xf, yi);
		glVertex2f(xi, yi);		
	glEnd();
}

int viewportPelaPosMouse(GLsizei x, GLsizei y)
{
	GLsizei meioX = tamJanelaX/2;
	GLsizei meioY = tamJanelaY/2;

	if(x < meioX && y < meioY) return VIEWPORT_SUPERIOR_ESQUERDA;
	else if(x < meioX) 	   return VIEWPORT_INFERIOR_ESQUERDA;
	else if(y < meioY)	   return VIEWPORT_SUPERIOR_DIREITA ;
	else			   return VIEWPORT_INFERIOR_DIREITA ;
}


void aplicaZoomViewport(int viewport, int x, int y)
{
	GLdouble diferencaX, diferencaY, scaleX, scaleY;
	GLdouble novoCentroX, novoCentroY;
	GLsizei meioX = tamJanelaX/2;
	GLsizei meioY = tamJanelaY/2;

	
	y = tamJanelaY - y;


	if(x > meioX) x -= meioX;
	if(y > meioY) y -= meioY;

	diferencaX = vpLimites[viewport][1] - vpLimites[viewport][0];
	diferencaY = vpLimites[viewport][3] - vpLimites[viewport][2];

	novoCentroX = vpLimites[viewport][0] + (((GLdouble) x / meioX) * diferencaX);
	novoCentroY = vpLimites[viewport][2] + (((GLdouble) y / meioY) * diferencaY);

	scaleX = diferencaX / 4.0;
	scaleY = diferencaY / 4.0; 

	DBG(printf("Zoom In na viewport %d:\nNovo Centro = (%lf %lf)\n sX = %lf sY = %lf\n", viewport, novoCentroX, novoCentroY, scaleX, scaleY));


	vpLimites[viewport][0] = novoCentroX - scaleX;
	vpLimites[viewport][1] = novoCentroX + scaleX;
	vpLimites[viewport][2] = novoCentroY - scaleY;
	vpLimites[viewport][3] = novoCentroY + scaleY;

	redesenhaJanela = 1;
}

void aplicaUnZoomViewport(int viewport)
{
	GLdouble diferencaX, diferencaY, scaleX, scaleY;
	GLdouble novoCentroX, novoCentroY;

	diferencaX = vpLimites[viewport][1] - vpLimites[viewport][0];
	diferencaY = vpLimites[viewport][3] - vpLimites[viewport][2];

	novoCentroX = vpLimites[viewport][0] + diferencaX/2.0;
	novoCentroY = vpLimites[viewport][2] + diferencaY/2.0;

	scaleX = diferencaX;
	scaleY = diferencaY; 

	DBG(printf("Zoom Out na viewport %d:\nNovo Centro = (%lf %lf)\n sX = %lf sY = %lf\n", viewport, novoCentroX, novoCentroY, scaleX, scaleY));


	vpLimites[viewport][0] = novoCentroX - scaleX;
	vpLimites[viewport][1] = novoCentroX + scaleX;
	vpLimites[viewport][2] = novoCentroY - scaleY;
	vpLimites[viewport][3] = novoCentroY + scaleY;

	redesenhaJanela = 1;
}

void resetaZoomViewport1(void)
{
	vpLimites[VIEWPORT_SUPERIOR_ESQUERDA][0] = -10.0;
	vpLimites[VIEWPORT_SUPERIOR_ESQUERDA][1] =  10.0;
	vpLimites[VIEWPORT_SUPERIOR_ESQUERDA][2] = -10.0;
	vpLimites[VIEWPORT_SUPERIOR_ESQUERDA][3] =  10.0;
}

void mousequito(int x, int y, int t)
{
	GLdouble diferencaX, diferencaY;
        GLsizei meioX = tamJanelaX/2;
        GLsizei meioY = tamJanelaY/2;
	GLdouble rX, rY;	
	GLdouble px, py;

	rX = (GLdouble) (x - meioX)/meioX;
	rY = (GLdouble) ((tamJanelaY - y) - meioY)/meioY;

	diferencaX = vpLimites[VIEWPORT_SUPERIOR_DIREITA][1] - vpLimites[VIEWPORT_SUPERIOR_DIREITA][0];
	diferencaY = vpLimites[VIEWPORT_SUPERIOR_DIREITA][3] - vpLimites[VIEWPORT_SUPERIOR_DIREITA][2];

	px = vpLimites[VIEWPORT_SUPERIOR_DIREITA][0] + (rX  * diferencaX);
	py = vpLimites[VIEWPORT_SUPERIOR_DIREITA][2] + (rY  * diferencaY);

	if	(tamJanelaX > tamJanelaY) px *= razaoX;
	else if (tamJanelaY > tamJanelaX) py *= razaoY;

	if(t == SEM_PICADA)
	{
		mousequitoNoRostoRobo(px, py);
		return;
	}

	if(px > vpLimites[VIEWPORT_SUPERIOR_DIREITA][1] || px < vpLimites[VIEWPORT_SUPERIOR_DIREITA][0] ||
	   py > vpLimites[VIEWPORT_SUPERIOR_DIREITA][3] || py < vpLimites[VIEWPORT_SUPERIOR_DIREITA][2]) return;

	adicionaPicada(px, py, t);
}
