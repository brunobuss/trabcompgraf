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

#include "../headers/rostorobo.h"



float	 P = 10.0,
	 Q = 6.0, /* Parametros das elipses dos olhos */
	 R = 3.0; /* Raio do olho */
GLdouble corElipse[3]  = {1.0, 1.0, 1.0},/* Cor das elipses dos olhos */
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

GLdouble coordElipses[2][2] = {{-15.0, 10.0}, {15.0, 10.0}};
GLdouble coordOlhos[2][2] = {{-15.0, 10.0}, {15.0, 10.0}};
GLdouble movOlhos[2][2] = {{ 0.0, 0.0}, {0.0, 0.0}};
int frameOlho = 0;
int qntFrameOlho = 20; /* Frames por animação do olho */
int mousequitoNoRosto = 0;
GLdouble posMousequitoX, posMousequitoY;

GLfloat  tamPicada = 3.0;	    /* Tam da picada */
GLdouble picadasCord[N_PICADAS][2]; /* Vetor com as coordenadas das N_PICADAS picadas ;) */
int	 picadasTipo[N_PICADAS]   ; /* Vetor com o tipo das N_PICADAS picadas ;) */
int 	 qntpicadas = -1;	/* Quantidade de picadas no rosto do robo */
int	 statePicada = 0;
int	 numPicadasParaRage = 20; /* Numeros de picada para o RostoRobo ficar enfurecido */
int	 roboRage = 0;
GLdouble corOlhosRAGE1[3] = {1.0, 0.0, 0.0},
	 corOlhosRAGE2[3] = {0.0, 1.0, 0.0},
	 corOlhosRAGE3[3] = {0.0, 0.0, 1.0};
GLdouble corDentesRAGE[3][3] = {{1.0, 1.0, 1.0},
				{0.0, 0.0, 0.0},
				{0.5, 0.5, 0.5}};

/* Estado da animação da boca:
   0 = fechada, parada;
   1 = abrindo;
   2 = aberta, parada;
   3 = fechando; */
int	stateBoca = BOCA_FECHADA;
/* Controle de qual frame está a animação de abrir/fechar */
int	qntFramesBoca = 0;

int timerAtivado = 0;

void adicionaPicada(GLdouble x, GLdouble y, int t)
{
	if(qntpicadas == N_PICADAS) return;

	if(stateBoca == BOCA_FECHADA) stateBoca = BOCA_ABRINDO;

	DBG(printf("Adicionando picada = (%lf, %lf)\n", x, y));

	qntpicadas++;
	picadasCord[qntpicadas][PICADA_COORDENADA_X] = x;
	picadasCord[qntpicadas][PICADA_COORDENADA_Y] = y;
	picadasTipo[qntpicadas]			     = t;
	statePicada = 1;
	if((qntpicadas + 1) % numPicadasParaRage == 0)
	{
		roboRage = 1;
	}

}

void terminouPicada()
{
	statePicada = 0;
}

