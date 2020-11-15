#include <gl/glut.h>
#include<stdlib.h>

static int shoulder = 0, elbow = 0, finger1_1 = 0, finger2_1 = 0, finger3_1 = 0, finger1_2 = 0, finger2_2 = 0, finger3_2 = 0;
static int state = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		//glTranslatef(-2.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
		glTranslatef(1.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
			glPopMatrix();

		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
			glTranslatef(1.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
			glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
			glTranslatef(1.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(2.0, 0.4, 1.0);
				glutWireCube(1.0);
				glPopMatrix();
//finger1
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(1.0, 0.0, 0.05); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger1_1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
					glScalef(0.3, 0.1, 0.1);
					glutWireCube(1.0);
					glPopMatrix();

				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
					glTranslatef(0.15, 0.0, 0.0); // Pivot 지정 및 객체 이동
					glRotatef((GLfloat)finger1_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
					glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
					glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
						glScalef(0.3, 0.1, 0.1);
						glutWireCube(1.0);
						glPopMatrix();

					glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
						glTranslatef(0.15, 0.0, 0.0); // Pivot 지정 및 객체 이동
						glRotatef((GLfloat)finger1_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
						glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
						glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
							glScalef(0.3, 0.1, 0.1);
							glutWireCube(1.0);
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
//finger2
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(1.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger2_1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(0.3, 0.1, 0.1);
				glutWireCube(1.0);
				glPopMatrix();

				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(0.15, 0.0, 0.0); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger2_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(0.3, 0.1, 0.1);
				glutWireCube(1.0);
				glPopMatrix();

				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(0.15, 0.00, 0.0); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger2_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(0.3, 0.1, 0.1);
				glutWireCube(1.0);
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();


//finger3
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(1.0, 0.0, -0.05); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger3_1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(0.3, 0.1, 0.1);
				glutWireCube(1.0);
				glPopMatrix();

				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(0.15, 0.0, 0.0); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger3_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(0.3, 0.1, 0.1);
				glutWireCube(1.0);
				glPopMatrix();

				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glTranslatef(0.15, 0.00, 0.0); // Pivot 지정 및 객체 이동
				glRotatef((GLfloat)finger3_2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
				glTranslatef(0.15, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
				glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glScalef(0.3, 0.1, 0.1);
				glutWireCube(1.0);
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();

				glPopMatrix();
		glPopMatrix();

	glutSwapBuffers();
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		state = 7;
	}
	else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		state = 8;
	}
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		state = 1;
		break;
	case '2':
		state = 3;
		break;
	case '3':
		state = 5;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void MyTimer(int value) {
	//<1>을 클릭했을 때(state : 1~2)
	if (state == 1) {
		if (finger1_2 < 100) {
			finger1_2 = (finger1_2 + 5) % 180;
		}
		else {
			state = 2;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}
	else if (state == 2) {
		if (finger1_2 > 0) {
			finger1_2 = (finger1_2 - 5) % 180;
		}
		else {
			state = 0;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}
	//<2>을 클릭했을 때(state : 3~4)
	if (state == 3) {
		if (finger2_2 < 100) {
			finger2_2 = (finger2_2 + 5) % 180;
		}
		else {
			state = 4;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}
	else if (state == 4) {
		if (finger2_2 > 0) {
			finger2_2 = (finger2_2 - 5) % 180;
		}
		else {
			state = 0;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}

	//<3>을 클릭했을 때(state : 5~6)
	if (state == 5) {
		if (finger3_2 < 100) {
			finger3_2 = (finger3_2 + 5) % 180;
		}
		else {
			state = 6;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}
	else if (state == 6) {
		if (finger3_2 > 0) {
			finger3_2 = (finger3_2 - 5) % 180;
		}
		else {
			state = 0;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
	//마우스 왼쪽 클릭했을 때
	if (state == 7) {

		shoulder = (shoulder + 2) % 180;
		elbow = (elbow - 7) % 180;
		finger1_1 = (finger1_1 - 5) % 180;
		finger2_1 = (finger2_1 - 5) % 180;
		finger3_1 = (finger3_1 - 5) % 180;
		finger1_2 = (finger1_2 - 5) % 180;
		finger2_2 = (finger2_2 - 5) % 180;
		finger3_2 = (finger3_2 - 5) % 180;

		if (shoulder > 30) {
			state = 0;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}
	//마우스 오른쪽 클릭했을 때
	if (state == 8) {
		shoulder = (shoulder - 2) % 180;
		elbow = (elbow + 7) % 180;
		finger1_1 = (finger1_1 + 5) % 180;
		finger2_1 = (finger2_1 + 5) % 180;
		finger3_1 = (finger3_1 + 5) % 180;
		finger1_2 = (finger1_2 + 5) % 180;
		finger2_2 = (finger2_2 + 5) % 180;
		finger3_2 = (finger3_2 + 5) % 180;

		if (shoulder == 0) {
			state = 0;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}

 //누르지 않았을 때
	else if (state == 0) {
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}



}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("robot arm");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutTimerFunc(40, MyTimer, 1);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}
