#include <GL/freeglut.h>
#include <cstdio>
#include <iostream>
using namespace std;


void setupDisplay() {
    // Clear the screen and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Draw stuff
    glBegin(GL_QUADS);
    
    glColor3f(0.0f, 1.0f, 0.0f); // Green face
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);

    glEnd();
    // glTranslatef(0.0f, 0.0f, -2.0f);
    // Do the things
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    	
    glShadeModel(GL_SMOOTH);

    // Set up the window
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Fucking cool");
    glutDisplayFunc(setupDisplay);

    // Main glut loop
    glutMainLoop();
    return 0;
}