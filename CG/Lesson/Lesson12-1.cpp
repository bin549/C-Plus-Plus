#include "stdafx.h"
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159

float theta = -90.0;		//rotating angle
int inner = 10, outer = 80; //torus's inner & outer radius
float s = outer + 4 * inner + 50;
float eyex = 0, eyey = 0, eyez = s; //eye point initial position
float atx = 0, aty = 0, atz = 0;	//at point initial position
int ww, hh;							//variable for windows's width
bool flag = true;
float angle = 0;	 //for angle between view-line and z axis
float r = s;		 //for distance between eye and at
float step = r / 10; //for forward and backword step;

void Display(void);
void Reshape(int w, int h);
void mytime(int value);
void drawground();
void drawsphere();
void drawwall();
void init();
void mykeyboard(unsigned char key, int x, int y);

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR lpCmdLine,
					   int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	char *argv[] = {"hello ", " "};
	int argc = 2;
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);
	glutCreateWindow("Rotating 3D World");
	glutReshapeFunc(Reshape);
	init();
	glutDisplayFunc(Display); 
	glutKeyboardFunc(mykeyboard);
	glutTimerFunc(100, mytime, 10);
	glutMainLoop(); 
	return 0;
}

void init()
{
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void mykeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'W':
	case 'w': // 向前直走
			  //your code Here
		eyex = eyex - step * sin(angle * PI / 180.0);
		eyez = eyez - step * cos(angle * PI / 180.0);
		atx = atx - step * sin(angle * PI / 180.0);
		atz = atz - step * cos(angle * PI / 180.0);
		break;
	case 'S':
	case 's': //向后退
			  //your code Here
		eyex = eyex + step * sin(angle * PI / 180.0);
		eyez = eyez + step * cos(angle * PI / 180.0);
		atx = atx + step * sin(angle * PI / 180.0);
		atz = atz + step * cos(angle * PI / 180.0);
		break;
	case 'A':
	case 'a': //左看
		//your code Here
		angle = angle + 1;
		atx = eyex - r * sin(angle * PI / 180.0);
		atz = eyez - r * cos(angle * PI / 180.0);
		break;
	case 'D':
	case 'd': //右看
		//your code Here
		angle = angle - 1;
		atx = eyex - r * sin(angle * PI / 180.0);
		atz = eyez - r * cos(angle * PI / 180.0);
		break;
	}
	glutPostRedisplay(); //参数修改后调用重画函数，屏幕图形将发生改变
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, atx, aty, atz, 0, 1, 0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	drawwall();
	glColor3f(1.0, 0, 0);
	drawground();
	drawsphere();
	glPopMatrix();
	glutSwapBuffers();
}

void drawsphere()
{
	float tr;
	tr = (outer + 3 * inner);
	glRotatef(theta, 0, 1, 0);
	glPushMatrix();
	glPushMatrix();
	glColor3f(1.0, 0, 1.0);
	glutWireTorus(inner, outer, 30, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(outer, 0, 0);
	glRotatef(theta, 0, 1, 0);
	glTranslatef(-outer, 0, 0);

	glPushMatrix();
	glTranslatef(tr, 0, 0);
	glRotatef(-45, 1, 0, 0);
	glColor3f(0.0, 1.0, 0);
	glutWireSphere(inner, 20, 20);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void drawground()
{
	//ground
	for (int i = -outer - 4 * inner; i < outer + 4 * inner; i += 2 * inner)
		for (int j = -outer - 4 * inner; j < outer + 4 * inner; j += 2 * inner)
		{
			glBegin(GL_QUADS);
			glVertex3d(j, -outer - 4 * inner, i);
			glVertex3d(j, -outer - 4 * inner, i + 2 * inner);
			glVertex3d(j + 2 * inner, -outer - 4 * inner, i + 2 * inner);
			glVertex3d(j + 2 * inner, -outer - 4 * inner, i);
			glEnd();
		}

	//top
	for (int i = -outer - 4 * inner; i < outer + 4 * inner; i += 2 * inner)
		for (int j = -outer - 4 * inner; j < outer + 4 * inner; j += 2 * inner)
		{
			glBegin(GL_QUADS);
			glVertex3d(j, outer + 4 * inner, i);
			glVertex3d(j, outer + 4 * inner, i + 2 * inner);
			glVertex3d(j + 2 * inner, outer + 4 * inner, i + 2 * inner);
			glVertex3d(j + 2 * inner, outer + 4 * inner, i);
			glEnd();
		}
}

void drawwall()
{
	int i, j;

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//left
	for (i = -outer - 4 * inner; i < outer + 4 * inner; i += 2 * inner)
		for (j = -outer - 4 * inner; j < outer + 4 * inner; j += 2 * inner)
		{
			glBegin(GL_QUADS);
			glVertex3d(-outer - 4 * inner, j, i);
			glVertex3d(-outer - 4 * inner, j + 2 * inner, i);
			glVertex3d(-outer - 4 * inner, j + 2 * inner, i + 2 * inner);
			glVertex3d(-outer - 4 * inner, j, i + 2 * inner);
			glEnd();
		}

	//right
	for (i = -outer - 4 * inner; i <= outer + 4 * inner - 2 * inner; i += 2 * inner)	 //for z
		for (j = -outer - 4 * inner; j <= outer + 4 * inner - 2 * inner; j += 2 * inner) //for y
		{
			glBegin(GL_QUADS);
			glVertex3f(outer + 4 * inner, j, i);
			glVertex3f(outer + 4 * inner, j + 2 * inner, i);
			glVertex3f(outer + 4 * inner, j + 2 * inner, i + 2 * inner);
			glVertex3f(outer + 4 * inner, j, i + 2 * inner);
			glEnd();
		}

	glColor3f(1.0, 1.0, 0.0);
	//front
	for (i = -outer - 4 * inner; i <= outer + 4 * inner - 2 * inner; i += 2 * inner)	 //for z
		for (j = -outer - 4 * inner; j <= outer + 4 * inner - 2 * inner; j += 2 * inner) //for y
		{
			glBegin(GL_QUADS);
			glVertex3f(j, i, -outer - 4 * inner);
			glVertex3f(j + 2 * inner, i, -outer - 4 * inner);
			glVertex3f(j + 2 * inner, i + 2 * inner, -outer - 4 * inner);
			glVertex3f(j, i + 2 * inner, -outer - 4 * inner);
			glEnd();
		}
}

void mytime(int value)
{
	theta += 0.5;
	if (theta >= 360.0)
		theta -= 360.0;
	glutPostRedisplay();
	glutTimerFunc(100, mytime, 10);
}

void Reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, w / h, 10, 2 * outer + 8 * inner + 250);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	ww = w;
	hh = h;
}
