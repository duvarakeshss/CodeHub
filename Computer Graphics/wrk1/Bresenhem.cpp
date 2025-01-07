// DDL line drawing algorithm
#include<windows.h>
#include <iostream>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

using namespace std;

#define SCREENHEIGHT 480

class point {
public:
    float x;
    float y;
};
point arr[100];

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, SCREENHEIGHT);
}

void bresenham(){
    float delx = arr[1].x - arr[0].x;
    float dely = arr[1].y - arr[0].y;
    float delx2 = 2*delx;
    float dely2 = 2*dely;
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex2f(arr[0].x , arr[0].y);
        float pk = dely2 - delx ;
        float x = arr[0].x;
        float y = arr[0].y;
        for(int i = 0 ; i < delx ; i++){
            if(pk < 0){
                x += 1;
                pk = pk + dely2;
            }
            else{
                x += 1;
                y += 1;
                pk = pk + dely2 - delx2 ;
            }
            glVertex2f(x,y);
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham();
    glFlush();
}


int count = 0;
int i = 0;

void HandleMouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (i < 100) {
            arr[i].x = x;
            arr[i].y = SCREENHEIGHT - y;
            cout << "(" << x << " , " << (SCREENHEIGHT - y) << " )" << endl;
            i++;
            count++;
        }

        if (count == 2) {
            glutPostRedisplay();
            count = 0;
            i = 0;
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,SCREENHEIGHT);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("DDA Line Drawing");


    glutDisplayFunc(display);
    init();

    glutMouseFunc(HandleMouse);

    glutMainLoop();

    return 0;
}