void RostoRobo()
{

	desenhaFundoRosto();
	desenhaPicadas();

	desenhaElipse(coordElipses[0][0], coordElipses[0][1], corElipse);
	desenhaElipse(coordElipses[1][0], coordElipses[1][1], corElipse);

	movimentaOlhos();

	if(statePicada == 1)
	{
		if(roboRage == 0)
		{
			desenhaCirculo(coordOlhos[0][0], coordOlhos[0][1], corOlhosP);
			desenhaCirculo(coordOlhos[1][0], coordOlhos[1][1], corOlhosP);
		}
		else if(roboRage <= 3)
		{
			desenhaCirculo(coordOlhos[0][0], coordOlhos[0][1], corOlhosRAGE1);
			desenhaCirculo(coordOlhos[1][0], coordOlhos[1][1], corOlhosRAGE2);
			roboRage++;

			if(stateBoca == BOCA_FECHADA ||
			   stateBoca == BOCA_ABERTA)
			{
				BF = 15;
				BT = 1;
			}
		}
		else if(roboRage <= 6)
		{
			desenhaCirculo(coordOlhos[0][0], coordOlhos[0][1], corOlhosRAGE2);
			desenhaCirculo(coordOlhos[1][0], coordOlhos[1][1], corOlhosRAGE3);
			roboRage++;

			if(stateBoca == BOCA_FECHADA ||
			   stateBoca == BOCA_ABERTA)
			{
				BF = 15;
				BT = 1;
			}
		}
		else if(roboRage <= 9)
		{
			desenhaCirculo(coordOlhos[0][0], coordOlhos[0][1], corOlhosRAGE3);
			desenhaCirculo(coordOlhos[1][0], coordOlhos[1][1], corOlhosRAGE1);
			roboRage++;

			if(stateBoca == BOCA_FECHADA ||
			   stateBoca == BOCA_ABERTA)
			{
				BF = 15;
				BT = 1;
			}
			if(roboRage == 10) roboRage = 1;
		}

		
	}
	else
	{
		desenhaCirculo(coordOlhos[0][0], coordOlhos[0][1], corOlhosN);
		desenhaCirculo(coordOlhos[1][0], coordOlhos[1][1], corOlhosN);
		roboRage = 0;
		
		if(stateBoca == BOCA_FECHADA || stateBoca == BOCA_ABERTA)
		{
			BF = 30;
			BT = 5;
		}
	}
	
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
	GLdouble altDentes = ((GLdouble) qntFramesBoca/BF) * 10.0;

	switch(stateBoca)
	{
		case BOCA_ABRINDO:
			for(i = 0; i < nDentes; i++) /*Dentes de baixo */
			{
				if(roboRage >= 1)
				{
					glColor3dv(corDentesRAGE[(i + roboRage)%3]);
				}
				else glColor3dv(corDentes);

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
				if(roboRage >= 1)
				{
					glColor3dv(corDentesRAGE[(i + roboRage)%3]);
				}
				else glColor3dv(corDentes);

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
			qntFramesBoca++;
			if(qntFramesBoca == BF) {qntFramesBoca = 0; stateBoca = BOCA_ABERTA;}
			break;
		case BOCA_FECHADA:
			for(i = 0; i < nDentes; i++) /*Dentes de baixo */
			{
				if(roboRage >= 1)
				{
					glColor3dv(corDentesRAGE[(i + roboRage)%3]);
				}
				else glColor3dv(corDentes);

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
				if(roboRage >= 1)
				{
					glColor3dv(corDentesRAGE[(i + roboRage)%3]);
				}
				else glColor3dv(corDentes);


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
				if(roboRage >= 1)
				{
					glColor3dv(corDentesRAGE[(i + roboRage)%3]);
				}
				else glColor3dv(corDentes);

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
				if(roboRage >= 1)
				{
					glColor3dv(corDentesRAGE[(i + roboRage)%3]);
				}
				else glColor3dv(corDentes);

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

			qntFramesBoca++;
			if(qntFramesBoca == BF) {qntFramesBoca = 0; stateBoca = BOCA_FECHADA;}
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

void desenhaPicadas()
{
	int i;
	GLfloat original = 1.0;

	glGetFloatv(GL_POINT_SIZE, &original);

	glPointSize(tamPicada);

	glBegin(GL_POINTS);		

	for(i = 0; i <= qntpicadas; i++)
	{
		if     (picadasTipo[i] == PICADA_ESQUERDA) glColor3dv(corPicadaE);
		else if(picadasTipo[i] == PICADA_DIREITA ) glColor3dv(corPicadaD);
		
		glVertex2d(picadasCord[i][PICADA_COORDENADA_X],
			   picadasCord[i][PICADA_COORDENADA_Y]);
	}

	glEnd();

	glPointSize(original);
}

void mexeBocaTimer(int valor)
{
	if(stateBoca == BOCA_FECHADA) stateBoca = BOCA_ABRINDO;
	else if(stateBoca == BOCA_ABERTA) stateBoca = BOCA_FECHANDO;

	timerAtivado = 0;
}

void movimentaOlhos()
{
	int tentativas = 10, i;
	int angE, angD;
	double rad;
	GLdouble dx, dy, dist;

	if(frameOlho == 0)
	{

		movOlhos[0][0] = movOlhos[0][1] = movOlhos[1][0] = movOlhos[1][1] = 0.0;

		if(mousequitoNoRosto == 0)
		{

			for(i = 0; i < tentativas; i++)
			{
				angE = rand()%360;
				rad = ((double)angE * 3.14159)/180.0;

				dx = cos(rad) * 0.1 * R;
				dy = sin(rad) * 0.1 * R;

				if(verificaColisao(coordElipses[0][0]   , coordElipses[0][1],
						   coordOlhos[0][0] + dx, coordOlhos[0][1] + dy))
				{
					movOlhos[0][0] = dx;
					movOlhos[0][1] = dy;
					break;
				}
			}


			for(i = 0; i < tentativas; i++)
			{
				angD = rand()%360;
				rad = ((double)angD * 3.14159)/180.0;

				dx = cos(rad) * 0.1 * R;
				dy = sin(rad) * 0.1 * R;

				if(verificaColisao(coordElipses[1][0]   , coordElipses[1][1],
						   coordOlhos[1][0] + dx, coordOlhos[1][1] + dy))
				{
					movOlhos[1][0] = dx;
					movOlhos[1][1] = dy;
					break;
				}
			}
		}
		else if(mousequitoNoRosto == 1)
		{
			dx = posMousequitoX - coordOlhos[0][0];
			dy = posMousequitoY - coordOlhos[0][1];

			dist = sqrt(dx * dx + dy * dy);

			movOlhos[0][0] = (dx / dist) * 0.1 * R;
			movOlhos[0][1] = (dy / dist) * 0.1 * R;



			dx = posMousequitoX - coordOlhos[1][0];
			dy = posMousequitoY - coordOlhos[1][1];

			dist = sqrt(dx * dx + dy * dy);

			movOlhos[1][0] = (dx / dist) * 0.1 * R;
			movOlhos[1][1] = (dy / dist) * 0.1 * R;
		}
	}

	if(verificaColisao(coordElipses[0][0],
			   coordElipses[0][1],
			   coordOlhos[0][0] + movOlhos[0][0],
                           coordOlhos[0][1] + movOlhos[0][1]))
	{
		coordOlhos[0][0] += movOlhos[0][0];
		coordOlhos[0][1] += movOlhos[0][1];
	}
	else if(verificaColisao(coordElipses[0][0],
			   coordElipses[0][1],
			   coordOlhos[0][0] + movOlhos[0][0],
                           coordOlhos[0][1]))
	{
		coordOlhos[0][0] += movOlhos[0][0];
	}
	else if(verificaColisao(coordElipses[0][0],
			   coordElipses[0][1],
			   coordOlhos[0][0],
                           coordOlhos[0][1] + movOlhos[0][1]))
	{
		coordOlhos[0][1] += movOlhos[0][1];
	}


	if(verificaColisao(coordElipses[1][0],
			   coordElipses[1][1],
			   coordOlhos[1][0] + movOlhos[1][0],
                           coordOlhos[1][1] + movOlhos[1][1]))
	{
		coordOlhos[1][0] += movOlhos[1][0];
		coordOlhos[1][1] += movOlhos[1][1];
	}
	else if(verificaColisao(coordElipses[1][0],
			   coordElipses[1][1],
			   coordOlhos[1][0] + movOlhos[1][0],
                           coordOlhos[1][1]))
	{
		coordOlhos[1][0] += movOlhos[1][0];
	}
	else if(verificaColisao(coordElipses[1][0],
			   coordElipses[1][1],
			   coordOlhos[1][0],
                           coordOlhos[1][1] + movOlhos[1][1]))
	{
		coordOlhos[1][1] += movOlhos[1][1];
	}

	frameOlho++;
	if(frameOlho == qntFrameOlho) frameOlho = 0;
}

int verificaColisao(GLdouble p1x, GLdouble p1y, GLdouble p2x, GLdouble p2y)
{
	GLdouble vx, vy, pdx, pdy;
	int i;

	for(i = 0; i < 360; i++)
	{
		vx = cos(((float) 3.14159/180) * i) * P + p1x,
		vy = sin(((float) 3.14159/180) * i) * Q + p1y;
		
		pdx = vx - p2x;
		pdy = vy - p2y;
		
		if(sqrt(pdx * pdx + pdy * pdy) <= R + 0.2) return 0;
	}

	return 1;
}



void mousequitoNoRostoRobo(GLdouble x, GLdouble y)
{
	DBG(printf("Mousequito no rosto em (%lf, %lf)\n", x, y));
	posMousequitoX = x;
	posMousequitoY = y;
	mousequitoNoRosto = 1;
}

void mousequitoSaiuDoRosto(void)
{
	mousequitoNoRosto = 0;
}

void apagaPicadasRostoRobo(void)
{
	qntpicadas = -1;
	statePicada = 0;
	roboRage = 0;
}

void menuParametrosRostoRobo(GLUI *menu, GLUI_Panel *painel)
{
	GLUI_Panel *p_Olhos;
	GLUI_Spinner *vp3_olhos_P;
	GLUI_Spinner *vp3_olhos_Q;
	GLUI_Spinner *vp3_olhos_R;
	GLUI_Spinner *vp3_dentes_qnt;
	GLUI_Spinner *vp3_tam_picada;
  
	p_Olhos = menu->add_panel_to_panel(painel, "Olhos:");
	vp3_olhos_P = menu->add_spinner_to_panel(p_Olhos, "P:" , GLUI_SPINNER_FLOAT, &P);
	vp3_olhos_P->set_float_limits(10.0, 15.0, GLUI_LIMIT_CLAMP);
	
	vp3_olhos_Q = menu->add_spinner_to_panel(p_Olhos, "Q:" , GLUI_SPINNER_FLOAT, &Q);
	vp3_olhos_Q->set_float_limits(6.0, 14.0, GLUI_LIMIT_CLAMP);
	
	vp3_olhos_R = menu->add_spinner_to_panel(p_Olhos, "R:" , GLUI_SPINNER_FLOAT, &R);
	vp3_olhos_R->set_float_limits(0.0,  6.0, GLUI_LIMIT_CLAMP);
	
	
	vp3_dentes_qnt = menu->add_spinner_to_panel(painel, "Numero de Dentes:" , GLUI_SPINNER_INT, &nDentes);
	vp3_dentes_qnt->set_int_limits(1, 30, GLUI_LIMIT_CLAMP);

	vp3_tam_picada = menu->add_spinner_to_panel(painel, "Tamanho da picada:" , GLUI_SPINNER_FLOAT, &tamPicada);
	vp3_tam_picada->set_float_limits(1.0,  10.0, GLUI_LIMIT_CLAMP);
}
