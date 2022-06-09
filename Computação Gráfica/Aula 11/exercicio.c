#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

GLfloat light0_pos[] = {2.0f, 2.0f, 2.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat cX = 0.0;
GLfloat cY = 0.0;
float angZ = 0.0;

void lightning(){
	glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
	glLightfv(GL_LIGHT0,GL_AMBIENT,black);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,white);
	glLightfv(GL_LIGHT0,GL_SPECULAR,black);
	
	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,0.5f);
	glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,0.15f);
	glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,0.1f);
	
	// Fonte de Luz Direcional - Efeito de Holofote
	GLfloat light1_pos[] = {cX, cY, 6.0f, 1.0f};
	glLightfv(GL_LIGHT1,GL_POSITION,light1_pos);
	glLightfv(GL_LIGHT1,GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1,GL_SPECULAR, white);
	GLfloat direction[] = {0.0f, 0.0f, -1.0f};
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,direction);       //vetor direção
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,15.0f);               //espalhamento angular
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,0.5f);              //atenuação angular

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
    	gluLookAt(0.0, 0.0, 1.0,   //posição da camera
              	  0.0, 0.0, 0.0,   //para onde a camera aponta
              	  0.0, 1.0, 0.0);  //vetor view-up
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity(); 
    	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    	glViewport(0, 0, 500, 500);
    	lightning();
    	glPushMatrix();
}

void displayFunc() {
	GLfloat diffuse[4];
	GLfloat shininess;
	GLfloat specular[4];
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer

	glMatrixMode(GL_MODELVIEW); //define que a matrix È a model view
	glLoadIdentity(); //carrega a matrix de identidade
	gluLookAt(0.0, 0.0, 1.0,   //posiÁ„o da c‚mera
                  0.0, 0.0, 0.0,   //para onde a c‚mera aponta
                  0.0, 1.0, 0.0);  //vetor view-up
    
    	//glNormal3f(0.0,0.0,1.0);
	glPushMatrix();
    	shininess = 65.0f;
	diffuse[0] = 0.65f;
	diffuse[1] = 0.0f;
	diffuse[2] = 0.0f;
	diffuse[3] = 1.0f;
	specular[0] = 1.0f;
	specular[1] = 1.0f;
	specular[2] = 1.0f;
	specular[3] = 1.0f;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    	glMaterialf(GL_FRONT,GL_SHININESS,shininess);
	
	glRotatef(angZ,0.0,0.0,1.0);
	glTranslatef(-1.5,0.0,0.0);
	glutSolidSphere(0.25,40,40); 
	glPopMatrix();
	
	glPushMatrix();
	shininess = 65.0f;
	diffuse[0] = 0.0f;
	diffuse[1] = 0.65;
	diffuse[2] = 0.0f;
	diffuse[3] = 1.0f;
	specular[0] = 1.0f;
	specular[1] = 1.0f;
	specular[2] = 1.0f;
	specular[3] = 1.0f;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    	glMaterialf(GL_FRONT,GL_SHININESS,shininess);
	
	glRotatef(angZ,0.0,0.0,1.0);
	glTranslatef(1.5,0.0,0.0);
	glutSolidSphere(0.25,40,40);
	glPopMatrix();
	
	glPushMatrix();
	shininess = 65.0f;
	diffuse[0] = 0.0f;
	diffuse[1] = 0.0;
	diffuse[2] = 0.65f;
	diffuse[3] = 1.0f;
	specular[0] = 1.0f;
	specular[1] = 1.0f;
	specular[2] = 1.0f;
	specular[3] = 1.0f;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    	glMaterialf(GL_FRONT,GL_SHININESS,shininess);
	glRotatef(angZ,0.0,0.0,1.0);
	glTranslatef(0.0,-1.5,0.0);
	glutSolidSphere(0.25,40,40); 
	glPopMatrix();
	
	glPushMatrix();
	shininess = 65.0f;
	diffuse[0] = 0.65f;
	diffuse[1] = 0.65f;
	diffuse[2] = 0.0f;
	diffuse[3] = 1.0f;
	specular[0] = 1.0f;
	specular[1] = 1.0f;
	specular[2] = 1.0f;
	specular[3] = 1.0f;
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    	glMaterialf(GL_FRONT,GL_SHININESS,shininess);
    	
	glRotatef(angZ,0.0,0.0,1.0);
	glTranslatef(0.0,1.5,0.0);
	glutSolidSphere(0.25,40,40);  
	glPopMatrix();
	
	lightning();
    
        glFlush();
}

void timerFunc(int value) {

	angZ += 5;
			
	glutPostRedisplay();
	glutTimerFunc(100,timerFunc,1);
}

void mouse(int botao, int estado, int x, int y) {
	switch (botao) {
		case GLUT_LEFT_BUTTON:
			if (estado == GLUT_DOWN) {
				cX = (((float)x/250)-1)*2;
				cY = (((float)y/250)-1)*(-2);
				printf("cX=%.2f \ncY=%.2f \n", cX, cY);
			}
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("Iluminacao");
	glutDisplayFunc(displayFunc);
	glutMouseFunc(mouse);
	glutTimerFunc(100,timerFunc,1);
	init();
	glutMainLoop();
	return 0;
}
