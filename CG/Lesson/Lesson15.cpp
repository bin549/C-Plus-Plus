//程序10-1 Bezier曲线绘制实例
// win32Test.cpp : Defines the entry point for the application.//
#include "stdafx.h"
#include <glut.h>

// The number of control points for this curve
GLint nNumPoints = 4;

//control point group1
GLfloat ctrlPoints[4][3] = {{-4.0f, 0.0f, 0.0f}, // End Point
                            {-6.0f, 4.0f, 0.0f}, // Control Point
                            {6.0f, -4.0f, 0.0f}, // Control Point
                            {4.0f, 0.0f, 0.0f}}; // End Point

void ChangeSize(int w, int h);
void DrawPoints(void);
void RenderScene(void);
void SetupRC();

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine,
                       int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    char *argv[] = {"hello ", " "};
    int argc = 2;                                // must/should match the number of strings in argv
    glutInit(&argc, argv);                       //初始化GLUT库；
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //设置显示模式；（缓冲，颜色类型）
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);
    glutCreateWindow("Bezier Curve"); //创建窗口，标题为“Rotating 3D World”；
    glutReshapeFunc(ChangeSize);
    SetupRC();
    ;
    glutDisplayFunc(RenderScene); //用于绘制当前窗口；
    glutMainLoop();               //表示开始运行程序，用于程序的结尾；

    return 0;
}

void DrawPoints(void)
{
    int i; // Counting variable

    // Set point size larger to make more visible
    glPointSize(5.0f);

    // Loop through all control points for this example
    glBegin(GL_POINTS);
    for (i = 0; i < nNumPoints; i++)
        glVertex2fv(ctrlPoints[i]);
    glEnd();
}

// Called to draw scene
void RenderScene(void)
{
    int i;

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    // Sets up the bezier
    // This actually only needs to be called once and could go in
    // the setup function
    glMap1f(GL_MAP1_VERTEX_3,   // Type of data generated
            0.0f,               // Lower u range
            100.0f,             // Upper u range
            3,                  // Distance between points in the data
            nNumPoints,         // number of control points
            &ctrlPoints[0][0]); // array of control points

    // Enable the evaluator
    glEnable(GL_MAP1_VERTEX_3);

    // Use a line strip to "connect-the-dots"
    glBegin(GL_LINE_STRIP);
    for (i = 0; i <= 100; i++)
    {
        // Evaluate the curve at this point
        glEvalCoord1f((GLfloat)i);
    }
    glEnd();

    // Use higher level functions to map to a grid, then evaluate the
    // entire thing.
    // Put these two functions in to replace above loop

    // Map a grid of 100 points from 0 to 100
    //glMapGrid1d(100,0.0,100.0);

    // Evaluate the grid, using lines
    //glEvalMesh1(GL_LINE,0,100);

    // Draw the Control Points
    DrawPoints();

    // Flush drawing commands
    glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    // Clear Window to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Draw in Blue
    glColor3f(0.0f, 0.0f, 1.0f);
}

///////////////////////////////////////
// Set 2D Projection
void ChangeSize(int w, int h)
{
    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10.0f, 10.0f, -10.0f, 10.0f);
    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
