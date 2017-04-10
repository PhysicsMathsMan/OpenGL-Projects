#include "/home/k0nfig/Documents/openGL-projects/cg-project/sprites/rocket.c"
#include <string.h>
int moderator = 50;
float cur_rand1[55], cur_rand2[55];

void display_string(int x, int y, char *string)
{
    int len, i;
    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
}

void drawStars()
{
    int rand(); // random integers
    // Stars
    int i;
    if (moderator % 50 == 0)
    { // Reduces the no. of times stars are rendered.
        for (i = 1; i <= 50; i++)
        {
            cur_rand1[i] = rand() % 750;
            cur_rand2[i] = rand() % 750; // Stores the points so they can be rendered the same in later calls, till modified.
        }
    }
    glPointSize(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for (i = 1; i < 50; i++)
        glVertex2f(cur_rand1[i], cur_rand2[i]);
    glEnd();
}

void drawScene2()
{
    int i, callcount = 0;
    srand(time(NULL));
    for (int j = 1; j < 550; j++)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glLineWidth(2.0);

        glColor3f(0.53, 0.80, 0.98);
        glBegin(GL_QUADS);
        glVertex2f(0, 50);
        glVertex2f(800, 50);

        glColor3f(0.27, 0.50, 0.70);
        glBegin(GL_QUADS);
        glVertex2f(800, 300);
        glVertex2f(0, 300);
        glVertex2f(800, 300);
        glVertex2f(0, 300);

        glColor3f(0.09, 0.09, 0.47);
        glBegin(GL_QUADS);
        glVertex2f(0, 600);
        glVertex2f(800, 600);
        glVertex2f(0, 600);
        glVertex2f(800, 600);

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex2f(800, 800);
        glVertex2f(0, 800);

        glEnd();
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES); // Draws the scale.
        glVertex2f(750, 50);
        glVertex2f(750, 800);
        glEnd();

        moderator++;
        drawStars();

        // Print the spheres
        glColor3f(0.75, 0.75, 0.75);
        char string1[] = "Troposphere";
        char string2[] = "Stratosphere";
        char string3[] = "Mesosphere";
        char string4[] = "Thermosphere";
        char string5[] = "Exosphere";
        display_string(650, 125, string1);
        display_string(650, 300, string2);
        display_string(650, 450, string3);
        display_string(650, 600, string4);
        display_string(650, 785, string5);

        glColor3f(0.627, 0.32, 0.17);
        glBegin(GL_TRIANGLES);
        glVertex2f(400, 50);
        glVertex2f(450, 100);
        glVertex2f(500, 50);
        glEnd();

        glColor3f(0.12, 0.56, 1.0); // Ocean blue
        glBegin(GL_QUADS);
        glVertex2f(800, 50);
        glVertex2f(800, 0);

        glColor3f(0.8, 0.52, 0.25); // Ground brown
        glBegin(GL_QUADS);
        glVertex2f(450, 0);
        glVertex2f(450, 50);
        glVertex2f(450, 50);
        glVertex2f(450, 0);

        glColor3f(0.13, 0.54, 0.13); // Green ground
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(0, 50);

        glEnd();

        drawRocket(25, 100, 50 + j, callcount++);
        for (double delay = 0; delay <= 1000000; delay++)
            ;
    }
    glFlush();
}

void display2(void)
{
    glClearColor(1.0, 1.0, 0.92, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);

    drawScene2();
    glutPostRedisplay();
}