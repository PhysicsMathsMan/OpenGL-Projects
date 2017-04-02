#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<math.h>



void renderFunction(float displacement) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5+displacement);
        glVertex2f(-0.5, 0.0+displacement);
        glVertex2f(0.5, 0.0+displacement);
        glVertex2f(0.5, -0.5+displacement);
    glEnd();
    glFlush();
}



void display(void) {
	float displacement = -1;

	while(displacement < 0.5)
	{
		renderFunction(displacement);
		displacement += 0.01;
		for (double delay = 0; delay <= 1600000; delay++);
	}

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