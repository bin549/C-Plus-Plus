// 3D_Basic.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "3D_Basic.h"
#include <Windows.h>
#include <gl/glut.h>

int flag = 0;

//GLfloat vertices[][3]={{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0},{-1.0,-1.0,-1.0},
//{-1.0,1.0,-1.0},{1.0,1.0,-1.0},{1.0,-1.0,-1.0}};

GLfloat vertices[][3] = {{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0}, {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}};

GLfloat colors[][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, {0.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};

static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;

void reshape(int w, int h);
void init();
void display();
void mouse(int btn, int state, int x, int y);
void polygon(int a, int b, int c, int d);
void colorcube(void);
void spinCube();

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR lpCmdLine,
					   int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	char *argv[] = {"hello ", " "};
	int argc = 2; // must/should match the number of strings in argv

	glutInit(&argc, argv); //初始化GLUT库；
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	glutCreateWindow("colorcube");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
	//gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//flag = 0;
	//colorcube();  //绘制彩色立方体

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//flag = 1;
	//colorcube();  //绘制彩色立方体

	glColor3f(0, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.6, 0);
	glRotated(90, 1, 0, 0);
	glutWireTorus(0.3, 0.8, 30, 30); //线框模式
	glPopMatrix();

	glutWireTeapot(0.5);

	glutSwapBuffers();
}

void init()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(3);
}

void polygon(int a, int b, int c, int d)
{
	/* draw a polygon via list of vertices */
	if (flag == 0)
	{
		glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
		glVertex3fv(vertices[d]);
		glEnd();
	}
	else
	{
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
		glEnd();
	}
}

void colorcube(void)
{
	/*  map  vertices to faces  */
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//定义正交投影观察体
	/*if (w <= h)
		glOrtho(-2.0, 2.0, -2.0*(GLfloat)h / (GLfloat)w, 2.0 *(GLfloat)h / (GLfloat)w, 1.0, 20.0);
	else
		glOrtho(-2.0*(GLfloat)w / (GLfloat)h, 2.0*(GLfloat)w / (GLfloat)h, -2.0, 2.0, 1.0, 20.0);*/

	gluPerspective(120, w / h, 1, 60); //定义透视投影投影观察体
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spinCube()
{
	theta[axis] += 1.0;
	if (theta[axis] > 360.0)
		theta[axis] -= 360.0;
	glutPostRedisplay();
}
