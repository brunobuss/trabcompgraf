#include "../headers/tresmeios.h"

int nmax = 4;

void desenha3Meios(GLdouble x, GLdouble y, int n, GLdouble lado)
{
	GLdouble pax, pay,
                 pbx, pby,
		 pcx, pcy;


	GLfloat cores[5][3] = {
			{1.0, 0.0, 0.0},
			{1.0, 1.0, 0.0},
			{0.0, 1.0, 0.0},
			{0.0, 1.0, 1.0},
			{0.0, 0.0, 1.0}};

	if(n > nmax) return;

	glColor3fv(cores[n]);


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

void defineCorInterpolada(int n)
{



}
