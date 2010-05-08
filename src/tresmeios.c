#include "../headers/tresmeios.h"

int nmax = 10;

int itDesenhar = 10;


void desenha3Meios(GLdouble x, GLdouble y, int n, GLdouble lado)
{
	GLdouble pax, pay,
                 pbx, pby,
		 pcx, pcy;
	GLdouble cor[3];


	if(n > nmax) return;

	/*if(n == itDesenhar)*/ defineCorInterpolada(n, cor);
	/*else cor[0] = cor[1] = cor[2] = 0.0; */

	glColor3dv(cor);


	pax = x;
	pay = y + lado * ( sqrt(3.0/4.0) - 1 / (2 * sqrt(3.0)));

	pbx = x + lado / 2.0;
	pby = y - lado / (2 * sqrt(3.0));
	

	pcx = x - lado / 2.0;
	pcy = y - lado / (2 * sqrt(3.0));


	glBegin(GL_TRIANGLES);
		glVertex2d(pax, pay);
		glVertex2d(pbx, pby);
		glVertex2d(pcx, pcy);
	glEnd();


	lado = lado / 2.0;

	desenha3Meios(x, y - lado * ( sqrt(3.0/4.0) - 1 / (2 * sqrt(3.0))), n + 1, lado);


	desenha3Meios(x - lado / 2.0 , y + lado / (2 * sqrt(3.0)), n + 1, lado);
	desenha3Meios(x + lado / 2.0 , y + lado / (2 * sqrt(3.0)), n + 1, lado);
}

void defineCorInterpolada(int n, GLdouble *p)
{
	GLdouble origem, destino;

	destino = (GLdouble)n /(GLdouble) nmax;
	origem = 1.0 - destino;

	p[0] = origem;
	p[1] = 0.0;
	p[2] = destino;
}
