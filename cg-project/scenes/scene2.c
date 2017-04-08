#include "/home/k0nfig/Documents/openGL-projects/cg-project/sprites/rocket.c"

void drawScene2() {
    for (int i = 1; i < 550; i++) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glLineWidth(2.0);
        glBegin(GL_LINES); // Draws the scale.
        glVertex2f(750, 50);
        glVertex2f(750, 800);
        glEnd();
        glColor3f(0.46, 0.46, 0.46);
        char string1[] = "Troposphere";
        char string2[] = "Stratosphere";
        char string3[] = "Mesosphere";
        char string4[] = "Thermosphere";
        char string5[] = "Exosphere";
        for (i = 0; i < 15; i++) {
            if (i <= 11 == 1)
             {
                glRasterPos2f(600 + i * 12, 125);
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string1[i]);
            }
            if (i <= 12 == 1) {
                glRasterPos2f(600 + i * 12, 300);
                glutBitmapCharacter( GLUT_BITMAP_HELVETICA_10 , string2[i]);
            }
            if (i <= 10 == 1) {
                glRasterPos2f(600 + i * 12, 450);
                glutBitmapCharacter( GLUT_BITMAP_HELVETICA_10 , string3[i]);
            }
            if (i <= 12 == 1) {
                glRasterPos2f(600 + i * 12, 600);
                glutBitmapCharacter( GLUT_BITMAP_HELVETICA_10 , string4[i]);
            }
            if (i <= 9 == 1) {
                glRasterPos2f(600 + i * 12, 785);
                glutBitmapCharacter( GLUT_BITMAP_HELVETICA_10 , string5[i]);
            }
            if(i>12)
                break;
        }
        drawRocket(30, 100, 50 + i);
        for (double delay = 0; delay <= 1000000; delay++);
    }
    glFlush();
}

void display2(void) {
    glClearColor(1.0, 1.0, 0.92, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
    drawScene2();
    //glutPostRedisplay();
}