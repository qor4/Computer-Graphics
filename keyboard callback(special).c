#include <GL/glut.h>

float delta_x = 0;
float delta_y = 0;
float zoom = 0;

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glColor3f(0.5, 0.5, 0.5);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + delta_x - zoom, -0.5 + delta_y - zoom, 0.0);
	glVertex3f(0.5 + delta_x + zoom, -0.5 + delta_y - zoom, 0.0);
	glVertex3f(0.5 + delta_x + zoom, 0.5 + delta_y + zoom, 0.0);
	glVertex3f(-0.5 + delta_x - zoom, 0.5 + delta_y + zoom, 0.0);
	glEnd();
	glFlush();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT:
		delta_x -= 0.1;
		break;
	case GLUT_KEY_RIGHT:
		delta_x += 0.1;
		break;
	case GLUT_KEY_UP:
		delta_y += 0.1;
		break;
	case GLUT_KEY_DOWN:
		delta_y -= 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		if(zoom < 0.5)
			zoom += 0.1;
		break;
	case GLUT_KEY_PAGE_DOWN:
		if(zoom > -0.4)
			zoom -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}
