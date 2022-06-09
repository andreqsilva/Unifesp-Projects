#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float theta = 0.0;
float alfa = 0.0;
float gama = 0.0;
float phi = 0.0;
float lambda = 0.0;
float upsilon = 0.0;
float PI = 3.1415;

void retangulo(float x0, float x1, float y0, float y1) {
	glBegin(GL_POLYGON);
		glVertex2f(x0,y0); 
		glVertex2f(x0,y1); 
		glVertex2f(x1,y1);
		glVertex2f(x1,y0);    
	glEnd();
}

void paralelogramo(float *x, float *y) {
	glBegin(GL_POLYGON);
		glVertex2f(x[0],y[0]); 
		glVertex2f(x[1],y[1]); 
		glVertex2f(x[2],y[2]);
		glVertex2f(x[3],y[3]);    
	glEnd();
}

void line(float x, float y0, float y1) {
	glLineWidth(2.5f);
	glBegin(GL_LINES);
		glVertex2f(x,y0);
		glVertex2f(x,y1);
	glEnd();
}

void circulo(float r, float incX, float incY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 50.0;
			glVertex2f(r*cos(angulo)+incX, r*sin(angulo)+incY);
		}
	glEnd();
}

void pernas() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// perna esquerda
	glPushMatrix();
	glColor3f(0.3,0.5,0.6);
	glTranslatef(-0.17,-0.5,0.0);
	glRotatef(lambda,0.0,0.0,1.0);
	glTranslatef(0.17,0.5,0.0);
	retangulo(-0.25,-0.1,-0.5,-0.9);
	glPopMatrix();
	glColor3f(0.3,0.4,0.4);
	circulo(0.09,-0.17,-0.5);
	
	// perna direita
	glPushMatrix();
	glColor3f(0.3,0.5,0.6);
	glTranslatef(0.17,-0.5,0.0);
	glRotatef(upsilon,0.0,0.0,1.0);
	glTranslatef(-0.17,0.5,0.0);
	retangulo(0.25,0.1,-0.5,-0.9);
	glPopMatrix();
	glColor3f(0.3,0.4,0.4);
	circulo(0.09,0.17,-0.5);
}

void bracos() {
	float x_0[4] = {-0.8,-0.7,-0.35,-0.45};
	float y_0[4] = {-0.2,-0.3,-0.05,0.05};
	float x_1[4] = {0.8,0.7,0.35,0.45};
	float y_1[4] = {-0.2,-0.3,-0.05,0.05};
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// braço esquerdo
	glPushMatrix();
	glColor3f(0.3,0.5,0.6);
	glTranslatef(-0.4501,-0.0376,0.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(0.4501,0.0376,0.0);
	paralelogramo(x_0,y_0);
	
	glPushMatrix();
	glColor3f(0.3,0.5,0.6);
	glTranslatef(-0.75,-0.25,0.0);
	glRotatef(alfa,0.0,0.0,1.0);
	glTranslatef(0.75,0.25,0.0);
	retangulo(-0.8,-0.7,-0.2,-0.6); 
	glPopMatrix();
	
	glColor3f(0.3,0.4,0.4);
	circulo(0.09,-0.75,-0.25);
	glPopMatrix();
	circulo(0.09,-0.4501,-0.0376);
	
	// braço direito
	glPushMatrix();
	glColor3f(0.3,0.5,0.6);
	glTranslatef(0.4501,-0.0376,0.0);
	glRotatef(gama,0.0,0.0,1.0);
	glTranslatef(-0.4501,0.0376,0.0);
	paralelogramo(x_1,y_1);
	
	glPushMatrix();
	glColor3f(0.3,0.5,0.6);
	glTranslatef(0.75,-0.25,0.0);
	glRotatef(phi,0.0,0.0,1.0);
	glTranslatef(-0.75,0.25,0.0);
	retangulo(0.8,0.7,-0.2,-0.6); 
	glPopMatrix();
	
	glColor3f(0.3,0.4,0.4);
	circulo(0.09,0.75,-0.25);
	glPopMatrix();
	circulo(0.09,0.4501,-0.0376);
}

void torax() {
	glColor3f(0.3,0.5,0.6);
	retangulo(-0.45,0.45,0.05,-0.5);

	glColor3f(0.1,0.8,0.4);
	retangulo(-0.2,0.2,-0.1,-0.3);
	
	glColor3f(0.8,0.0,0.0);
	circulo(0.0422,-0.1589,-0.3614);
	glColor3f(1.0,0.8,0.0);
	circulo(0.0422,-0.0053,-0.3614);
	glColor3f(0.0,0.0,0.8);
	circulo(0.0422,0.1589,-0.3614);
}

void cabeca() {
	glColor3f(0.3,0.4,0.4);
	retangulo(-0.4,0.4,0.5,0.3);
	retangulo(-0.1,0.1,0.05,0.2);
	line(-0.35,0.7672,0.5);
	line(0.35,0.7672,0.5);
	
	glColor3f(0.3,0.5,0.6);
	retangulo(-0.3,0.3,0.6,0.2);
	circulo(0.03,-0.35,0.7621);
	circulo(0.03,0.35,0.7621);
	
	glColor3f(0.1,0.8,0.4);
	circulo(0.1,0.15,0.4);
	circulo(0.1,-0.15,0.4);
	retangulo(-0.05,0.05,0.25,0.22);
}

void desenha() {
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	cabeca();
	bracos();
	pernas();
	torax();
		
	glFlush();
}

void teclado(unsigned char tecla, int x, int y) {
	switch (tecla) {
		// braço esquerdo
		case 'w':
			if (theta <= 15.0) theta += 0.5;
			break;
		case 'q':
			if (theta >= -15.0) theta -= 0.5;
			break;
		// antebraço esquerdo
		case 's':
			if (alfa <= 15.0) alfa += 0.5;
			break;
		case 'a':
			if (alfa >= -15.0) alfa -= 0.5;
			break;
		// braço direito
		case 'o':
			if (gama <= 15.0) gama += 0.5;
			break;
		case 'i':
			if (gama >= -15.0) gama -= 0.5;
			break;
		// antebraço direito
		case 'l':
			if (phi <= 15.0) phi += 0.5;
			break;
		case 'k':
			if (phi >= -15.0) phi -= 0.5;
			break;
		// perna esquerda
		case 'x':
			if (lambda <= 15.0) lambda += 0.5;
			break;
		case 'z':
			if (lambda >= -15.0) lambda -= 0.5;
			break;
		// perna direita
		case '.':  // >
			if (upsilon <= 15.0) upsilon += 0.5;
			break;
		case ',':  // <
			if (upsilon >= -15.0) upsilon -= 0.5;
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Robo");
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutMainLoop();
	return 0;
}
