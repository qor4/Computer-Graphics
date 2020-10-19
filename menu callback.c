#include <GL/glut.h>

GLboolean IsSmall = TRUE;
GLint Shape;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	if ((Shape == 1) && (IsSmall))
		glutWireSphere(0.5, 30, 30);
	else if ((Shape == 1) && (!IsSmall))
		glutWireSphere(0.7, 30, 30);
	else if ((Shape == 2) && (IsSmall))
		glutWireTorus(0.1, 0.3, 40, 20);
	else if ((Shape == 2) && (!IsSmall))
		glutWireTorus(0.2, 0.5, 40, 20);
	else if ((Shape == 3) && (IsSmall))
		glutWireTeapot(0.3);
	else if ((Shape == 3) && (!IsSmall))
		glutWireTeapot(0.5);
	glFlush();
}
void MyMainMenu(int entryID) {
	if (entryID == 1) exit(0);
	glutPostRedisplay();
}
void MySizeMenu_Sphere(int entryID) {
	if (entryID == 1) {
		IsSmall = TRUE;
		Shape = 1;
	}
	else if (entryID == 2) {
		IsSmall = FALSE;
		Shape = 1;
	}
	glutPostRedisplay();
}
void MySizeMenu_Torus(int entryID) {
	if (entryID == 1) {
		IsSmall = TRUE;
		Shape = 2;
	}
	else if (entryID == 2) {
		IsSmall = FALSE;
		Shape = 2;
	}
	glutPostRedisplay();
}
void MySizeMenu_Teapot(int entryID) {
	if (entryID == 1) {
		IsSmall = TRUE;
		Shape = 3;
	}
	else if (entryID == 2) {
		IsSmall = FALSE;
		Shape = 3;
	}
	glutPostRedisplay();
}
void MyColorMenu(int entryID) {
	if (entryID == 1) glColor3f(1.0, 0.0, 0.0);
	else if (entryID == 2) glColor3f(0.0, 1.0, 0.0);
	else if (entryID == 3) glColor3f(0.0, 0.0, 1.0);
	glutPostRedisplay();
}


void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	GLint MySizeID_Sphere = glutCreateMenu(MySizeMenu_Sphere);
	glutAddMenuEntry("Sphere Small", 1);
	glutAddMenuEntry("Sphere Large", 2);
	GLint MySizeID_Torus = glutCreateMenu(MySizeMenu_Torus);
	glutAddMenuEntry("Torus Small", 1);
	glutAddMenuEntry("Torus Large", 2);
	GLint MySizeID_Teapot = glutCreateMenu(MySizeMenu_Teapot);
	glutAddMenuEntry("Teapot Small", 1);
	glutAddMenuEntry("Teapot Large", 2);
	GLint MyColorID = glutCreateMenu(MyColorMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySizeID_Sphere);
	glutAddSubMenu("Draw Torus", MySizeID_Torus);
	glutAddSubMenu("Draw Teapot", MySizeID_Teapot);
	glutAddSubMenu("Change Color", MyColorID);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glColor3f(0.0, 0.5, 0.5);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
