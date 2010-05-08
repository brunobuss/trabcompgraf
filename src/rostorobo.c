#include "../headers/rostorobo.h"

GLdouble P = 10.0,
	 Q = 6.0, /* Parametros das elipses dos olhos */
	 R = 3.0, /* Raio do olho */
	 corElipse[3]  = {1.0, 1.0, 1.0},/* Cor das elipses dos olhos */
	 corOlhosN[3]  = {0.0, 0.0, 0.0},/* Cor dos olhos normais */
	 corOlhosP[3]  = {0.0, 1.0, 0.0},/* Cor dos olhos ao ser picado */
	 corFundoR[3]  = {1.0, 1.0, 0.0},/* Cor da "cara" do robo */
	 corBoca[3]    = {0.7, 0.7, 0.7},/* Cor da boca do robo */
	 corDentes[3]  = {0.0, 1.0, 1.0},/* Cor dos dentes do robo */
	 corPicadaE[3] = {1.0, 0.0, 0.0},/* Cor da picada com botão esquerdo */
	 corPicadaD[3] = {0.0, 0.0, 1.0};/* Cor da picada com botão direito  */

int 	BT = 5, /* Segundos entre uma animação de fechar/abrir a boca e outra */
	BF = 30 ; /* Frames para a duração de abrir/fechar a boca */

int	nDentes = 5; /* Número de dentes */

GLdouble picadas[N_PICADAS][3]; /* Vetor com o tipo e as coordenadas de até N_PICADAS picadas ;) */
int 	 qntpicadas = -1;	/* Quantidade de picadas no rosto do robo */

/* Estado da animação da boca:
   0 = fechada, parada;
   1 = abrindo;
   2 = aberta, parada;
   3 = fechando; */
int	stateBoca = BOCA_FECHADA;

/* Controle de qual frame está a animação de abrir/fechar */
int	qntFrames = 0;

int timerAtivado = 0;

void adicionaPicada(GLdouble x, GLdouble y)
{
	if(qntpicadas == N_PICADAS) return;

	qntpicadas++;
	picadas[qntpicadas][0] = x;
	picadas[qntpicadas][1] = y;
}

void RostoRobo()
{

	desenhaFundoRosto();

	desenhaElipse(-15.0, 10.0, corElipse);
	desenhaElipse( 15.0, 10.0, corElipse);

	desenhaCirculo(-15.0, 10.0, corOlhosN);
	desenhaCirculo( 15.0, 10.0, corOlhosN);
	
	desenhaFundoBoca();
	desenhaDentes();

	if(timerAtivado == 0)
	{
		timerAtivado = 1;
		glutTimerFunc(BT * 1000, mexeBocaTimer, 1);
	}
}

void desenhaFundoRosto()
{
	glColor3dv(corFundoR);

	glBegin(GL_POLYGON);
		glVertex2d(-30.0, -30.0);
		glVertex2d( 30.0, -30.0);
		glVertex2d( 30.0,  30.0);
		glVertex2d(-30.0 , 30.0);
		glVertex2d(-30.0 , 30.0);
	glEnd();
}

