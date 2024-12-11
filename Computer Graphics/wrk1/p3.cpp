// 3.Sine Wave 
#include <windows.h>
#include <iostream>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
using namespace std;

#define screen_height 300
#define screen_width 800

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-M_PI, M_PI, -1.5, 1.5);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
        GLfloat step = 0.01f;
        for (GLfloat x = -M_PI; x <= M_PI; x += step) {
            GLfloat y = sin(x);
            glVertex3f(x, y,0);
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(screen_width, screen_height);
    glutCreateWindow("Sine Wave");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
