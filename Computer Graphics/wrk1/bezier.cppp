#include<iostream>
#include<GL/glut.h>
#include<vector>

using namespace std;

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

struct point{
    float x;
    float y;
};

point arr[100];
int i = 0; 

void init(){

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,SCREEN_WIDTH,0,SCREEN_HEIGHT);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_STRIP);
        for(int j = 0 ; j < i ; j++){
            glVertex2f(arr[j].x , arr[j].y);
        }
    glEnd();
    glFlush();
}

void bezier()
{
    if(i < 4) return;

    glColor3f(1, 0, 0); 
    
    
    for(int j = 0 ; j < i ; j+=3){
        
        if(j == i-1) return;
        glBegin(GL_POINTS);
        for(float t = 0; t <= 1; t += 0.01)
        {
            float x = (1 - t) * (1 - t) * (1 - t) * arr[j].x +
                    3 * (1 - t) * (1 - t) * t * arr[j+1].x +
                    3 * (1 - t) * t * t * arr[j+2].x +
                    t * t * t * arr[j+3].x;
            
            float y = (1 - t) * (1 - t) * (1 - t) * arr[j+0].y +
                    3 * (1 - t) * (1 - t) * t * arr[j+1].y +
                    3 * (1 - t) * t * t * arr[j+2].y +
                    t * t * t * arr[j+3].y;
            
            glVertex2f(x, y);
        }
        glEnd();
        glFlush();
        
    }
   
}

void keyboard(unsigned char key , int x , int y){
    if(key == 'd'){
        bezier();
    }
}

void mouse(int button , int state , int x ,int y){
    if(button == GLUT_LEFT_BUTTON && state ==  GLUT_DOWN){
        arr[i].x = x;
        arr[i].y = SCREEN_HEIGHT -  y;
        glBegin(GL_POINTS);
            glVertex2f(arr[i].x , arr[i].y);
        glEnd();
        glFlush();

        cout<<"( "<< arr[i].x <<" , "<<arr[i].y<<" )"<<endl;
        i++;

        glutPostRedisplay();
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        bezier();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("Bezier");


    glutDisplayFunc(display);
    init();

    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
