#include <GL/freeglut.h>
#include <cstdio>
#include <iostream>
using namespace std;


class Tile {
    private:
        float x;
        float y;
        float width;
        float height;
        float r;
        float g;
        float b;
        GLfloat theta;
    public:
        void renderTile();   
        Tile(float x, float y, float width, float height, float r, float g, float b) {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
            this->r = r;
            this->g = g;
            this->b = b;
            fprintf(stdout, "All is good!");
        }     
};

void Tile::renderTile() {
    
    fprintf(stdout, "Tile::renderTile() called");
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(this->x, this->y);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(this->x + this->width, this->y);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(this->x + this->width, this->y + this->height);
    glColor3f(1.0f, 0.0f, 0.0f);    
    glVertex2f(this->x, this->y + this->height);
    glEnd();

}

void setupDisplay() {
    // Clear the screen and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // TODO: Figure out what this line does exactly - saw it mentioned in a tutorial
    glLoadIdentity();

    // Create 4 tiles
    Tile *tile1 = new Tile(-1.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f);
    Tile *tile3 = new Tile(0.0f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f);
    Tile *tile4 = new Tile(0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);

    // Render the tiles
    tile1->renderTile();
    tile2->renderTile();
    tile3->renderTile();
    tile4->renderTile();
    
    // Do the things
    glFlush();
}

int main(int argc, char* argv[]) {
    cout << "Hello?";

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