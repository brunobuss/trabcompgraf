#include "../headers/curvas.h"

int N_Butterfly = 2000;
int N_Chrysanthemum = 2000;

int selecionaCor = COR_RED_BLUE;

int qntFrames  = 70;
int frame	 = 0;

int curva = CURVA_CHRYSANTHEMUM;

int troca = 0;
int corRetorno;
GLdouble lc[3];


void desenhaCurvas()
{
	int i;
	GLdouble u;
	GLdouble px, py;
	GLdouble corCurva[3];

	glPushMatrix();

	if(curva == CURVA_BUTTERFLY)
	{
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glScalef(10.0, 10.0, 1.0);
	}
	else if(curva == CURVA_CHRYSANTHEMUM)
	{
		glScalef(3.5, 3.5, 1.0);
		glTranslatef(0.0, 2.5, 0.0);
	}

	defineCor(corCurva);
	glColor3dv(corCurva);
	
	glBegin(GL_LINE_STRIP);

	if(curva == CURVA_BUTTERFLY)
	{
		for(i = 0; i < N_Butterfly; i++)
		{
			u  = BF_U;
			px = BF_PX;
			py = BF_PY;

			glVertex2d(px, py);
		}
	}
	else if(curva == CURVA_CHRYSANTHEMUM)
	{
		for(i = 0; i <= N_Chrysanthemum; i++)
		{
			u  = CH_U;
			px = CH_PX;
			py = CH_PY;

			glVertex2d(px, py);
		}
	}	
	glEnd();

	glPopMatrix();	
}

void defineCor(GLdouble *p)
{
	switch(selecionaCor)
	{
		case COR_RED_BLUE:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_BLUE_GREEN;}
			break;
		case COR_RED_GREEN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_GREEN_CYAN;}
			break;
		case COR_RED_CYAN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_CYAN_GREEN;}
			break;
		case COR_RED_MAGENTA:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_MAGENTA_BLUE;}
			break;

		case COR_GREEN_BLUE:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_BLUE_RED;}
			break;
		case COR_GREEN_RED:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_RED_MAGENTA;}
			break;
		case COR_GREEN_CYAN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_CYAN_RED;}
			break;
		case COR_GREEN_MAGENTA:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_MAGENTA_CYAN;}
			break;

		case COR_BLUE_RED:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_RED_GREEN;}
			break;
		case COR_BLUE_GREEN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_GREEN_MAGENTA;}
			break;
		case COR_BLUE_CYAN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_CYAN_MAGENTA;}
			break;
		case COR_BLUE_MAGENTA:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_MAGENTA_RED;}
			break;

		case COR_CYAN_RED:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_RED_BLUE;}
			break;
		case COR_CYAN_GREEN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_GREEN_RED;}
			break;
		case COR_CYAN_BLUE:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_BLUE_MAGENTA;}
			break;
		case COR_CYAN_MAGENTA:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_MAGENTA_GREEN;}
			break;

		case COR_MAGENTA_RED:
			p[0] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_RED_CYAN;}
			break;
		case COR_MAGENTA_GREEN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_GREEN_BLUE;}
			break;
		case COR_MAGENTA_BLUE:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_BLUE_CYAN;}
			break;
		case COR_MAGENTA_CYAN:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - 255.0) / qntFrames) + 255.0;
			p[1] = (GLdouble)frame * ((GLdouble) (255.0 -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (255.0 - 255.0) / qntFrames) + 255.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = COR_CYAN_BLUE;}
			break;

		case COR_FADE_TO_COLOR:
			p[0] = (GLdouble)frame * ((GLdouble) (lc[0] -   0.0) / qntFrames) +   0.0;
			p[1] = (GLdouble)frame * ((GLdouble) (lc[1] -   0.0) / qntFrames) +   0.0;
			p[2] = (GLdouble)frame * ((GLdouble) (lc[2] -   0.0) / qntFrames) +   0.0;
			frame++;
			if(frame == qntFrames) {frame = 0; selecionaCor = corRetorno;}
			break;
		case COR_FADE_TO_BLACK:
			p[0] = (GLdouble)frame * ((GLdouble) (  0.0 - lc[0]) / qntFrames) + lc[0];
			p[1] = (GLdouble)frame * ((GLdouble) (  0.0 - lc[1]) / qntFrames) + lc[1];
			p[2] = (GLdouble)frame * ((GLdouble) (  0.0 - lc[2]) / qntFrames) + lc[2];
			frame++;
			if(frame == qntFrames)
			{
				frame = 0;
				selecionaCor = COR_FADE_TO_COLOR;
				if(curva == CURVA_BUTTERFLY) curva = CURVA_CHRYSANTHEMUM;
				else if(curva == CURVA_CHRYSANTHEMUM) curva = CURVA_BUTTERFLY;
			}
			break;
	

	}

	if(frame == 0 && troca == 1)
	{
		troca = 0;
		corRetorno = selecionaCor;
		selecionaCor = COR_FADE_TO_BLACK;
		lc[0] = p[0];
		lc[1] = p[1];
		lc[2] = p[2];
	}

	p[0] /= 255.0;
	p[1] /= 255.0;
	p[2] /= 255.0;
}

void trocaCurva()
{
	if(selecionaCor != COR_FADE_TO_BLACK && selecionaCor != COR_FADE_TO_COLOR) troca = 1;
}
