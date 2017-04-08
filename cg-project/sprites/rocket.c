void drawRocket(float x,float xcor,float ycor) {
    // Rocket body
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.96, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(0.3*x +xcor,2.0*x+ycor);
        glVertex2f(0.3*x +xcor,4.5*x+ycor);
        glVertex2f(0.65*x+xcor,4.5*x+ycor);
        glVertex2f(0.65*x+xcor,2.0*x+ycor);
    glEnd();

    // Rocket head
    glColor3f(0.96, 0.87, 0.70);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.3*x  +xcor,4.5*x+ycor);
        glVertex2f(0.475*x+xcor,5.5*x+ycor);
        glVertex2f(0.65*x +xcor,4.5*x+ycor);
    glEnd();

    // Rocket base
    glBegin(GL_POLYGON);
        glVertex2f(0.25*x+xcor,1.0*x+ycor);
        glVertex2f(0.3*x +xcor,2.0*x+ycor);
        glVertex2f(0.65*x+xcor,2.0*x+ycor);
        glVertex2f(0.7*x +xcor,1.0*x+ycor);
    glEnd();

    // Rocket flames
        
    glColor3f(1.0, 0.64, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.25*x +xcor,1.0*x+ycor);
        glVertex2f(0.0*x  +xcor,0.6*x+ycor);
        glVertex2f(0.475*x+xcor,0.0*x+ycor);
        glVertex2f(0.95*x +xcor,0.6*x+ycor);
        glVertex2f(0.7*x  +xcor,1.0*x+ycor);
    glEnd();

    glColor3f(1.0, 0.27, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.25*x +xcor,1.0*x+ycor);
        glVertex2f(0.2*x  +xcor,0.7*x+ycor);
        glVertex2f(0.475*x+xcor,0.5*x+ycor);
        glVertex2f(0.75*x +xcor,0.7*x+ycor);
        glVertex2f(0.7*x  +xcor,1.0*x+ycor);
    glEnd();
    glFlush();
}