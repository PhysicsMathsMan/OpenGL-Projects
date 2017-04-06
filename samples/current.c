#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>


void drawRocket(float x,float xcor,float ycor) {
 
    int mod;
    for(int i=0;i<100000;i++) {
        glClear(GL_COLOR_BUFFER_BIT);
        // Rocket body
        glColor3f(0.96, 1.0, 1.0);
        glBegin(GL_QUADS);
            glVertex2f(0.3*x +xcor,2.0*x+ycor);
            glVertex2f(0.3*x +xcor,4.5*x+ycor);
            glVertex2f(0.65*x+xcor,4.5*x+ycor);
            glVertex2f(0.65*x+xcor,2.0*x+ycor);
        glEnd();

        // Rocket head
        glColor3f(0.96, 0.87, 0.70);
        glBegin(GL_TRIANGLES);
            glVertex2f(0.3*x  +xcor,4.5*x+ycor);
            glVertex2f(0.475*x+xcor,5.5*x+ycor);
            glVertex2f(0.65*x +xcor,4.5*x+ycor);
        glEnd();

        // Rocket base
        glBegin(GL_POLYGON);
            glVertex2f(0.25*x+xcor,1.0*x+ycor);
            glVertex2f(0.3*x +xcor,2.0*x+ycor);
            glVertex2f(0.65*x+xcor,2.0*x+ycor);
            glVertex2f(0.7*x +xcor,1.0*x+ycor);
        glEnd();
        
        glColor3f(0.46, 0.46, 0.46);
        char string[]="NASA";
        for(i=0;i<4;i++) {
            glRasterPos2f(0.5*x+xcor-13, 1*x+ycor*2+i*25);
		    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
        }

        // Rocket flames
        if(mod%5==0) {
            glColor3f(1.0, 0.64, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(0.25*x +xcor,1.0*x+ycor);
                glVertex2f(0.0*x  +xcor,0.6*x+ycor);
                glVertex2f(0.475*x+xcor,0.0*x+ycor);
                glVertex2f(0.95*x +xcor,0.6*x+ycor);
                glVertex2f(0.7*x  +xcor,1.0*x+ycor);
            glEnd();
        }
        glColor3f(1.0, 0.27, 0.0);
        glBegin(GL_POLYGON);
            glVertex2f(0.25*x +xcor,1.0*x+ycor);
            glVertex2f(0.2*x  +xcor,0.7*x+ycor);
            glVertex2f(0.475*x+xcor,0.5*x+ycor);
            glVertex2f(0.75*x +xcor,0.7*x+ycor);
            glVertex2f(0.7*x  +xcor,1.0*x+ycor);
        glEnd();
        glFlush();
        mod++;
        }
}



void display(void) {
    int x=80;
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	//glutPostRedisplay();
	drawRocket(x,500,100);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(display);
    glutMainLoop();    
    return 0;
}