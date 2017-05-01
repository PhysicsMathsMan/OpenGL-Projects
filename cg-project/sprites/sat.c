void drawSat(int x, int y, float scale)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Body
    glColor3f(226 / 255.0, 226 / 255.0, 72 / 255.0);
    glBegin(GL_QUADS);
    glVertex2f(300.0 * scale, 300.0 * scale);
    glVertex2f(300.0 * scale, 500.0 * scale);
    glVertex2f(500.0 * scale, 500.0 * scale);
    glVertex2f(500.0 * scale, 300.0 * scale);
    glEnd();
    // Connectors
    glColor3f(81 / 255.0, 99 / 255.0, 127 / 255.0);
    glBegin(GL_LINES);
    glVertex2f(500.0 * scale, 400.0 * scale);
    glVertex2f(550.0 * scale, 400.0 * scale);
    glVertex2f(300.0 * scale, 400.0 * scale);
    glVertex2f(250.0 * scale, 400.0 * scale);
    glEnd();
    // Panels
    int tilt = 10;
    glColor3f(29 / 255.0, 92 / 255.0, 193 / 255.0);
    glBegin(GL_QUADS);
    glVertex2f((250.0 - tilt) * scale, 350.0 * scale);
    glVertex2f((250.0 + tilt) * scale, 450.0 * scale);
    glVertex2f((50.0 + tilt) * scale, 450.0 * scale);
    glVertex2f((50.0 - tilt) * scale, 350.0 * scale);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((550.0 - tilt) * scale, 350.0 * scale);
    glVertex2f((550.0 + tilt) * scale, 450.0 * scale);
    glVertex2f((750.0 + tilt) * scale, 450.0 * scale);
    glVertex2f((750.0 - tilt) * scale, 350.0 * scale);
    glEnd();

    glFlush();
}