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
    glColor3f(this->r, this->g, this->b);
    glVertex2f(this->x, this->y);
    glVertex2f(this->x + this->width, this->y);
    glVertex2f(this->x + this->width, this->y + this->height);
    glVertex2f(this->x, this->y + this->height);
    glEnd();

}

void setupDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    // glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f); // Red
    // glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
    //   glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
    //   glVertex2f(-0.2f, 0.7f);
    //   glVertex2f(-0.8f, 0.7f);
    // glEnd();

    // glFlush();
    Tile* map = new Tile[4];
    Tile *tile1 = new Tile(-1.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f);
    Tile *tile3 = new Tile(0.0f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f);
    Tile *tile4 = new Tile(0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);

    tile1->renderTile();
    tile2->renderTile();
    tile3->renderTile();
    tile4->renderTile();
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);
    // Tile *tile2 = new Tile(-0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f);


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

    // Clear the window
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();
    return 0;
}