#include "stdafx.h"
#include <GL/glut.h>

void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //设置清屏颜色
    glClear(GL_COLOR_BUFFER_BIT);         //刷新颜色缓冲区；

    glColor3f(1, 1, 1);
    glRectf(0, 0, 0.2, 0.2);
    glColor3f(1, 0, 0);
    glRectf(0.2, 0, 0.6, 0.2);

    glColor3f(0, 0, 1);
    
    glBegin(GL_TRIANGLES);
        glVertex2f(0, 0.2);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.1, 0.4);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.1, 0.4);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.5, 0.4);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.1, 0.0);
        glVertex2f(0.1, 0.08);
        glVertex2f(0.12, 0.0);
        glVertex2f(0.12, 0.08);
        glVertex2f(0.08, 0.0);
        glVertex2f(0.08, 0.08);
        glVertex2f(0.08, 0.08);
        glVertex2f(0.12, 0.08);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.3, 0.14);
        glVertex2f(0.3, 0.18);
        glVertex2f(0.32, 0.14);
        glVertex2f(0.32, 0.18);
        glVertex2f(0.34, 0.14);
        glVertex2f(0.34, 0.18);
        glVertex2f(0.3, 0.14);
        glVertex2f(0.34, 0.14);
        glVertex2f(0.3, 0.16);
        glVertex2f(0.34, 0.16);
        glVertex2f(0.3, 0.18);
        glVertex2f(0.34, 0.18);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.44, 0.14);
        glVertex2f(0.44, 0.18);
        glVertex2f(0.46, 0.14);
        glVertex2f(0.46, 0.18);
        glVertex2f(0.48, 0.14);
        glVertex2f(0.48, 0.18);
        glVertex2f(0.44, 0.14);
        glVertex2f(0.48, 0.14);
        glVertex2f(0.44, 0.16);
        glVertex2f(0.48, 0.16);
        glVertex2f(0.44, 0.18);
        glVertex2f(0.48, 0.18);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-0.1, 0.04);
        glVertex2f(-0.1, 0.1);
        glVertex2f(-0.12, 0);
        glVertex2f(-0.1, 0.04);
        glVertex2f(-0.08, 0);
        glVertex2f(-0.1, 0.04);
        glVertex2f(-0.12, 0.04);
        glVertex2f(-0.1, 0.08);
        glVertex2f(-0.08, 0.04);
        glVertex2f(-0.1, 0.08);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.12, 0.1);
        glVertex2f(-0.08, 0.1);
        glVertex2f(-0.08, 0.14);
        glVertex2f(-0.12, 0.14);
    glEnd();

    glFlush(); //用于刷新命令队列和缓冲区，使所有尚未被执行的OpenGL命令得到执行；
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine,
                       int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    char *argv[] = {(char *)"hello ", (char *)" "};
    int argc = 2; // must/should match the number of strings in argv

    glutInit(&argc, argv);                                 //初始化GLUT库；
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           //设置显示模式；（缓冲，颜色类型）
    glutInitWindowSize(500, 500);                          //绘图窗口大小
    glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250); //窗口左上角在屏幕的位置
    glutCreateWindow("hello");                             //创建窗口，标题为“hello”；
    glutDisplayFunc(display);                              //用于绘制当前窗口；
    glutMainLoop();                                        //表示开始运行程序，用于程序的结尾；
    return 0;
}