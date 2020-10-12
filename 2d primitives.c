#include <gl/freeglut.h>
#include <gl/gl.h>
#include <gl/glu.h>


GLUquadricObj* objSphere;
GLUquadricObj* objCylinder;
GLUquadricObj* objDisk;
GLUquadricObj* objPartDisk;

GLuint sphereList;
GLuint cylinderList;
GLuint diskList;
GLuint partialDiskList;

void Sphere()
{
	objSphere = gluNewQuadric();
	gluQuadricDrawStyle(objSphere, GLU_LINE);
	gluSphere(objSphere, 2, 25, 25);

}

void Cylinder()
{
	objCylinder = gluNewQuadric();
	gluQuadricDrawStyle(objCylinder, GLU_LINE);
	gluCylinder(objCylinder, 2, 1, 2, 25, 25);
}

void Disk()
{
	objDisk = gluNewQuadric();
	gluQuadricDrawStyle(objDisk, GLU_FILL);
	gluDisk(objDisk, 0.5, 1, 25, 25);
	
}

void PartDisk()
{
	objPartDisk = gluNewQuadric();
	gluQuadricDrawStyle(objPartDisk, GLU_FILL);
	gluPartialDisk(objPartDisk, 0.5, 2, 25, 25, 0, 120);
}



void MyCreateList()
{
	sphereList = glGenLists(1);
	cylinderList = glGenLists(2);
	diskList = glGenLists(3);
	partialDiskList = glGenLists(4);
	glNewList(sphereList, GL_COMPILE);
	Sphere();
	glEndList();
	glNewList(cylinderList, GL_COMPILE);
	Cylinder();
	glEndList();
	glNewList(diskList, GL_COMPILE);
	Disk();
	glEndList();
	glNewList(partialDiskList, GL_COMPILE);
	PartDisk();
	glEndList();
}


void Mydisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(sphereList); //SsphereList를 호출
	glCallList(cylinderList); //cylinderList를 호출
	glCallList(diskList); //diskList를 호출
	glCallList(partialDiskList); //partialDiskList를 호출
	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2d primitive");
	glutDisplayFunc(Mydisplay);
	glutReshapeFunc(Reshape);
	MyCreateList();
	glutMainLoop();
	
}