void desenhaFundoBoca()
{
	glColor3dv(corBoca);

	glBegin(GL_POLYGON);
		glVertex2d(-10.0, -30.0);
		glVertex2d( 10.0, -30.0);
		glVertex2d( 10.0, -10.0);
		glVertex2d(-10.0, -10.0);
		glVertex2d(-10.0, -30.0);
	glEnd();

	glColor3d(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
		glVertex2d(-10.0, -30.0);
		glVertex2d( 10.0, -30.0);
		glVertex2d( 10.0, -10.0);
		glVertex2d(-10.0, -10.0);
		glVertex2d(-10.0, -30.0);
	glEnd();
}

void desenhaDentes()
{
	int i;
	GLdouble largdentes = (GLdouble) 20.0 / nDentes;
	GLdouble altDentes = ((GLdouble) qntFrames/BF) * 10.0;

	switch(stateBoca)
	{
		case BOCA_ABRINDO:
			for(i = 0; i < nDentes; i++) /*Dentes de baixo */
			{
				glColor3dv(corDentes);

				glBegin(GL_POLYGON);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -20.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
				glEnd();

				glColor3d(0.0, 0.0, 0.0);

				glBegin(GL_LINE_STRIP);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -20.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
				glEnd();
			}
			for(i = 0; i < nDentes; i++) /*Dentes de cima */
			{
				glColor3dv(corDentes);

				glBegin(GL_POLYGON);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -20.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
				glEnd();

				glColor3d(0.0, 0.0, 0.0);

				glBegin(GL_LINE_STRIP);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -20.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
				glEnd();
			}
			qntFrames++;
			if(qntFrames == BF) {qntFrames = 0; stateBoca = BOCA_ABERTA;}
			break;
		case BOCA_FECHADA:
			for(i = 0; i < nDentes; i++) /*Dentes de baixo */
			{
				glColor3dv(corDentes);

				glBegin(GL_POLYGON);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
				glEnd();

				glColor3d(0.0, 0.0, 0.0);

				glBegin(GL_LINE_STRIP);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
				glEnd();
			}
			for(i = 0; i < nDentes; i++) /*Dentes de cima */
			{
				glColor3dv(corDentes);

				glBegin(GL_POLYGON);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
				glEnd();

				glColor3d(0.0, 0.0, 0.0);

				glBegin(GL_LINE_STRIP);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -20.0);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
				glEnd();
			}
			break;
		case BOCA_ABERTA:
			break;
		case BOCA_FECHANDO:
			for(i = 0; i < nDentes; i++) /*Dentes de baixo */
			{
				glColor3dv(corDentes);

				glBegin(GL_POLYGON);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -30.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
				glEnd();

				glColor3d(0.0, 0.0, 0.0);

				glBegin(GL_LINE_STRIP);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -30.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -30.0 + altDentes);
					glVertex2d(-10.0 + i     * largdentes, -30.0);
				glEnd();
			}

			for(i = 0; i < nDentes; i++) /*Dentes de cima */
			{
				glColor3dv(corDentes);

				glBegin(GL_POLYGON);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -10.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
				glEnd();

				glColor3d(0.0, 0.0, 0.0);

				glBegin(GL_LINE_STRIP);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0);
					glVertex2d(-10.0 + (i+1) * largdentes, -10.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -10.0 - altDentes);
					glVertex2d(-10.0 + i     * largdentes, -10.0);
				glEnd();
			}

			qntFrames++;
			if(qntFrames == BF) {qntFrames = 0; stateBoca = BOCA_FECHADA;}
			break;
	}
}

void desenhaCirculo(GLdouble x, GLdouble y, GLdouble *cor)
{
	int i;

	glColor3dv(cor);

	glBegin(GL_POLYGON);

		for(i = 0; i <= 360; i++)
		{
			glVertex2d(cos(((float) 3.14159/180) * i) * R + x,
				   sin(((float) 3.14159/180) * i) * R + y);
		}
	glEnd();

	glColor3d(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);

		for(i = 0; i <= 360; i++)
			glVertex2d(cos(((float) 3.14159/180) * i) * R + x,
				   sin(((float) 3.14159/180) * i) * R + y);
	glEnd();
}

void desenhaElipse(GLdouble x, GLdouble y, GLdouble *cor)
{
	int i;

	glColor3dv(cor);

	glBegin(GL_POLYGON);

		for(i = 0; i <= 360; i++)
			glVertex2d(cos(((float) 3.14159/180) * i) * P + x,
				   sin(((float) 3.14159/180) * i) * Q + y);
	glEnd();


	glColor3d(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);

		for(i = 0; i <= 360; i++)
			glVertex2d(cos(((float) 3.14159/180) * i) * P + x,
				   sin(((float) 3.14159/180) * i) * Q + y);
	glEnd();
}

void mexeBocaTimer(int valor)
{
	if(stateBoca == BOCA_FECHADA) stateBoca = BOCA_ABRINDO;
	else if(stateBoca == BOCA_ABERTA) stateBoca = BOCA_FECHANDO;

	timerAtivado = 0;
}
