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

#include "../headers/movimentos.h"

GLdouble    angMovimento = 0.0;


//Inicializador da bola
int         arestaBolinha = ARESTA_NULA;

GLdouble    vetorCaminho[TAM_FILA][4];

int tamFila = 0;

//Contador para ser usado no vetor
int         contCaminho = 0;
int         contVolta   = 0;

//Pontos da "Bola"
GLdouble    by, bx;
GLdouble    ultimoLado;

void movimentos(GLdouble lado, GLfloat ang, GLfloat desl, int movimenta, int desenhaQuadrado, int desenhaBola, int desenhaRastro)
{
	GLdouble    pax, pay,
		    pbx, pby,
		    pcx, pcy,
		    pdx, pdy;
	GLdouble    corQuad[3]          = {1.0, 1.0, 0.0},
		    corBola[3]         = {0.25, 0.35, 0.8},
		    corCaminho[3][3]   = {  {0.15, 0.15, 0.50},
					    {0.00, 0.75, 0.15},
					    {0.50, 0.40, 0.70}};
					    
	GLdouble razao;

	if(ultimoLado != lado) 
	{
	        razao = lado/ultimoLado;
		bx *= razao;
		by *= razao;
		
	}
	ultimoLado = lado;
					    
	int i = 0, j = 0;

	ang *= -1.0;

	//SETANDO AS COORDENADAS DOS VERTICES DO QUADRADO
	pax = lado * (1.0 / 2.0);
	pay = lado * (1.0 / 2.0);

	pbx = -1.0 * lado * (1.0 / 2.0);
	pby = lado * (1.0 / 2.0);

	pcx = -1.0 * lado * (1.0 / 2.0);
	pcy = -1.0 * lado * (1.0 / 2.0);

	pdx = lado * (1.0 / 2.0);
	pdy = -1.0 * lado * (1.0 / 2.0);


	if(movimenta == 1)
	{
		//SETANDO AS COORDENADAS DA BOLA
		switch (arestaBolinha)
		{
			case ARESTA_DIREITA:
			by  -= desl/10.0;      
			if(by <= pdy)
			{
				bx = pdx - (pdy - by);
				by = pdy;
				arestaBolinha   = ARESTA_INFERIOR;
			}
			else if(by >= pay)
			{
				bx = pax - (by - pay);
				by = pay;
				arestaBolinha   = ARESTA_SUPERIOR;
				contVolta = (contVolta + 1) % 3; // trocando a cor do rastro
			}	    
			DBG(printf("ARESTA_DIREITA Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
			break;
		    case ARESTA_INFERIOR:            
			bx  -= desl/10.0;
			if(bx <= pcx)
			{
				by = pcy + (pcx - bx);
				bx = pcx;
				arestaBolinha   = ARESTA_ESQUERDA;
			}
			else if(bx >= pdx)
			{
				by = pdy + (bx - pdx);
				bx = pdx;
				arestaBolinha   = ARESTA_DIREITA;
			}	    
			DBG(printf("ARESTA_INFERIOR Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
			break;
		    case ARESTA_ESQUERDA:
			by  += desl/10.0;
			if(by >= pby)
			{
				bx = pbx + (by - pby);
				by = pby;
				arestaBolinha   = ARESTA_SUPERIOR;
			}
			else if(by <= pcy)
			{
				bx = pcx + (pcy - by);
				by = pcy;
				arestaBolinha   = ARESTA_INFERIOR;
			}	    
			DBG(printf("ARESTA_ESQUERDA Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
			break;
		    case ARESTA_SUPERIOR:
			bx  += desl/10.0;
			if(bx >= pax)
			{
				by = pay - (bx - pax);
				bx = pax;
				arestaBolinha   = ARESTA_DIREITA;
				contVolta = (contVolta + 1) % 3; // trocando a cor do rastro
			}
			else if(bx <= pbx)
			{
				by = pby - (pbx - bx);
				bx = pbx;
				arestaBolinha   = ARESTA_ESQUERDA;
			}	    
			DBG(printf("ARESTA_SUPERIOR Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
			break;
		    case ARESTA_NULA:
			bx  = pax;
			by  = pay;
			if(desl >= 0) arestaBolinha = ARESTA_DIREITA;
			else	  arestaBolinha = ARESTA_SUPERIOR;
		    default:
			break;
		}

		//CONTROLE DO MOVIMENTO
		angMovimento += ang / 10.0;

		if((angMovimento < -360)&& (ang < 0))
			angMovimento += 360;
		else if((angMovimento > 360)&&(ang > 0))
			angMovimento -= 360;
		
		//ADICIONANDO OS PONTOS DA BOLA PARA O RASTRO DO CAMINHO
		
		if(tamFila < TAM_FILA)
		{
			setPontosBola(contCaminho, angMovimento, contVolta);
			DBG(printf("X %lf Y %lf ANG %lf COR %lf\n", vetorCaminho[contCaminho][0],vetorCaminho[contCaminho][1], vetorCaminho[contCaminho][2],vetorCaminho[contCaminho][3]));
			contCaminho++;
			tamFila++;
		}
		else
		{
			if(contCaminho >= TAM_FILA) contCaminho -= TAM_FILA;
			setPontosBola(contCaminho, angMovimento, contVolta);
			DBG(printf("X %lf Y %lf ANG %lf COR %lf\n", vetorCaminho[contCaminho][0],vetorCaminho[contCaminho][1], vetorCaminho[contCaminho][2],vetorCaminho[contCaminho][3]));
			contCaminho++;			
			if(contCaminho >= TAM_FILA) contCaminho -= TAM_FILA;
		}
	
	}
    
    

	if(desenhaRastro == 1)
	{
		if(tamFila)
		{
			glPointSize(2.0);
		    
			glBegin(GL_LINES);
		    
			if(tamFila == TAM_FILA) i = contCaminho + 1;
			else			i = 1;
			
			for(j = 1; j < tamFila; j++)
			{	
				if(i >= TAM_FILA) i -= TAM_FILA;
				
				if(i == 0)
				{
					glColor3dv(corCaminho[(int)vetorCaminho[TAM_FILA-1][3]]);
					glVertex2d(vetorCaminho[TAM_FILA-1][0], vetorCaminho[TAM_FILA-1][1]);
					glColor3dv(corCaminho[(int)vetorCaminho[0][3]]);
					glVertex2d(vetorCaminho[0][0], vetorCaminho[0][1]);
				}
				else
				{
					glColor3dv(corCaminho[(int)vetorCaminho[i-1][3]]);
					glVertex2d(vetorCaminho[i-1][0], vetorCaminho[i-1][1]);
					glColor3dv(corCaminho[(int)vetorCaminho[i][3]]);
					glVertex2d(vetorCaminho[i][0], vetorCaminho[i][1]);
				}
				i++;
								

			}
			glEnd();
		}
	  
	}

	 if(desenhaQuadrado == 1)
	 {
		//DESENHANDO O QUADRADO
		DBG(printf("l: %lf pax: %lf pay: %lf angMovimento: %lf\n", lado,pax,pay, angMovimento));
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
	 }


	if(desenhaBola == 1)
	{
		//DESENHANDO A BOLA
		DBG(printf("Aresta: %d bx %lf by: %lf\n", arestaBolinha, bx, by));
		glPushMatrix();
		glRotatef(angMovimento,0.0,0.0,1.0);
		
		glColor3d(1.0, 1.0, 1.0);
		glPointSize(8.0);
		glBegin(GL_POINTS);
			glVertex2d(bx,by);
		glEnd();		
		
		glColor3dv(corBola);
		glPointSize(6.0);
		glBegin(GL_POINTS);
			glVertex2d(bx,by);
		glEnd();		
		
		glPopMatrix();	  
	}


}

void setPontosBola(int i, GLdouble angulo, int cor)
{
    vetorCaminho[i][0] = bx * cos(((float) 3.14159/180) * angulo) - by * sin(((float) 3.14159/180) * angulo);
    vetorCaminho[i][1] = bx * sin(((float) 3.14159/180) * angulo) + by * cos(((float) 3.14159/180) * angulo);
    vetorCaminho[i][2] = angMovimento;
    vetorCaminho[i][3] = cor;
}

void apagaRastro()
{
    contCaminho = 0;
    tamFila	= 0;
}
