#include "../headers/tresmeios.h"

int nmax = 10;

int itDesenhar = 0;

int cor_inicial_vermelho = 1;
int cor_inicial_verde = 0;
int cor_inicial_azul = 0;

int cor_final_vermelho = 0;
int cor_final_verde = 0;
int cor_final_azul = 1;

void desenha3Meios(GLdouble x, GLdouble y, int n, GLdouble lado)
{
	GLdouble pax, pay,
                 pbx, pby,
		 pcx, pcy;
	GLdouble cor[3];


	if(n > nmax) return;

	if(n == itDesenhar || itDesenhar == 0) defineCorInterpolada(n, cor);
	else cor[0] = cor[1] = cor[2] = 0.0;

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
	p[0] = ((GLdouble)n * ((GLdouble) (255.0 * cor_final_vermelho - 255.0 * cor_inicial_vermelho) / (GLdouble)nmax) +   255.0 * cor_inicial_vermelho) / (GLdouble)255.0;
	p[1] = ((GLdouble)n * ((GLdouble) (255.0 * cor_final_verde    - 255.0 * cor_inicial_verde   ) / (GLdouble)nmax) +   255.0 * cor_inicial_verde    ) / (GLdouble)255.0;
	p[2] = ((GLdouble)n * ((GLdouble) (255.0 * cor_final_azul     - 255.0 * cor_inicial_azul    ) / (GLdouble)nmax) +   255.0 * cor_inicial_azul     ) / (GLdouble)255.0;	
}

void menuParametros3Meios(GLUI *menu, GLUI_Panel *painel)
{
	GLUI_Panel *p_cInicial;
	GLUI_Panel *p_cFinal;
	GLUI_Spinner *vp1_nmax;
	GLUI_Spinner *vp1_ndis;  
  
	vp1_nmax = menu->add_spinner_to_panel(painel, "N maximo:" , GLUI_SPINNER_INT, &nmax);
	vp1_nmax->set_int_limits(0, NMAX_RECOMENDADO, GLUI_LIMIT_CLAMP);

	vp1_ndis = menu->add_spinner_to_panel(painel, "Desenhar somente uma iteracao:" , GLUI_SPINNER_INT, &itDesenhar);
	vp1_ndis->set_int_limits(0, NMAX_RECOMENDADO, GLUI_LIMIT_CLAMP);
	
	p_cInicial = menu->add_panel_to_panel(painel, "Cor Inicial:");
	menu->add_checkbox_to_panel(p_cInicial, "Vermelho", &cor_inicial_vermelho);
	menu->add_column_to_panel(p_cInicial, false);
	menu->add_checkbox_to_panel(p_cInicial, "Verde", &cor_inicial_verde);
	menu->add_column_to_panel(p_cInicial, false);
	menu->add_checkbox_to_panel(p_cInicial, "Azul", &cor_inicial_azul);
	
	p_cFinal = menu->add_panel_to_panel(painel, "Cor Final:");
	menu->add_checkbox_to_panel(p_cFinal, "Vermelho", &cor_final_vermelho);
	menu->add_column_to_panel(p_cFinal, false);
	menu->add_checkbox_to_panel(p_cFinal, "Verde", &cor_final_verde);
	menu->add_column_to_panel(p_cFinal, false);
	menu->add_checkbox_to_panel(p_cFinal, "Azul", &cor_final_azul);	
	
	
}
