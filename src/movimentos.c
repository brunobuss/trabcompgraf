#include "../headers/movimentos.h"
#include "../headers/debug.h"

GLdouble    angMovimento = 0.0;


//Inicializador da bola
int         arestaBolinha = ARESTA_NULA;

GLdouble    vetorCaminho[1000][3];

//Contador para ser usado no vetor
int         contCaminho = 0;

//Pontos da "Bola"
GLdouble    by,bx;

void movimentos(GLdouble lado, GLfloat ang, GLfloat desl, GLfloat tempo)
{
    GLdouble    pax, pay,
                pbx, pby,
                pcx, pcy,
                pdx, pdy;

    

    GLdouble    corQuad[3]      = {1.0, 1.0, 0.0},
                corBola[3]      = {0.25, 0.35, 0.8},
                corCaminho[3]   = {1.0, 0.0, 0.0};

    int i = 0;
    
    //SETANDO AS COORDENADAS DOS VERTICES DO QUADRADO
    pax = lado * (1.0 / 2.0);
    pay = lado * (1.0 / 2.0);

    pbx = -1.0 * lado * (1.0 / 2.0);
    pby = lado * (1.0 / 2.0);

    pcx = -1.0 * lado * (1.0 / 2.0);
    pcy = -1.0 * lado * (1.0 / 2.0);

    pdx = lado * (1.0 / 2.0);
    pdy = -1.0 * lado * (1.0 / 2.0);

    

    //DBG(printf("vetorCaminho %ld\n", sizeof(vetorCaminho)));
   
    //SETANDO AS COORDENADAS DA BOLA
    switch (arestaBolinha)
    {
        case ARESTA_DIREITA:
            by  -= desl/10.0;            
            if(by < pdy)
            {
                bx = pdx - (by - pdy);
                by = pdy;
                arestaBolinha   = ARESTA_INFERIOR;
            }
            DBG(printf("ARESTA_DIREITA Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            break;
        case ARESTA_INFERIOR:            
            bx  -= desl/10.0;
            if(bx <= pcx)
            {
                by = pcy - (bx - pcx);
                bx = pcx;
                arestaBolinha   = ARESTA_ESQUERDA;
            }
            DBG(printf("ARESTA_INFERIOR Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            break;
        case ARESTA_ESQUERDA:
            by  += desl/10.0;
            if(by > pby)
            {
                bx = pbx + (by - pby);
                by = pby;
                arestaBolinha   = ARESTA_SUPERIOR;
            }
            DBG(printf("ARESTA_ESQUERDA Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
            break;
        case ARESTA_SUPERIOR:
            bx  += desl/10.0;
            if(bx > pax)
            {
                by = pay - (bx - pax);
                bx = pax;
                arestaBolinha   = ARESTA_DIREITA;
            }
            DBG(printf("ARESTA_SUPERIOR Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
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

    //ADICIONANDO OS PONTOS DA BOLA PARA O RASTRO DO CAMINHO
    if(contCaminho < 1000)
    {
        vetorCaminho[contCaminho][0] = bx;
        vetorCaminho[contCaminho][1] = by;
        vetorCaminho[contCaminho][2] = angMovimento;
        DBG(printf("X %lf Y %lf ANG %lf\n", vetorCaminho[contCaminho][0],vetorCaminho[contCaminho][1], vetorCaminho[contCaminho][2]));
        contCaminho++;
    }

    if(contCaminho)
    {
        glPointSize(2.0);
        glColor3dv(corCaminho);
        
        
        
        for(i = 1; i < contCaminho; i++)
        {
            glPushMatrix();
            glRotatef(vetorCaminho[i-1][2],0.0,0.0,1.0);
            glBegin(GL_LINES);
                glVertex2d(vetorCaminho[i-1][0], vetorCaminho[i-1][1]);
                glVertex2d(vetorCaminho[i][0], vetorCaminho[i][1]);
            glEnd();
            glPopMatrix();
            
        }
            //  glVertex2d(vetorCaminho[0][0], vetorCaminho[0][1]);
        
        
    }
}
