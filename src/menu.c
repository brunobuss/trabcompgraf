#include "../headers/menu.h"

GLUI *menu;

void initMenu(void)
{
	menu = GLUI_Master.create_glui(MENU_NOME);
}

GLUI *objetoMenu(void)
{
	return menu;
}