#ifndef H_BUTTERFLY
#define H_BUTTERFLY

#include <GL/glut.h>
#include <math.h>

/* Desenha a borboleta na tela :) */
void desenhaButterfly();

/* Varia a cor da borboleta */
void defineCorButterfly(int n, GLdouble *p);

/* Equações da Butterfly:
   http://local.wasp.uwa.edu.au/~pbourke//geometry/butterfly/ */

#define PI 3.14159
#define FU(u) (i * 24.0 * PI / N) 
#define PX(u) (cos(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))
#define PY(u) (sin(u) * (exp(cos(u)) - 2 * cos(4 * u) - pow(sin(u / 12),5.0)))


#endif
