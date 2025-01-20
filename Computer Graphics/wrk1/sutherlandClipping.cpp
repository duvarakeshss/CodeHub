// MidPoint Circle drwaing algorithm

// #include<windows.h>
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
float xw_min,xw_max,yw_min,yw_max;
enum { INSIDE, LEFT, RIGHT, BOTTOM, TOP };

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, SCREENHEIGHT);
}

void windowBoundry(){
    xw_min = min(arr[0].x,arr[1].x);
    xw_max = max(arr[0].x,arr[1].x);
    yw_min = min(arr[0].y , arr[1].y);
    yw_max = max(arr[0].y , arr[1].y);
}

int RegionCode(point p){
    int code = INSIDE;
    
    if (p.x < xw_min)       code |= LEFT;
    else if (p.x > xw_max)  code |= RIGHT;
    
    if (p.y < yw_min)       code |= BOTTOM;
    else if (p.y > yw_max)  code |= TOP;

    return code;
}


void CohenSutherlandClip(point &p1, point &p2){
    int code1 = RegionCode(p1);
    int code2 = RegionCode(p2);
    bool accept = false;

    while (true) {
        if ((code1 == INSIDE) && (code2 == INSIDE)) {
            
            accept = true;
            break;
        } else if (code1 & code2) {
            
            break; 
        } else {
            int code_out;
            float x, y;

            
            if (code1 != INSIDE) {
                code_out = code1;
            } else {
                code_out = code2;
            }

            
            if (code_out & TOP) {
                x = p1.x + (p2.x - p1.x) * (yw_max - p1.y) / (p2.y - p1.y);
                y = yw_max;
            } else if (code_out & BOTTOM) {
                x = p1.x + (p2.x - p1.x) * (yw_min - p1.y) / (p2.y - p1.y);
                y = yw_min;
            } else if (code_out & RIGHT) {
                y = p1.y + (p2.y - p1.y) * (xw_max - p1.x) / (p2.x - p1.x);
                x = xw_max;
            } else { 
                y = p1.y + (p2.y - p1.y) * (xw_min - p1.x) / (p2.x - p1.x);
                x = xw_min;
            }

            
            if (code_out == code1) {
                p1.x = x; 
                p1.y = y; 
                code1 = RegionCode(p1);
            } else {
                p2.x = x; 
                p2.y = y; 
                code2 = RegionCode(p2);
            }
        }
    }
    if (accept) {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glEnd();
        glFlush();
    }

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
        for(int j = 2 ; j < count ; j+=2){
            glVertex2f(arr[j].x,arr[j].y);
            glVertex2f(arr[j+1].x,arr[j+1].y);
            CohenSutherlandClip(arr[j],arr[j+1]);
        }
    glEnd();


}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1 , 1 ,1);
        DrawWindow();
        if(count >= 2){
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
        if(count == 2){
            windowBoundry();
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
    glutCreateWindow("Clipping Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(HandleMouse);
    glutMainLoop();
    return 0;
}
