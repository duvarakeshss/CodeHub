// 1. Circle Drawing
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
        float radius = p.r;

        for (GLfloat theta = 0; theta < 360; theta ++) {
            GLfloat x = p.a + (radius * cos(theta));
            GLfloat y = p.b + (radius * sin(theta));
            glVertex3f(x, y,0);
        }

    glEnd();
    glFlush();
}

void Calradius() {
    if (count == 2) {
        p.r = sqrt(pow(arr[1].x - arr[0].x, 2) + pow(arr[1].y - arr[0].y, 2));
        cout << "Radius: " << p.r << endl;
        glutPostRedisplay();
    }
}
bool mouseHandlingEnabled = true;
void HandleMouse(int button, int state, int x, int y) {

    if(!mouseHandlingEnabled){
        return;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (i < 100) {
            arr[i].x = x;
            arr[i].y = y;
            cout << "(" << x << " , " << (screen_height - y) << " )" << endl;
            count++;
            i++;
        }
    }

    if (count == 2) {
        cout << count << endl;
        p.a = arr[0].x;
        p.b = arr[0].y;
        mouseHandlingEnabled = false;
        Calradius();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("Circle");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(HandleMouse);

    glutMainLoop();
    return 0;
}
