#include "pch.h"
#include "framework.h"
#include "2DSunSystem.h"
#include <GL/glut.h>
#include <math.h>

float PI = 3.1415926f;

int rs = 80, re = 40, rm = 10;
int dse = 180, dsm = 250;

int as = 0, ae = 0, am = 0;
int rse = 0, rem = 0, rsm = 0;

void Display(void);
void Reshape(int w, int h);
void mytime(int value);
void myinit(void);

void sun();
void earth();
void moon();

void selectFont(int size, int charset, const char *face); //选择字体
void drawCNString(const char *str);                       //生成中文字体函数

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine,
                       int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    char *argv[] = {(char *)"hello ", (char *)" "};
    int argc = 2;                                // must/should match the number of strings in argv
    glutInit(&argc, argv);                       //初始化GLUT库；
    glutInitWindowSize(700, 700);                //设置显示窗口大小
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //设置显示模式；（注意双缓冲）
    glutCreateWindow("A Rotating Sun System");   // 创建显示窗口
    glutDisplayFunc(Display);                    //注册显示回调函数
    glutReshapeFunc(Reshape);                    //注册窗口改变回调函数
    myinit();
    glutTimerFunc(200, mytime, 10);
    glutMainLoop(); //进入事件处理循环
    return 0;
}

void myinit()
{
    glLineWidth(8);
    glPointSize(12);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //设置矩阵模式为模型变换模式，表示在世界坐标系下
    glLoadIdentity();           //将当前矩阵设置为单位矩阵
    sun();
    earth();
    moon();
    glutSwapBuffers(); //双缓冲的刷新模式；
}

void mytime(int value)
{
    as++;
    ae++;
    am++;

    rse += 2;
    rsm += 2;
    rem += 2;

    glutPostRedisplay(); //重画，相当于10重新调用Display(),改编后的变量得以传给绘制函数

    glutTimerFunc(200, mytime, 10);
}

void sun()
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glRotatef(as, 0, 0, 1);
    glutWireSphere(rs, 30, 30);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    glVertex2f(rs, 0);
    glEnd();

    selectFont(36, GB2312_CHARSET, "楷体_GB2312");
    glRasterPos2f(0, 0);
    drawCNString("太阳");

    glPopMatrix();
}

void earth()
{
    glPushMatrix();
    glColor3f(0, 0, 1);

    glRotatef(rse, 0, 0, 1);

    glTranslatef(dse, 0, 0);
    glRotatef(ae, 0, 0, 1);
    glTranslatef(-dse, 0, 0);

    glTranslatef(dse, 0, 0);
    glutWireSphere(re, 30, 30);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    glVertex2f(re, 0);
    glEnd();
    selectFont(16, GB2312_CHARSET, "楷体_GB2312");
    glRasterPos2f(0, 0);
    drawCNString("地球");
    glPopMatrix();
}

void moon()
{
    glPushMatrix();
    glColor3f(1, 1, 1);

    glRotatef(rsm, 0, 0, 1);

    glTranslatef(dse, 0, 0);
    glRotatef(rem, 0, 0, 1);
    glTranslatef(-dse, 0, 0);

    glTranslatef(dsm, 0, 0);
    glRotatef(rsm, 0, 0, 1);
    glTranslatef(-dsm, 0, 0);

    glTranslatef(dsm, 0, 0);
    glutWireSphere(rm, 30, 30);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    glVertex2f(rm, 0);
    glEnd();

    selectFont(14, GB2312_CHARSET, "楷体_GB2312");
    glRasterPos2f(0, 0);
    drawCNString("月亮");

    glPopMatrix();
}

void Reshape(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION); //投影矩阵模式
    glLoadIdentity();            //矩阵堆栈清空
    glViewport(0, 0, w, h);      //设置视区大小

    gluOrtho2D(-(dsm + rm + 2 * rm), (dsm + rm + 2 * rm), -(dsm + rm + 2 * rm), (dsm + rm + 2 * rm)); //设置裁剪窗口大小
    glMatrixMode(GL_MODELVIEW);                                                                       //模型矩阵模式
}

void selectFont(int size, int charset, const char *face)
{
    HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
                              charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                              DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
    HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
    DeleteObject(hOldFont);
}

void drawCNString(const char *str)
{
    int len, i;
    wchar_t *wstring;
    HDC hDC = wglGetCurrentDC();
    GLuint list = glGenLists(1);
    len = 0;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (IsDBCSLeadByte(str[i]))
            ++i;
        ++len;
    }
    wstring = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
    wstring[len] = L'\0';

    for (i = 0; i < len; ++i)
    {
        wglUseFontBitmapsW(hDC, wstring[i], 1, list);
        glCallList(list);
    }

    free(wstring);
    glDeleteLists(list, 1);
}