void drawSat(float x, float y, float scale)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Body
    glColor3f(226 / 255.0, 226 / 255.0, 72 / 255.0);
    glBegin(GL_QUADS);
    glVertex2f(x * scale, y * scale);
    glVertex2f(x * scale, (y + 200.0) * scale);
    glVertex2f((x + 200.0) * scale, (y + 200.0) * scale);
    glVertex2f((x + 200.0) * scale, y * scale);
    glEnd();
    // Connectors
    glColor3f(81 / 255.0, 99 / 255.0, 127 / 255.0);
    glBegin(GL_LINES);
    glVertex2f((x + 200.0) * scale, (y + 100.0) * scale);
    glVertex2f((x + 250.0) * scale, (y + 100.0) * scale);
    glVertex2f(x * scale, (y + 100.0) * scale);
    glVertex2f((x - 50.0) * scale, (y + 100.0) * scale);
    glEnd();
    // Panels
    int tilt = 10;
    glColor3f(29 / 255.0, 92 / 255.0, 193 / 255.0);
    glBegin(GL_QUADS);
    glVertex2f((x - 50.0 - tilt) * scale, (y + 50.0) * scale);
    glVertex2f((x - 50.0 + tilt) * scale, (y + 150.0) * scale);
    glVertex2f((x - 250.0 + tilt) * scale, (y + 150.0) * scale);
    glVertex2f((x - 250.0 - tilt) * scale, (y + 50.0) * scale);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((x + 250.0 - tilt) * scale, (y + 50.0) * scale);
    glVertex2f((x + 250.0 + tilt) * scale, (y + 150.0) * scale);
    glVertex2f((x + 450.0 + tilt) * scale, (y + 150.0) * scale);
    glVertex2f((x + 450.0 - tilt) * scale, (y + 50.0) * scale);
    glEnd();

    glFlush();
}