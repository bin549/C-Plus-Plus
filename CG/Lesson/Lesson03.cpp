#include "stdafx.h"
#include <glut.h>

void display(void);
void myreshape(GLsizei w, GLsizei h);
void mykeyboard(unsigned char key, int x, int y);
float x1 = -0.5, y1 = -0.5, x2 = 0.5, y2 = 0.5;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine,
                       int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    char *argv[] = {"hello ", " "};
    int argc = 2; // must/should match the number of strings in argv

    glutInit(&argc, argv);                       //初始化GLUT库；
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //设置显示模式；（缓冲，颜色类型）
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);
    glutCreateWindow("Hello"); //创建窗口，标题为“hello”；
    glutDisplayFunc(display);  //用于绘制当前窗口；
    glutKeyboardFunc(mykeyboard);
    //  glutReshapeFunc(myreshape);
    glutMainLoop(); //表示开始运行程序，用于程序的结尾；

    return 0;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //刷新颜色缓冲区
    glColor3f(1, 1, 1);
    glRectf(x1, y1, x2, y2);
    glColor3f(1, 0, 0);
    glRasterPos2i((x1 + x2) / 2, (y1 + y2) / 2);
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'H');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'l');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'l');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'o');
    glFlush(); //用于刷新命令队列和缓冲区，使所有尚未被执行的OpenGL命令得到执行
}

void myreshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 300, 0, 300);
}

void mykeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        y1 += 0.1, y2 += 0.1;
        break;
    case 'S':
    case 's':
        y1 -= 0.1, y2 -= 0.1;
        break;
    case 'A':
    case 'a':
        x1 -= 0.1, x2 -= 0.1;
        break;
    case 'D':
    case 'd':
        x1 += 0.1, x2 += 0.1;
        break;
    }
    glutPostRedisplay();
}
