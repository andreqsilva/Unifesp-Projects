#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float angX = 0;
float angY = 0;
int opcao; 

void init() {
	glClearColor(0.0,0.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST);  // habilita o teste de profundidade
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-7.0,7.0,-7.0,7.0,-7.0,7.0); // coordenadas -7 a 7 em todos os eixos (volume de visualização)
	glPushMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	
	glPopMatrix();	// carrega o volume de visualização
	glPushMatrix(); // guarda de novo 
	
	glRotatef(angX,1.0,0.0,0.0); 
	glRotatef(angY,0.0,1.0,0.0);
	glutWireSphere(3,50,50);
	//glutWireTeapot(3.0);
	
	glFlush();
}

void anima() {
	switch (opcao) {
		case 1:
			angX += 5;
			break;
		case 2:
			angX -= 5;
			break;
		case 3:
			angY -= 5;
			break;
		case 4:
			angY += 5;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void rotacoes(int key, int x, int y) {
	glutIdleFunc(anima);
	switch (key) {
		case GLUT_KEY_UP:
			opcao = 1;
			break;
		case GLUT_KEY_DOWN:
			opcao = 2;
			break;
		case GLUT_KEY_LEFT:
			opcao = 3;
			break;
		case GLUT_KEY_RIGHT:
			glutIdleFunc(NULL);
			opcao = 4;
			break;
		default:
			break;
	}
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("Objetos 3D");
	glutDisplayFunc(display);
	glutSpecialFunc(rotacoes);
	glutIdleFunc(anima);
	init();
	glutMainLoop();	
}

