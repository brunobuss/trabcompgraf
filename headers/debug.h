#ifndef H_DEBUG
#define H_DEBUG

#include "stdio.h"

/* Indica se o programa deve imprimir informações de debug */
#define DEBUG 1

/* Macros */
#define DBG(x) if(DEBUG) { x; }

#endif
