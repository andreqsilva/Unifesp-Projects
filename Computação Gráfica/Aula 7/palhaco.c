#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ANIMAÇÃO 
   - Quando está com o chapéu, o palhço fica feliz
   - Quando está sem o chapéu, o nariz do palhaço muda de cor e ele fica triste
*/

float incY = 0;

float RED[2] = {1.0,0.9};
float GREEN[2] = {0.0,0.8};
float BLUE[2] = {0.0,0.0};

float angY = 0;
int turn = 0;
int state = 0;

void init() {
	glClearColor(0.0,0.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-7.0,7.0,-7.0,7.0,-7.0,7.0);
	glPushMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPopMatrix();
	glPushMatrix();
	
	// chapéu
	glColor3f(0.6,0.8,0.3);
	glPushMatrix();
	glTranslatef(0.0,2.5+incY,0.0);
	glTranslatef(0.0,-1.1,0.0);
	glRotatef(-90,1.0,0.0,0.0);
	glutWireCone(1.8,2.5,80,80);
	glPopMatrix();
	
	// cabeça
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glTranslatef(0.0,-1.0,0.0);
	glRotatef(angY,0.0,1.0,0.0);
	glutSolidSphere(3,50,50);
	
	// cabelo
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(-2.0,1.0,0.0);
	glutWireTorus(0.5,1.0,50,50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2.0,1.0,0.0);
	glutWireTorus(0.5,1.0,50,50);
	glPopMatrix();
	
	// Olhos
	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
	glTranslatef(1.0,0.7,2.5);
	glRotatef(164,1.0,0.0,0.0);
	glRotatef(340,0.0,1.0,0.0);
	glutSolidTorus(0.2,0.6,50,50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-1.0,0.7,2.5);
	glRotatef(164,1.0,0.0,0.0);
	glRotatef(20,0.0,1.0,0.0);
	glutSolidTorus(0.2,0.6,50,50);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(0.9,0.65,2.25);
	glutWireSphere(0.6,50,50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.9,0.65,2.25);
	glutWireSphere(0.6,50,50);
	glPopMatrix();
		
	// nariz
	glPushMatrix();
	glColor3f(RED[turn],GREEN[turn],BLUE[turn]);
	glTranslatef(0.0,-0.5,3.0);
	glutWireSphere(0.5,50,50);
	glPopMatrix();
	
	// boca
	glColor3f(1.0,0.0,0.0);
	switch (state) {
		case 0: // feliz
			glTranslatef(0.0,-1.0,2.5);
			glutWireTorus(0.1,0.8,50,50);
			glPopMatrix();
			break;
		
		case 1: // triste
			glTranslatef(0.0,-2.0,1.86);
			glRotatef(60,1.0,0.0,0.0);
			glutWireTorus(0.1,0.8,50,50);
			glPopMatrix();
			break;
	}
	glFlush();
}

void timerFunc(int value) {

	if (angY < 360) angY += 5;
	else angY = 0;
			
	if (angY > 180 && turn == 1) incY += 0.05;
	if (angY > 180 && turn == 0) incY -= 0.05;		
	
	if (angY == 180 || angY == -180) {
		turn = !turn;	// muda as cores
		state = !state;
	}
			
	glutPostRedisplay();
	glutTimerFunc(100,timerFunc,1);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(600,600);
	glutCreateWindow("Palhaco");
	glutDisplayFunc(display);
	glutTimerFunc(100,timerFunc,1);
	init();
	glutMainLoop();	
}

