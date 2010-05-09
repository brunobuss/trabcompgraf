#include "../headers/butterfly.h"

int N = 10000;

int selecionaCor = COR_RED_BLUE;

int qntFramesBF  = 70;
int frameBF	 = 0;

void desenhaButterfly()
{
	int i;
	GLdouble u;
	GLdouble px, py, lx, ly;
	GLdouble corButterfly[3];



	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);

	defineCorButterfly(corButterfly);
	glColor3dv(corButterfly);

	glBegin(GL_LINE_STRIP);

		for(i = 0; i < N; i++)
		{



			u  = FU(u);
			px = PX(u);
			py = PY(u);

			glVertex2d(px, py);
		}
	glEnd();

	glPopMatrix();	
}

void defineCorButterfly(GLdouble *p)
{
	switch(selecionaCor)
	{
		case COR_RED_BLUE:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_BLUE_GREEN;}
			break;
		case COR_RED_GREEN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_GREEN_CYAN;}
			break;
		case COR_RED_CYAN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_CYAN_GREEN;}
			break;
		case COR_RED_MAGENTA:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_MAGENTA_BLUE;}
			break;

		case COR_GREEN_BLUE:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_BLUE_RED;}
			break;
		case COR_GREEN_RED:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_RED_MAGENTA;}
			break;
		case COR_GREEN_CYAN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_CYAN_RED;}
			break;
		case COR_GREEN_MAGENTA:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_MAGENTA_CYAN;}
			break;

		case COR_BLUE_RED:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_RED_GREEN;}
			break;
		case COR_BLUE_GREEN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_GREEN_MAGENTA;}
			break;
		case COR_BLUE_CYAN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_CYAN_MAGENTA;}
			break;
		case COR_BLUE_MAGENTA:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_MAGENTA_RED;}
			break;

		case COR_CYAN_RED:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_RED_BLUE;}
			break;
		case COR_CYAN_GREEN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_GREEN_RED;}
			break;
		case COR_CYAN_BLUE:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_BLUE_MAGENTA;}
			break;
		case COR_CYAN_MAGENTA:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_MAGENTA_GREEN;}
			break;

		case COR_MAGENTA_RED:
			p[0] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_RED_CYAN;}
			break;
		case COR_MAGENTA_GREEN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_GREEN_BLUE;}
			break;
		case COR_MAGENTA_BLUE:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (  0.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_BLUE_CYAN;}
			break;
		case COR_MAGENTA_CYAN:
			p[0] = (GLdouble)frameBF * ((GLdouble) (  0.0 - 255.0) / qntFramesBF) + 255.0;
			p[1] = (GLdouble)frameBF * ((GLdouble) (255.0 -   0.0) / qntFramesBF) +   0.0;
			p[2] = (GLdouble)frameBF * ((GLdouble) (255.0 - 255.0) / qntFramesBF) + 255.0;
			frameBF++;
			if(frameBF == qntFramesBF) {frameBF = 0; selecionaCor = COR_CYAN_BLUE;}
			break;

	}

	p[0] /= 255.0;
	p[1] /= 255.0;
	p[2] /= 255.0;
}
