#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include"scenes/scene1.c"

int mod=10;	// Used to reduce the star re-rendering rate.

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

void display(void) {
	float displacement = -500;

	while(displacement != 50)
	{
		drawScene(displacement, mod);
		displacement += 5;
		mod++;
		for (double delay = 0; delay <= 9000000; delay++);
	}

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Satellite");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}