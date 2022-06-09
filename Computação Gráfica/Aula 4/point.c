#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 1/número de pixels => 1/400 = 0.005
   pontoX = (x * 0.005) - 1
   pontoY = ((y * 0.005) - 1) * (-1)
*/

float pontoX = -2;	//iniciando fora das coordenadas
float pontoY = -2;

void ponto() {
	glPointSize(2.0f);
	glBegin(GL_POINTS);
		glVertex2f(pontoX, pontoY);
	glEnd();
}

void desenha() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	ponto();
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
			break;
		default:
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
	glutMainLoop();
	return 0;
}
