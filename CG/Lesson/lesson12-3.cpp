#include <GL/glut.h>
#include "windows.h"
void Display(void);
void Reshape(int w, int h);
void init();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(200,200);
 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("A Lighted sphere");
	init();
	glutDisplayFunc(Display);
 	glutReshapeFunc(Reshape);
    glutMainLoop();
	return 0;
}

void Display(void)
{
    glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glTranslatef(0.0,0.0,-3.0);
	glRotatef(60.0,1.0,0.0,0.0);
	glutSolidSphere(1.0,30,60);
	glutSwapBuffers();
}

void Reshape(GLsizei w,GLsizei h)
{
	if (h==0) h=1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	 gluPerspective(60,w/h,1,20);
	glViewport(0,0,w,h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();  
}

void init()
{
	//define light position
	GLfloat light_position[]={1.0,1.0,1.0,0.0};
	//GLfloat light color
	GLfloat light_ambient[]={1.0,0.0,0.0,1.0};
	GLfloat light_diffuse[]={1.0,0.0,0.0,1.0};
	GLfloat light_specular[]={1.0,0.0,0.0,1.0};

	//define light source direction;
	GLfloat light_direction[]={0.0,0.0,-1.0};

	// set light source location
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

	// set light source color;
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);


	//set spotlight parameter
	glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,light_direction);
	glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,0.0);
	glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,180);

	//set light source attenuation
	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,1.0);
	glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,0.0);
	glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,1.0);

	//define material property
	GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[]={50.0};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	glClearColor(1.0,1.0,1.0,1.0);
	glShadeModel(GL_SMOOTH);

	//make light source enable;
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);

}
