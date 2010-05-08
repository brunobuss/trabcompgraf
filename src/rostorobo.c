#include "../headers/rostorobo.h"

GLdouble P,
	 Q, /* Parametros das elipses dos olhos */
	 R, /* Raio do olho */
	 corElipse[3]  = {1.0, 1.0, 1.0},/* Cor das elipses dos olhos */
	 corOlhosN[3]  = {0.0, 0.0, 0.0},/* Cor dos olhos normais */
	 corOlhosP[3]  = {0.0, 1.0, 0.0},/* Cor dos olhos ao ser picado */
	 corFundoR[3]  = {1.0, 1.0, 0.0},/* Cor da "cara" do robo */
	 corBoca[3]    = {0.7, 0.7, 0.7},/* Cor da boca do robo */
	 corDentes[3]  = {0.0, 1.0, 1.0},/* Cor dos dentes do robo */
	 corPicadaE[3] = {1.0, 0.0, 0.0},/* Cor da picada com botão esquerdo */
	 corPicadaD[3] = {0.0, 0.0, 1.0};/* Cor da picada com botão direito  */

int 	BT = 5.0, /* Segundos entre uma animação de fechar/abrir a boca e outra */
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

	desenhaElipse(20.0, 40.0, corElipse);
	desenhaElipse(20.0, 40.0, corElipse);

	desenhaCirculo(20.0, 40.0, corOlhosN);
	desenhaCirculo(20.0, 40.0, corOlhosN);
	


	desenhaFundoBoca();
	desenhaDentes();
}

void desenhaFundoRosto()
{
	glColor3dv(corFundoR);

	glBegin(GL_POLYGON);
		glVertex2d(0.0 , 0.0 );
		glVertex2d(60.0, 0.0 );
		glVertex2d(60.0, 60.0);
		glVertex2d(0.0 , 60.0);
		glVertex2d(0.0 , 0.0 );
	glEnd();
}

void desenhaFundoBoca()
{
	glColor3dv(corBoca);

	glBegin(GL_POLYGON);
		glVertex2d(20.0, 0.0 );
		glVertex2d(40.0, 0.0 );
		glVertex2d(40.0, 20.0);
		glVertex2d(20.0, 20.0);
		glVertex2d(20.0, 0.0 );
	glEnd();
}

void desenhaDentes()
{


}

void desenhaCirculo(GLdouble x, GLdouble y, GLdouble *cor)
{
	int i;

	glColor3dv(cor);

	glBegin(GL_LINE_LOOP);

		for(i = 0; i < 360; i++)
			glVertex2d(cos(((float) 3.14159/180) * i) * R + x,
				   sin(((float) 3.14159/180) * i) * R + y);
	glEnd();
}

void desenhaElipse(GLdouble x, GLdouble y, GLdouble *cor)
{
	int i;

	glColor3dv(cor);

	glBegin(GL_LINE_LOOP);

		for(i = 0; i < 360; i++)
			glVertex2d(cos(((float) 3.14159/180) * i) * P + x,
				   sin(((float) 3.14159/180) * i) * Q + y);
	glEnd();
}
