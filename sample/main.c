#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<time.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	glutPostRedisplay();
	
	// Initialise seed with current time
	srand(time(NULL));
}



void renderFunction(float displacement) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.0+displacement);
        glVertex2f(-0.5, 0.0+displacement);
        glVertex2f(0.5, 0.0+displacement);
        glVertex2f(0.5, -0.0+displacement);
    glEnd();
    glFlush();
}



void display(void) {
	float displacement = -500/750;

	while(displacement != 50/750)
	{
		renderFunction(displacement);
		displacement += 50/750;
		for (double delay = 0; delay <= 160000000; delay++);
	}

}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    init();
    glutMainLoop();    
    return 0;
}