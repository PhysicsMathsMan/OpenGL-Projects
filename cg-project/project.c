#include<stdlib.h>
#include<time.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

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

void drawScene(float displacement) {
	glClear(GL_COLOR_BUFFER_BIT);
	int rand(); // random integers

	// Stars
	glPointSize(2.5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (int i = 1; i <= 50; i++)
		glVertex2f(rand() % 750, rand() % 750);
	glEnd();

	// Body
	glColor3f(226 / 255.0, 226 / 255.0, 72 / 255.0);
	glBegin(GL_QUADS);
	glVertex2f(300.0, 300.0 + displacement);
	glVertex2f(300.0, 500.0 + displacement);
	glVertex2f(500.0, 500.0 + displacement);
	glVertex2f(500.0, 300.0 + displacement);
	glEnd();

	// Connectors
	glColor3f(81 / 255.0, 99 / 255.0, 127 / 255.0);
	glBegin(GL_LINES);
	glVertex2f(500.0, 400.0 + displacement);
	glVertex2f(550.0, 400.0 + displacement);
	glVertex2f(300.0, 400.0 + displacement);
	glVertex2f(250.0, 400.0 + displacement);
	glEnd();

	// Panels
	glColor3f(29 / 255.0, 92 / 255.0, 193 / 255.0);
	glBegin(GL_QUADS);
	glVertex2f(250.0, 350.0 + displacement);
	glVertex2f(250.0, 450.0 + displacement);
	glVertex2f(50.0, 450.0 + displacement);
	glVertex2f(50.0, 350.0 + displacement);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(550.0, 350.0 + displacement);
	glVertex2f(550.0, 450.0 + displacement);
	glVertex2f(750.0, 450.0 + displacement);
	glVertex2f(750.0, 350.0 + displacement);
	glEnd();

	glFlush();
}

void display(void) {
	float displacement = -500;

	while(displacement != 50)
	{
		drawScene(displacement);
		displacement += 50;
		for (double delay = 0; delay <= 160000000; delay++);
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