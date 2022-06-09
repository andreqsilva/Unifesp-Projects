#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

// gcc first_polygon.c -o first_polygon -lglut -lGLU -lGL -lm
// -lm para math.h

float up = 0.0;
float right = 0.0;

void quadrado(float incX, float incY) {
	glBegin(GL_POLYGON);
		glVertex2f(-0.25+incX+right, 0.25+incY+up);
		glVertex2f(0.25+incX+right, 0.25+incY+up);
		glVertex2f(0.25+incX+right, -0.25+incY+up);
		glVertex2f(-0.25+incX+right, -0.25+incY+up);
	glEnd();
}

void circulo() {
	int i;
	float angulo = 0.0;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 50; i++) {	//50 pontos
		angulo = 2 * PI * i / 50;
		glVertex2f(0.25*cos(angulo), 0.25*sin(angulo));
	}

	glEnd();
}

void desenha() {
	glClearColor(0, 0, 0, 0); //preto
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	circulo();
	glColor3f(1.0, 0.0, 0.0);
	quadrado(0.5,0.5);
	glColor3f(0.0, 1.0, 0.0);
	quadrado(-0.5,0.5);
	glColor3f(0.0, 0.0, 1.0);
	quadrado(0.5,-0.5);
	glColor3f(1.0, 1.0, 0.0);
	quadrado(-0.5,-0.5);
	glFlush();
}

void teclado(unsigned char tecla, int x, int y) {
	switch (tecla) {
		case 'u':
			up += 0.05;
			break;
		case 'd':
			up -= 0.05;
			break;
		case 'r':
			right += 0.05;
			break;
		case 'l':
			right -= 0.05;
			break;
		default:
			break;
	}
	glutPostRedisplay(); //renderiza a tela
}

void teclado_especial(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP:
			up += 0.05;
			break;
		case GLUT_KEY_DOWN:
			up -= 0.05;
			break;
		case GLUT_KEY_RIGHT:
			right += 0.05;
			break;
		case GLUT_KEY_LEFT:
			right -= 0.05;
			break;
		default:
			break;
	}
	glutPostRedisplay(); //renderiza a tela
}

void mouse(int botao, int estado, int x, int y) {
	switch (botao) {
		case GLUT_LEFT_BUTTON:
			if (estado == GLUT_DOWN) {
				printf("x = %d, y = %d\n", x,y);	//imprime as coordenadas
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
	glutCreateWindow("Primeiro programa usando OpenGL");
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(teclado_especial);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}
