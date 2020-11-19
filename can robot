#include <gl/glut.h>
#include<stdlib.h>

static int neck = 0, head = 0, right_upper_arm = 80, right_lower_arm = 0, right_hand = 0, left_upper_arm = -80, left_lower_arm = 0, left_hand = 0,
right_upper_leg = 0, right_lower_leg = 0, right_foot = 0, left_upper_leg = 0, left_lower_leg = 0, left_foot = 0;
static int state = 0;
static int shoulder = 0, elbow = 0, finger1_1 = 0, finger2_1 = 0, finger3_1 = 0, finger1_2 = 0, finger2_2 = 0, finger3_2 = 0;


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	//Body
	glPushMatrix();
	glPushMatrix();
	glScalef(1.0, 1.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	//Neck
	glPushMatrix();
	glTranslatef(0.0, 0.65, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)neck, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, 0.15, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.3, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Head
	glPushMatrix();
	glTranslatef(0.0, 0.15, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)head, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, 0.3, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.7, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Head pop
	glPopMatrix();
	//Neck pop
	glPopMatrix();

	//Left Upper Arm
	glPushMatrix();
	glTranslatef(0.5, 0.6, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)left_upper_arm, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.35, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.7, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Left Lower Arm
	glPushMatrix();
	glTranslatef(0.35, 0.0, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)left_lower_arm, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.35, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.7, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Left Hand
	glPushMatrix();
	glTranslatef(0.35, 0.0, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)left_hand, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.2, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.4, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Left Hand pop
	glPopMatrix();
	//Left Lower Arm pop
	glPopMatrix();
	//Left Upper Arm pop
	glPopMatrix();

	//Right Upper Arm
	glPushMatrix();
	glTranslatef(-0.5, 0.6, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)right_upper_arm, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(-0.35, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.7, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Right Lower Arm
	glPushMatrix();
	glTranslatef(-0.35, 0.0, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)right_lower_arm, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(-0.35, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.7, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Right Hand
	glPushMatrix();
	glTranslatef(-0.35, 0.0, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)right_hand, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(-0.2, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.4, 0.3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Right Hand pop
	glPopMatrix();
	//Right Lower Arm pop
	glPopMatrix();
	//Right Upper Arm pop
	glPopMatrix();

	//Left Upper Leg
	glPushMatrix();
	glTranslatef(0.25, -0.65, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)left_upper_leg, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, -0.4, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.5, 0.8, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Left Lower Leg
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)left_lower_leg, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, -0.4, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.5, 0.8, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Left Foot
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)left_foot, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, -0.1, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.5, 0.2, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Left Foot pop
	glPopMatrix();
	//Left Lower Leg pop
	glPopMatrix();
	//Left Upper Leg pop
	glPopMatrix();

	//Right Upper Leg
	glPushMatrix();
	glTranslatef(-0.25, -0.65, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)right_upper_leg, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, -0.4, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.5, 0.8, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Right Lower Leg
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)right_lower_leg, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, -0.4, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.5, 0.8, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Right Foot
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)right_foot, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(0.0, -0.1, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
	glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
	glScalef(0.5, 0.2, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//Right Foot pop
	glPopMatrix();
	//Right Lower Arm pop
	glPopMatrix();
	//Right Upper Arm pop
	glPopMatrix();

	//Body pop
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
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
		state = 1;
	}
}


void MyTimer(int value) {
	//마우스 오른쪽 클릭했을 때(state : 1~2)
	if (state == 1) {
		if (left_upper_arm < 50) {
			right_upper_arm = (right_upper_arm - 5) % 360;
			left_upper_arm = (left_upper_arm + 5) % 360;

		}
		if (left_lower_arm < 80) {
			right_lower_arm = (right_lower_arm - 2) % 360;
			left_lower_arm = (left_lower_arm + 2) % 360;
		}
		if (left_hand < 70) {
			right_hand = (right_hand - 2) % 360;
			left_hand = (left_hand + 2) % 360;
		}
		else{
			state = 2;
		}
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);

	}
	if (state == 2) {
		if (left_upper_arm > -80) {
			right_upper_arm = (right_upper_arm + 5) % 360;
			left_upper_arm = (left_upper_arm - 5) % 360;
		}
		if (left_lower_arm > 0) {
			right_lower_arm = (right_lower_arm + 2) % 360;
			left_lower_arm = (left_lower_arm - 2) % 360;
		}
		if (left_hand > 0) {
			right_hand = (right_hand + 2) % 360;
			left_hand = (left_hand - 2) % 360;
		}
		else {
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
	glutCreateWindow("Can Robot");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutTimerFunc(40, MyTimer, 1);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}
