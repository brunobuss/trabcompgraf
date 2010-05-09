#include "../headers/butterfly.h"

int N = 9000;

void desenhaButterfly()
{
	int i;
	GLdouble u;
	GLdouble px, py, lx, ly;
	GLdouble corButterfly[3];



	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);

	glBegin(GL_LINE_STRIP);

		for(i = 0; i < N; i++)
		{

			defineCorButterfly(i, corButterfly);
			glColor3dv(corButterfly);


			u  = FU(u);
			px = PX(u);
			py = PY(u);

			glVertex2d(px, py);
		}
	glEnd();

	glPopMatrix();	
}

void defineCorButterfly(int n, GLdouble *p)
{
        GLdouble origem, destino;

        destino = (GLdouble)n /((GLdouble) N/3.0);
        origem = 1.0 - destino;

	if(n < N/3)
	{
	        p[0] = 0.0;
        	p[1] = origem;
	        p[2] = destino;
	}
	else if(n >= N/3)
	{

	        p[0] = destino;
        	p[1] = 0.0;
	        p[2] = origem;
	}
	else
	{

	        p[0] = origem;
        	p[1] = destino;
	        p[2] = 0.0;
	}
}

