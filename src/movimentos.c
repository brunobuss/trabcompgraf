#include "../headers/movimentos.h"
#include "../headers/debug.h"

GLdouble    angMovimento = 0.0;

GLdouble    pax, pay,
            pbx, pby,
            pcx, pcy,
            pdx, pdy;

//Pontos da "Bola"
GLdouble    by,bx;

int         arestaBolinha = 4;

GLdouble    corQuad[3]  = {1.0, 1.0, 0.0},
            corBola[3]    = {0.25, 0.35, 0.8};

void movimentos(GLdouble lado, GLfloat ang, GLfloat desl, GLfloat tempo)
{
    //SETANDO AS COORDENADAS DOS VERTICES DO QUADRADO
    pax = lado * (1.0 / 2.0);
    pay = lado * (1.0 / 2.0);

    pbx = -1.0 * lado * (1.0 / 2.0);
    pby = lado * (1.0 / 2.0);

    pcx = -1.0 * lado * (1.0 / 2.0);
    pcy = -1.0 * lado * (1.0 / 2.0);

    pdx = lado * (1.0 / 2.0);
    pdy = -1.0 * lado * (1.0 / 2.0);


    //SETANDO AS COORDENADAS DA BOLA
    switch (arestaBolinha)
    {
        case ARESTA_DIREITA:
            by  -= desl/10.0;
            //DBG(printf("ARESTA_DIREITA Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            if(by < pdy)
            {
                bx = pdx - (by - pdy);
                by = pdy;
                arestaBolinha   = ARESTA_INFERIOR;
            }
            break;
        case ARESTA_INFERIOR:
            //DBG(printf("ARESTA_INFERIOR Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            bx  -= desl/10.0;
            if(bx < pcx)
            {
                by = pcy + (bx - pcx);
                bx = pcx;
                arestaBolinha   = ARESTA_ESQUERDA;
            }
            break;
        case ARESTA_ESQUERDA:
            //DBG(printf("ARESTA_ESQUERDA Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            by  += desl/10.0;
            if(by > pby)
            {
                bx = pbx + (by - pby);
                by = pby;
                arestaBolinha   = ARESTA_SUPERIOR;
            }
            break;
        case ARESTA_SUPERIOR:
            //DBG(printf("ARESTA_SUPERIOR Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            bx  += desl/10.0;
            if(bx > pax)
            {
                by = pay - (bx - pax);
                bx = pax;
                arestaBolinha   = ARESTA_DIREITA;
            }
            break;
        case ARESTA_NULA:
            bx  = pax;
            by  = pay;
            arestaBolinha = ARESTA_DIREITA;
        default:
            break;
    }

    //CONTROLE DO MOVIMENTO
    angMovimento += ang / 10.0;

    if((angMovimento < -360)&& (ang < 0))
        angMovimento += 360;
    else if((angMovimento > 360)&&(ang > 0))
        angMovimento -= 360;


    
    //DESENHANDO O QUADRADO
    // DBG(printf("l: %lf pax: %lf pay: %lf angMovimento: %lf\n", lado,pax,pay, angMovimento));
    glPushMatrix();
    glRotatef(angMovimento,0.0,0.0,1.0);
    glLineWidth(1.5);
    glColor3dv(corQuad);
    glBegin(GL_LINE_LOOP);
       glVertex2d(pax,pay);
       glVertex2d(pbx,pby);
       glVertex2d(pcx,pcy);
       glVertex2d(pdx,pdy);
    glEnd();
    glPopMatrix();

    if(!glIsEnabled(GL_POINT_SMOOTH))
        glEnable(GL_POINT_SMOOTH);

    //DESENHANDO A BOLA
    //DBG(printf("Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
    glPointSize(6.0);
    glPushMatrix();
    glRotatef(angMovimento,0.0,0.0,1.0);
    glColor3dv(corBola);
    glBegin(GL_POINTS); 
        glVertex2d(bx,by);
    glEnd();
    glPopMatrix();
}
