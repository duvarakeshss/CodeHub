// 2.Parabola
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

class point {
public:
    float x;
    float y;
};

struct vertices {
    float r;
    float a;
    float b;
};

vertices p;
int count = 0;
point arr[100];
int i = 0;

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 300);
}
float x , y;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
        for(float i = -1;i<=1;i+=0.01){
            x = 50 + 50*i;
            y = 100*pow(i,2);
            glVertex3f(x,y,0);
        }

    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("Circle");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
