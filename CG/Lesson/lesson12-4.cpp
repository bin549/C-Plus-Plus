#include <windows.h>
#include <GL/glut.h>

int step=0;
void myinit(void)
{
  glClearColor(1.0,1.0,1.0,1.0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

}

void display(void)
{
 
	// setting light source;
	GLfloat position[]={0.0,0.0,4.0,1.0};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0,0,-10);
	glPushMatrix();

	//rotating light source;
	glRotatef(step,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);

	glPushMatrix();
	// blue sphere as a light source;
	glTranslatef(0,0,4);
	glDisable(GL_LIGHTING);
	glColor3f(0,0,1);
	glutSolidSphere(0.1,20,16);

	glPopMatrix();

	glPopMatrix();
	glEnable(GL_LIGHTING);

	//draw a 20th polyhons shined by light source;
	glutSolidIcosahedron();

	glPopMatrix();
	glFlush();

}

// press mouse left button to rotate light source;
void mouse(int button, int state,int x,int y)
{
	switch(button){
		case GLUT_LEFT_BUTTON:
			step+=5;
			display();
			break;
		  default:
			break;
	}
}

void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20.0,(GLfloat)w/(GLfloat)h,1,20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(200,200);              //屏幕分辨率1024*768
	glutInitWindowPosition(150,150);               //左上角为原点
	glutCreateWindow("Movelight");
	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	glutMouseFunc(mouse);
    
	glutMainLoop();
	return 0;
}

