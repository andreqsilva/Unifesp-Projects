#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 1/número de pixels => 1/400 = 0.005
   pontoX = (x * 0.005) - 1
   pontoY = ((y * 0.005) - 1) * (-1)
*/

float pontoX = 0;
float pontoY = 0;
float red = 0.0;
float green = 0.0;
float blue = 1.0;

void ponto(float red, float green, float blue) {
	glColor3f(red, green, blue);
	glPointSize(5.0f);  // tamanho do ponto
	glBegin(GL_POINTS);
		glVertex2f(pontoX, pontoY);
	glEnd();
}

void desenha() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	ponto(red,green,blue);
	glFlush();
}

void mouse(int botao, int estado, int x, int y) {
	switch (botao) {
		case GLUT_LEFT_BUTTON:
			if (estado == GLUT_DOWN) {
				printf("x = %d, y = %d \n", x,y);
				pontoX = (x * 0.005) - 1;	
				pontoY = ((y * 0.005) - 1) * -1;
			}
	}
	glutPostRedisplay();
}

void teclado_numerico(unsigned char tecla, int x, int y) {
	switch (tecla) {	
		case '0':	//vermelho
			red = 1.0;
			green = 0.0;
			blue = 0.0;
			break;
		case '1':	//verde
			red = 0.0;
			green = 1.0;
			blue = 0.0;
			break;
		case '2':	//azul
			red = 0.0;
			green = 0.0;
			blue = 1.0;
			break;
		case '3':	//amarelo
			red = 1.0;
			green = 1.0;
			blue = 0.0;
			break;
		case '4':	//roxo
			red = 1.0;
			green = 0.0;
			blue = 1.0;
			break;
		case '5':	//ciano
			red = 0.0;
			green = 1.0;
			blue = 1.0;
			break;
		case '6':	//laranja
			red = 1.0;
			green = 0.5;
			blue = 0.0;
			break;
		case '7':	//marrom
			red = 0.5;
			green = 0.2;
			blue = 0.0;
			break;
		case '8':	//rosa
			red = 1.0;
			green = 0.2;
			blue = 0.5;
			break;
		case '9':	//branco
			red = 1.0;
			green = 1.0;
			blue = 1.0;
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Pontos");
	glutDisplayFunc(desenha);
	glutMouseFunc(mouse);
	glutKeyboardFunc(teclado_numerico);
	glutMainLoop();
	return 0;
}
