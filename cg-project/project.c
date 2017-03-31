#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

int mod=9;


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
	float cur_rand1[35], cur_rand2[35];
	int i;
	mod++;
	if(mod%10==0) {
		for(i=1;i<=30;i++) {
			cur_rand1[i]=rand()%750;
			cur_rand2[i]=rand()%750;
		}
	}
	printf("%d",mod);
	glPointSize(2.5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
		for (i = 1; i < 35; i++)
			glVertex2f(cur_rand1[i], cur_rand2[i]);
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
	int tilt=10;
	glColor3f(29 / 255.0, 92 / 255.0, 193 / 255.0);
	glBegin(GL_QUADS);
		glVertex2f(250.0-tilt, 350.0 + displacement);
		glVertex2f(250.0+tilt, 450.0 + displacement);
		glVertex2f(50.0+tilt, 450.0 + displacement);
		glVertex2f(50.0-tilt, 350.0 + displacement);
	glEnd();
	glBegin(GL_QUADS);
		glVertex2f(550.0-tilt, 350.0 + displacement);
		glVertex2f(550.0+tilt, 450.0 + displacement);
		glVertex2f(750.0+tilt, 450.0 + displacement);
		glVertex2f(750.0-tilt, 350.0 + displacement);
	glEnd();

	glFlush();
}

void display(void) {
	float displacement = -500;

	while(displacement != 50)
	{
		drawScene(displacement);
		displacement += 5;
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