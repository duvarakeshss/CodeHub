// DDL line drawing algorithm

#include <iostream>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

using namespace std;

#define SCREENHEIGHT 300

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
    gluOrtho2D(0, 400, 0, SCREENHEIGHT);
}

void ddaLineDrawing() {
    glBegin(GL_POINTS);
    
    float delX = arr[1].x - arr[0].x;
    float delY = arr[1].y - arr[0].y;
    float steps;
    
    if (fabs(delX) > fabs(delY)) {
        steps = fabs(delX);
    } else {
        steps = fabs(delY);
    }
    
    float Xinc = delX / steps;
    float Yinc = delY / steps;
    float x = arr[0].x;
    float y = arr[0].y;

    
    glVertex2f(arr[0].x, arr[0].y);
    
    for (int i = 0; i < steps; i++) {
        x += Xinc;
        y += Yinc;
        glVertex2f(round(x), round(y));
    }


    glVertex2f(arr[1].x, arr[1].y);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    ddaLineDrawing();
    glFlush();
}

bool mouseHandlingEnabled = true;
int count = 0;
int i = 0;

void HandleMouse(int button, int state, int x, int y) {
    if (!mouseHandlingEnabled) {
        return;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (i < 100) {
            arr[i].x = x;
            arr[i].y = SCREENHEIGHT - y; 
            cout << "(" << x << " , " << (screen_height - y) << " )" << endl;
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
    glutInitWindowPosition(80, 80);
    glutCreateWindow("DDA Line Drawing");
    
    glutDisplayFunc(display);
    init();
    
    glutMouseFunc(HandleMouse);

    glutMainLoop();
    
    return 0; 
}
