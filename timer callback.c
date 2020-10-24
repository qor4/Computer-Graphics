#include <GL/glut.h>
#include <stdio.h>

GLint Delta;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MyTimer(int Value) {
	Delta = rand() % 15;
	switch (Delta) {
	case 0:	glColor3f(0, 0, 0); break;
	case 1:	glColor3f(1, 0, 0); break;
	case 2:	glColor3f(0, 1, 0); break;
	case 3:	glColor3f(0, 0, 1); break;
	case 4:	glColor3f(0.2, 0.4, 0); break;
	case 5:	glColor3f(0, 0, 0.6); break;
	case 6:	glColor3f(0, 0.3, 0.2); break;
	case 7:	glColor3f(0.1, 0.4, 0.7); break;
	case 8:	glColor3f(0.2, 0.6, 0.1); break;
	case 9:	glColor3f(0.8, 0.3, 0.6); break;
	case 10: glColor3f(0.7, 1, 0.5); break;
	case 11: glColor3f(0.2, 0.9, 0.0); break;
	case 12: glColor3f(0.2, 0.3, 0.7); break;
	case 13: glColor3f(0.0, 0.2, 0.9); break;
	case 14: glColor3f(0.9, 0.1, 0.2); break;
	case 15: glColor3f(1, 1, 1); break;
	}
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Timer Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1);
	glutMainLoop();
	return 0;
}
