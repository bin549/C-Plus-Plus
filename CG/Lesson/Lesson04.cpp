#include "stdafx.h"
#include <gl/glut.h>
#include <math.h>

#define N 1000
int ww, hh;
int line[N][4], k = 0;

void Myinit(void);
void Reshape(int w, int h);
void Display(void);
void myMouse(int button, int state, int x, int y);
void myMotion(int x, int y);
void drawPoints();

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine,
                       int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    char *argv[] = {(char *)"hello ", (char *)" "};
    int argc = 2;

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("A Rotating Square");
    Myinit();
    glutDisplayFunc(Display);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}

void Myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLineWidth(3.0);
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawPoints();
    glutSwapBuffers();
}

void Reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluOrtho2D(0, w, 0, h);
    ww = w;
    hh = h;
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        line[k][0] = x;
        line[k][1] = hh - y;
        k++;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        line[k][2] = x;
        line[k][3] = hh - y;
        k++;
        glutPostRedisplay();
    }
}

void myMotion(int x, int y)
{
    line[k][2] = x;
    line[k][3] = hh - y;
    k++;
    glutPostRedisplay();
}

void drawPoints()
{
    //glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= k; i++)
    {
        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex3f(line[i][0], line[i][1], 0);
        glVertex3f(line[i][2], line[i][3], 0);
        glEnd();
        //glVertex2f(points[i][0],points[i][1]);
    }
}