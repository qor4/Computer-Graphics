#include <GL/glut.h>

GLfloat move = 0;
GLint state = 0;

void MyDisplay() {
	glViewport(0, 0, 500, 500);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0 + move, -0.25, 0.0);
	glVertex3f(-0.5 + move, -0.25, 0.0);
	glVertex3f(-0.5 + move, 0.25, 0.0);
	glVertex3f(-1.0 + move, 0.25, 0.0);
	glEnd();
	glFlush();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		state = 1;
	}
	else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		state = 0;
	}
}
void MyIdle() {
	if (state == 1) {
		if (move < 1.5) {
			move += 0.001;
			glutPostRedisplay();
		}
	}

}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Mouse Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyIdle);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}
