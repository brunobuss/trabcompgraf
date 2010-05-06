#include "../headers/main.h"

/* Variáveis */
GLsizei tamJanelaX = CONFIG_TAMHOR_INICIAL;
GLsizei tamJanelaY = CONFIG_TAMVER_INICIAL;

GLdouble razaoX;
GLdouble razaoY;

int redesenhaJanela = 1;


int main(int argc, char *argv[])
{
	setupGlut(&argc, argv);
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
	glutCreateWindow(CONFIG_TITULO_JANELA);

	glClearColor(0.0, 0.0, 0.0, 0.0); /* Define a cor do GL_COLOR_BUFFER_BIT */
	glShadeModel(GL_FLAT);

	glutDisplayFunc(desenhaCallBack);
	glutReshapeFunc(redimensionaCallBack);
	glutKeyboardFunc(tecladoCallBack);
	glutMouseFunc(mouseCallBack);
	glutIdleFunc(idleCallBack);
	glutTimerFunc(CONFIG_FPS_TIMER, timerFPS, 1);

	DBG(printf("...GLUT configurado com sucesso\n"));
}

void desenhaCallBack(void)
{
	if(redesenhaJanela == 0) return;

	DBG(printf("Redesenhando a tela...\n"));
	redesenhaJanela = 0;

	glClear(GL_COLOR_BUFFER_BIT);

	selecionaViewport(1);
	/* Rotina de desenho do quadrante superior esquerdo */
	defineCoordenadas(-10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenha3Meios(0.0, 0.0, 0, 16.0);
	desenhaBorda(-10.0, 10.0, 1.0, 1.0, 1.0, 1.0);

	selecionaViewport(2);
	/* Rotina de desenho do quadrante superior direito */
	defineCoordenadas(-10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaBorda(-10.0, 10.0, 1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glRectd(-8.0, -8.0, 8.0, 8.0);

	selecionaViewport(3);
	/* Rotina de desenho do quadrande inferior esquerdo */
	defineCoordenadas(-10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaBorda(-10.0, 10.0, 1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glRectd(-8.0, -8.0, 8.0, 8.0);


	selecionaViewport(4);
	/* Rotina de desenho do quadrante inferior direito */
	defineCoordenadas(-10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaBorda(-10.0, 10.0, 1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectd(-8.0, -8.0, 8.0, 8.0);




	glutSwapBuffers();

	DBG(printf("... terminou o redesenho.\n"));
}

void idleCallBack()
{
}

void tecladoCallBack(unsigned char tecla, int x, int y)
{
	DBG(printf("Acao do teclado detectada: tecla = %d x = %d u = %d\n", tecla, x, y));
}

void mouseCallBack(int botao, int estado, int x, int y)
{
	DBG(printf("Acao do mouse detectada: botao = %d estado = %d x = %d u = %d\n", botao, estado, x, y));

	switch (botao)
	{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
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

	glutPostRedisplay();
}

void timerFPS(int valor)
{
	DBG(printf("Temporizador disparado.\n"));

	redesenhaJanela = 1;
	glutPostRedisplay();
	glutTimerFunc(CONFIG_FPS_TIMER, timerFPS, 1);
}

void selecionaViewport(int i)
{
	GLsizei meioX = tamJanelaX/2;
	GLsizei meioY = tamJanelaY/2;

	DBG(printf("Preparando a viewport %d...\n", i));

	switch(i)
	{
		case 1: /* superior esquerdo */
			glViewport(0, meioY, meioX, meioY);
			break;
		case 2: /* superior direito  */
			glViewport(meioX, meioY, meioX, meioY);
			break;
		case 3: /* inferior esquerdo */
			glViewport(0, 0, meioX, meioY);
			break;
		case 4: /* inferior direito  */
			glViewport(meioX, 0, meioX, meioY);
			break;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	DBG(printf("Viewport preparada com sucesso\n."));
}

void defineCoordenadas(GLdouble inicial, GLdouble final)
{
	if(tamJanelaX == tamJanelaY) 	 gluOrtho2D(inicial, final, inicial, final);
	else if(tamJanelaX > tamJanelaY) gluOrtho2D(inicial * razaoX, final * razaoX, inicial, final);
	else				 gluOrtho2D(inicial, final, inicial * razaoY, final * razaoY);

}

void desenhaBorda(GLdouble inicial, GLdouble final, GLfloat red, GLfloat green, GLfloat blue, GLfloat tam)
{
	GLdouble xi = inicial,
		 xf = final  ,
                 yi = inicial,
                 yf = final  ;

	if(tam <= 0.01) tam = 1.0;

	if(tamJanelaX > tamJanelaY)
	{
		xi = inicial * razaoX;
		xf = final   * razaoX;
	}
	else
	{
		yi = inicial * razaoY;
		yf = final   * razaoY;
	}


	glColor3f(red, green, blue);
	glLineWidth(tam);

	glBegin(GL_LINE_STRIP);
		glVertex2f(xi, yi);
		glVertex2f(xi, yf);
		glVertex2f(xf, yf);
		glVertex2f(xf, yi);
		glVertex2f(xi, yi);		
	glEnd();

}
