//鼠标画线小程序
#include "stdafx.h"
#include <glut.h>

#define N 1000         //maximum line numbers
int ww, hh;            // for display window width and height
int line[N][4], k = 0; //for line's endpoint coordinates and line number

void Myinit(void);
void Reshape(int w, int h);
void myMouse(int button, int state, int x, int y);
void myMotion(int x, int y);
void Display(void);
void drawlines();

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
    glutInitWindowSize(800, 600);                //设置显示窗口大小
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //设置显示模式；（注意双缓冲）
    glutCreateWindow("鼠标画线小程序演示");      // 创建显示窗口
    Myinit();
    glutDisplayFunc(Display); //注册显示回调函数
    glutMouseFunc(myMouse);   //注册鼠标按钮回调函数
    glutMotionFunc(myMotion); //注册鼠标移动回调函数
    glutReshapeFunc(Reshape); //注册窗口改变回调函数
    glutMainLoop();           //进入事件处理循环
    return 0;
}

void Myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLineWidth(3.0);
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //刷新颜色缓冲区；
    drawlines();                  //画线子程序；
    glutSwapBuffers();            //双缓冲的刷新模式；
}

void Reshape(int w, int h) //窗口改变时自动获取显示窗口的宽w和高h
{
    glMatrixMode(GL_PROJECTION); //投影矩阵模式
    glLoadIdentity();            //矩阵堆栈清空
    glViewport(0, 0, w, h);      //设置视区大小
    gluOrtho2D(0, w, 0, h);      //设置裁剪窗口大小
    ww = w;
    hh = h;
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        line[k][0] = x;      //线段起点x坐标
        line[k][1] = hh - y; //线段终点y坐标
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        line[k][2] = x;      //线段起点x坐标
        line[k][3] = hh - y; //线段终点y坐标
        k++;
        glutPostRedisplay();
    }
}

void myMotion(int x, int y)
{
    //get the line's motion point
    line[k][2] = x;      //动态终点的x坐标
    line[k][3] = hh - y; //动态终点的y坐标
    glutPostRedisplay();
}

void drawlines()
{
    for (int i = 0; i <= k; i++) //********
    {
        glBegin(GL_LINES);
        glVertex2f(line[i][0], line[i][1]);
        glVertex2f(line[i][2], line[i][3]);
        glEnd();
    }
}

//裁剪线段子函数
void clipLine(Point2D winMin, Point2D winMax, Point2D p1, Point2D p2)
//裁剪窗口左下角，右上角， 直线段起始点，终止点
{
    float u1 = 0.0, u2 = 1.0, dx = p2.x - p1.x, dy;
    if (clipTest(-dx, p1.x - winMin.x, &u1, &u2))
        if (clipTest(dx, winMax.x - p1.x, &u1, &u2))
        {
            dy = p2.y - p1.y;
            if (clipTest(-dy, p1.y - winMin.y, &u1, &u2))
                if (clipTest(dy, winMax.y - p1.y, &u1, &u2))
                {
                    if (u2 < 1.0)
                    {
                        p2.x = p1.x + u2 * dx;
                        p2.y = p1.y + u2 * dy;
                    }
                    if (u1 > 0.0)
                    {
                        p1.x += u1 * dx;
                        p1.y += u1 * dy;
                    }
                    line DDA(ROUND(p1.x), ROUND(p1.y), ROUND(p2.x), ROUND(p2.y));
                }
        }
}

//判断是否需要裁减子函数
int clipTest(float p, float q, float *u1, float *u2)
{
    float r;
    int retVal = TRUE;
    if (p < 0.0)
    {
        r = q / p;
        if (r > *u2)
            retVal = FALSE;
        else if (r > *u1)
            *u1 = r;
    }
    else if (p > 0.0)
    {
        r = q / p;
        if (r < *u1)
            retVal = FALSE;
        else if (r < *u2)
            *u2 = r;
    }
    Else /* p = 0, so line is parallel to this clipping edge */
        if (q < 0.0)
        /* Line is outside clipping edge */
        retVal = FALSE;
    return (retVal);
} //裁剪线段子函数

