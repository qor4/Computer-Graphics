#include <gl/glut.h>

int Width, Height;
static float camera_x = 0, camera_y = 0, focus_x = 0, focus_y = 0, focus_z = 0, zoom = 0;

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene() {
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(1.0, 1.5, 5.0);
	glutWireTeapot(1.0);
	glPopMatrix();

	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, -1.0);
	glRotatef(30.0, 0.0, 1.0, 0.0);
	glutWireTorus(0.5, 2.0, 20, 20);
	glPopMatrix();

}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	// 좌하단 뷰폿
	glViewport(0, 0, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-2 - zoom, 9 + zoom, (-2 * (GLfloat)Height / (GLfloat)Width) - zoom, (7 * (GLfloat)Height / (GLfloat)Width) + zoom, -20, 20);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(camera_x, camera_y, 10, focus_x, focus_y, focus_z, 0.0, 1.0, 0.0); //뷰행렬 설정
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	// 우하단 뷰폿
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	// 좌상단 뷰폿
	glViewport(0, Height / 2, Width / 2, Height / 2);
	// 우상단 뷰폿
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(70.0 + (2 * zoom), (GLfloat)Width / (GLfloat)Height, 0, 20);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(camera_x, camera_y,10, focus_x, focus_y, focus_z, 0.0, 1.0, 0.0); //뷰행렬 설정
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}
void MyReshape(int w, int h) {
	Width = w;
	Height = h;
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		camera_y -= 0.1;
		break;
	case GLUT_KEY_RIGHT:
		camera_y += 0.1;
		break;
	case GLUT_KEY_UP:
		camera_x += 0.1;
		break;
	case GLUT_KEY_DOWN:
		camera_x -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();

}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0); break;
	case 'A': focus_x += 0.1; break;
	case 'a': focus_x += 0.1; break;
	case 'F': focus_x -= 0.1; break;
	case 'f': focus_x -= 0.1; break;
	case 'R': focus_y += 0.1; break;
	case 'r': focus_y += 0.1; break;
	case 'V': focus_y -= 0.1; break;
	case 'v': focus_y -= 0.1; break;
	case 'Z': focus_z += 0.1; break;
	case 'z': focus_z += 0.1; break;
	case 'T': focus_z -= 0.1; break;
	case 't': focus_z -= 0.1; break;
	}
	glutPostRedisplay();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		zoom += 1;
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		zoom -= 1;
	}

}

int main(int argc, char** argv) {
glutInit(&argc, argv);
Width = 500;
Height = 500;
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowSize(Width, Height);
glutInitWindowPosition(0, 0);
glutCreateWindow("viewport");
MyInit();
glutDisplayFunc(MyDisplay);
glutReshapeFunc(MyReshape);
glutSpecialFunc(MySpecial);
glutKeyboardFunc(MyKeyboard);
glutMouseFunc(MyMouseClick);
glutMainLoop();
return 0;
}
