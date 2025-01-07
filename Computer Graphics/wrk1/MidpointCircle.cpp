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

void plot(float x , float y , float a , float b ){
    glBegin(GL_POINTS);
        glVertex2f(a+x,b+y);
        glVertex2f(a+x,b-y);
        glVertex2f(a-x,b+y);
        glVertex2f(a-x,b-y);
        glVertex2f(a+y,b+x);
        glVertex2f(a+y,b-x);
        glVertex2f(a-y,b+x);
        glVertex2f(a-y,b-x);
    glEnd();
    glFlush();
}

void Drawcircle(){
    
    float radius = sqrt(pow(arr[1].x - arr[0].x, 2) + pow(arr[1].y - arr[0].y, 2));
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex2f( arr[0].x , arr[0].y+radius);
        float pk = 1 - radius ;
        float x = x;
        float y = radius;

        while(x <= y){
            x += 1;

            if(pk < 0){
                y += 0;
                pk += 2*x + 1 ;
            }
            else{
                y -=1 ;
                pk += (2*x - 2*y) +3;
            }
            plot(x , y, arr[0].x , arr[0].y);
        }
        
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Drawcircle();
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

        if (count == 2) {
            cout << "2 points available";
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
    glutCreateWindow("Midpoint circle drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(HandleMouse);
    glutMainLoop();
    return 0;
}
