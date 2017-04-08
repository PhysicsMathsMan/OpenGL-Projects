#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include"scenes/scene1.c"
#include "scenes/scene2.c"

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Satellite");
	glutDisplayFunc(display2);
	//init();
	glutMainLoop();
	return 0;
}