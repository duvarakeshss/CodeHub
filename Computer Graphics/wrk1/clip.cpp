// MidPoint Circle drwaing algorithm

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

int count = 0;
int i = 0;

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, SCREENHEIGHT);
}


void DrawWindow(){
    glBegin(GL_LINE_LOOP);
        glVertex2f(arr[0].x,arr[0].y);
        glVertex2f(arr[1].x,arr[0].y);
        glVertex2f(arr[1].x,arr[1].y);
        glVertex2f(arr[0].x,arr[1].y);
    glEnd();


}

void DrawLine(){
    glBegin(GL_LINES);
        for(int j = 2 ; j < count ; j++){
            glVertex2f(arr[j].x,arr[j].y);
        }
    glEnd();


}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1 , 0 ,1);
        DrawWindow();
        if(count > 2){
            DrawLine();

        }

    glFlush();
}
void HandleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (i < 100) {
            arr[i].x = x;
            arr[i].y = SCREENHEIGHT - y;
            cout << "(" << x << " , " << (SCREENHEIGHT - y) << " )" << endl;
            i++;
            count++;
        }

        if (count % 2 == 0 && count !=0) {
            glutPostRedisplay();
        }
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,SCREENHEIGHT);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("Midpoint circle drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(HandleMouse);
    glutMainLoop();
    return 0;
}
