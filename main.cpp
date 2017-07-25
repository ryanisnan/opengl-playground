#include <GL/freeglut.h>
#include <cstdio>
#include <iostream>
using namespace std;


void setupDisplay() {
    // Clear the screen and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // TODO: Figure out what this line does exactly - saw it mentioned in a tutorial
    glLoadIdentity();

    // Draw stuff
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
    
    // Do the things
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    
    // Set up the window
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Fucking cool");
    glutDisplayFunc(setupDisplay);

    // Main glut loop
    glutMainLoop();
    return 0;
}