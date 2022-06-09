#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

GLfloat light0_pos[] = {2.0f, 2.0f, 2.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat kd = 0.0f;

void lightning(){
    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,black);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,white);
    glLightfv(GL_LIGHT0,GL_SPECULAR,black);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //define que a matrix È a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(0.0, 0.0, 1.0,   //posiÁ„o da c‚mera
              0.0, 0.0, 0.0,   //para onde a c‚mera aponta
              0.0, 1.0, 0.0);  //vetor view-up

    glMatrixMode(GL_PROJECTION); //define que a matrix È a de projeÁ„o
    glLoadIdentity(); //carrega a matrix de identidade
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); //define uma projeÁ„o ortogonal
    //gluPerspective(90.0, 1.0, 2.0, 8.0); //define uma projeÁ„o perspectiva
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 8.0); //define uma projeÁ„o perspectiva simÈtrica
    //glFrustum(-2.0, 1.0, -1.0, 2.0, 2.0, 8.0); //define uma projeÁ„o perspectiva obliqua
    glViewport(0, 0, 500, 500);
    lightning();
    glPushMatrix();
}

void displayFunc() {
        GLfloat diffuse[4];
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer

        glMatrixMode(GL_MODELVIEW); //define que a matrix È a model view
        glLoadIdentity(); //carrega a matrix de identidade
        gluLookAt(0.0, 0.0, 1.0,   //posiÁ„o da c‚mera
                  0.0, 0.0, 0.0,   //para onde a c‚mera aponta
                  0.0, 1.0, 0.0);  //vetor view-up
    
        glPushMatrix();
    
        diffuse[0] = kd;
        diffuse[1] = kd;
        diffuse[2] = kd;
        diffuse[3] = 1.0f;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glutSolidSphere(1.0,40,40);  //desenha uma esfera
    
        lightning();
    
        glFlush();
}

void teclado(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
             if(kd<1.0)
                 kd+=0.1;
             break ;
        case GLUT_KEY_DOWN :
             if(kd>0.0)
                 kd-=0.1;
             break ;
        default:
             break;
     }
     glutPostRedisplay() ;
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Iluminacao");
    glutDisplayFunc(displayFunc);
    glutSpecialFunc(teclado);
    init();
    glutMainLoop();
    return 0;
}
