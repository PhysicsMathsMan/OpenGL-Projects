#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include"scenes/scene1.c"

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	glutPostRedisplay();
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Satellite");
	glutDisplayFunc(display1);
	init();
	glutMainLoop();
	return 0;
}