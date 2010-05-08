#include "../headers/movimentos.h"

GLdouble    angMovimento = 0.0;

GLdouble    pax, pay,
            pbx, pby,
            pcx, pcy,
            pdx, pdy;

void movimentos(GLdouble l, GLfloat a, GLfloat d, GLfloat t)
{
    pax = l * (1.0 / 2.0);
    pay = l * (1.0 / 2.0);

    pbx = -1.0 * l * (1.0 / 2.0);
    pby = l * (1.0 / 2.0);

    pcx = -1.0 * l * (1.0 / 2.0);
    pcy = -1.0 * l * (1.0 / 2.0);

    pdx = l * (1.0 / 2.0);
    pdy = -1.0 * l * (1.0 / 2.0);

    angMovimento += a / 10;

    glLineWidth(2.0);
    DBG(printf("l: %lf pax: %lf pay: %lf angMovimento: %lf\n", l,pax,pay, angMovimento));
    glPushMatrix();
    glRotatef(angMovimento,0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
       glVertex2d(pax,pay);
       glVertex2d(pbx,pby);
       glVertex2d(pcx,pcy);
       glVertex2d(pdx,pdy);
    glEnd();
    glPopMatrix();
}