void LBLineClip(float xleft, float xright, float ybottom, float ytop, float x1, float y1, float x2, float y2)
{
    float u1 = 0.0, u2 = 1.0;
    float deltax = x2 - x1, deltay = y2 - y1;
    if (LBclipTest(-deltax, x1 - xleft, u1, u2))
    {
        if (LBclipTest(deltax, xright - x1, u1, u2))
        {
            deltay = y2 - y1;
            if (LBclipTest(-deltay, y1 - ybottom, u1, u2))
            {
                if (LBclipTest(deltay, ytop - y1, u1, u2))
                {
                    if (u2 < 1.0)
                    {
                        x2 = x1 + u2 * deltax;
                        y2 = y1 + u2 * deltay;
                    }
                    if (u1 > 0.0)
                    {
                        x1 = x1 + u1 * deltax;
                        y1 = y1 + u1 * deltay;
                    }

                    glBegin(GL_LINES);
                    glVertex2f(x1, y1);
                    glVertex2f(x2, y2);
                    glEnd();
                }
            }
        }
    }
}
//判断是否需要裁减子函数
bool LBclipTest(float p, float q, float &u1, float &u2)
{
    float u;
    bool Cliptest = true;
    if (p > 0.0)
    {
        u = q / p;
        if (u < u1)
        {
            Cliptest = false;
        }
        else if (u < u2)
        {
            u2 = u;
        }
    }
    else if (p < 0.0)
    {
        u = q / p;
        if (u > u2)
        {
            Cliptest = false;
        }
        else if (u > u1)
        {
            u1 = u;
        }
    }
    else
    {
        if (q < 0.0)
        {
            Cliptest = false;
        }
    }
    return Cliptest;
}

class wcPt2D
{
public:
    float x, y;
};

GLubyte encode(wcPt2D pt, wcPt2D winMin, wcPt2D winMax);
void swapPts(wcPt2D *p1, wcPt2D *p2);
void swapCodes(GLubyte *c1, GLubyte *c2);
void lineClipCohSuth(wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2);

/*  Define a four-bit code…*/
const GLint winLeftBitCode = 0x1;
const GLint winRightBitCode = 0x2;
const GLint winBottomBitCode = 0x4;
const GLint winTopBitCode = 0x8;
inline GLint inside(GLint code) { return GLint(!code); }
inline GLint reject(GLint code1, GLint code2) { return GLint(code1 & code2); }
inline GLint accept(GLint code1, GLint code2) { return GLint(!(code1 | code2)); }

GLubyte encode(wcPt2D pt, wcPt2D winMin, wcPt2D winMax)
{
    GLubyte code = 0x00;
    if (pt.x < winMin.x)
        code = code | winLeftBitCode;
    if (pt.x > winMax.x)
        code = code | winRightBitCode;
    if (pt.y < winMin.y)
        code = code | winBottomBitCode;
    if (pt.y > winMax.y)
        code = code | winTopBitCode;
    return (code);
}

void swapPts(wcPt2D *p1, wcPt2D *p2)
{
    wcPt2D tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swapCodes(GLubyte *c1, GLubyte *c2)
{
    GLubyte tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void lineClipCohSuth(wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2)
{
    GLubyte code1, code2;
    GLint done = false, plotLine = false;
    GLfloat m;
    while (!done)
    {
        code1 = encode(p1, winMin, winMax);
        code2 = encode(p2, winMin, winMax);
        if (accept(code1, code2))
        {
            done = true;
            plotLine = true;
        }
        else if (reject(code1, code2))
            done = true;
        else
        {
            /* Label the point outside the window as p1*/
            if (inside(code1))
            {
                swapPts(&p1, &p2);
                swapCodes(&code1, &code2);
            }
            if (p2.x != p1.x)
                m = (p2.y - p1.y) / (p2.x - p1.x);
            if (code1 & winLeftBitCode)
            {
                p1.y += (winMin.x - p1.x) * m;
                p1.x = winMin.x;
            }
            else if (code1 & winRightBitCode)
            {
                p1.y += (winMax.x - p1.x) * m;
                p1.x = winMax.x;
            }
            else if (code1 & winBottomBitCode)
            {
                /*Need to update p1.x for nonvertical lines only*/
                if (p2.x != p1.x)
                    p1.x += (winMin.y - p1.y) / m;
                p1.y = winMin.y;
            }
            else if (code1 & winTopBitCode)
            {
                if (p2.x != p1.x)
                    p1.x += (winMax.y - p1.y) / m;
                p1.y = winMax.y;
            }
        } //for else;
    }     // for while;
    if (plotLine)
        glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
} //  for linelipCohSuth();
