#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void drawCircle(GLfloat radius, GLfloat x, GLfloat y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.11, 0.56, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float rad = i * 3.14159 / 180;
        glVertex2f(cos(rad) * radius + x, sin(rad) * radius + y);
    }
    glEnd();
}

void display(void)
{
    int x = 80;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLineWidth(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
    //glutPostRedisplay();
    drawCircle(500, 400, -250);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}