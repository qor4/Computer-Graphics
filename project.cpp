#include <gl/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <gl/glaux.h>
#include <vector>
#include <cmath>

#pragma comment(lib, "glaux.lib")
#pragma comment (lib,"legacy_stdio_definitions.lib")


using namespace std;



//========함수원형=========//
void draw(void);
void draw_complete();
void draw_preview_next(void);
void draw_preview_prev(void);
void init(void);
void keyboard(unsigned char key, int x, int y);
void motion(int x, int y);
void mouse(int button, int state, int x, int y);
void reshape(int width, int height);
void specialkeyboard(int key, int x, int y);

//============== block 구조체 ================//
struct block {
	int type;
	GLfloat blc_trans_x;
	GLfloat blc_trans_y;
	GLfloat blc_trans_z;
	GLfloat blc_rot_x;
	GLfloat blc_rot_y;
	GLfloat blc_rot_z;
	GLfloat blc_rot_angle;
};


//void mapTextureMapping();
void draw_floor(void);
void draw_block_1();
void draw_block_2();
void draw_block_3();
void draw_block_4();
void draw_block_5();
void draw_block_6();
void draw_block_7();
void draw_block_8();
void draw_block_9();
void draw_block(int type, GLfloat blc_trans_x, GLfloat blc_trans_y, GLfloat blc_trans_z, GLfloat blc_rot_angle,
	GLfloat blc_rot_x, GLfloat blc_rot_y, GLfloat blc_rot_z);
void draw_block_list();
void undo_drawing();


//============== 시점 관련 변수 ==============//
double pi = 3.14159265358979f;
double radian = 0.1;
double th = 0.7;
double p = 0.7;
double r = 20;
double look_x = r * sin(th) * cos(p);
double look_y = r * sin(th) * sin(p);
double look_z = r * cos(th);
double pre_x, pre_y = 0;
int _width = 0;
int _height = 0;

//============== object 이동 관련 변수 ==============//
GLfloat trans_x = 0;
GLfloat trans_y = 0;
GLfloat trans_z = 0;
GLfloat pre_trans_x = 0;
GLfloat pre_trans_y = 0;
GLfloat pre_trans_z = 0;
GLfloat rot_x = 0;
GLfloat rot_y = 0;
GLfloat rot_z = 0;
GLfloat rot_angle = 0;

GLfloat rot_angle_x = 0;
GLfloat rot_angle_y = 0;
GLfloat rot_angle_z = 0;


//============== 기본 블럭 1번 ==============//
int cur_type = 1;

//============== 관리할 리스트 ==============//
vector <block> block_list;


//바닥
void draw_floor(void) {
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-400, -3, -400);
	glVertex3f(-400, -3, 400);
	glVertex3f(400, -3, 400);
	glVertex3f(400, -3, -400);
	glEnd();
}


//블록 그리기
void draw_block_1() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.7f,0.0f,0.0f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();

}
void draw_block_2() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.0f, 0.7f, 0.0f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}
void draw_block_3() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.0f, 0.0f, 0.7f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}
void draw_block_4() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.7f, 0.0f, 0.7f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}
void draw_block_5() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.0f, 0.7f, 0.7f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();

}
void draw_block_6() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.7f, 0.7f, 0.0f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}
void draw_block_7() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}
void draw_block_8() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.2f, 0.2f, 0.2f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}
void draw_block_9() {
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(0.7f, 0.3f, 0.5f);
	glScalef(1.5, 1.5, 1.5);
	glutSolidCube(3.0f);
	glPopMatrix();
}

//선택한 블록 그리기
void draw_block(int type, GLfloat blc_trans_x, GLfloat blc_trans_y, GLfloat blc_trans_z, GLfloat blc_rot_angle,
	GLfloat blc_rot_x, GLfloat blc_rot_y, GLfloat blc_rot_z) {
	glPushMatrix();
	glTranslatef(blc_trans_x, blc_trans_y, blc_trans_z);
	glRotatef(blc_rot_angle, blc_rot_x, blc_rot_y, blc_rot_z);
	switch (type) {
	case 1:
		draw_block_1();
		break;
	case 2:
		draw_block_2();
		break;
		case 3:
			draw_block_3();
			break;
		case 4:
			draw_block_4();
			break;
		case 5:
			draw_block_5();
			break;
		case 6:
			draw_block_6();
			break;
		case 7:
			draw_block_7();
			break;
		case 8:
			draw_block_8();
			break;
		case 9:
			draw_block_9();
			break;
		default:
			draw_block_1();
			break;
	}
	glPopMatrix();
}

//확정한 블럭 그리기
void draw_block_list() {
	block temp;
	for (int i = 0; i < block_list.size(); i++) {
		temp = block_list.at(i);
		draw_block(temp.type, temp.blc_trans_x, temp.blc_trans_y, temp.blc_trans_z,
			temp.blc_rot_angle, temp.blc_rot_x, temp.blc_rot_y, temp.blc_rot_z);
	}
}
//가장 최근 블록 제거
void undo_drawing() {
	if (block_list.size() != 0)
	{
		block_list.pop_back();

	}
}

void init(void) {
	glClearColor(0.0f, 0.0f, 0.6f, 0.0f);

	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat ambientMaterial[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseMaterial[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat specularMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, 60);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glFrontFace(GL_CW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
}
void reshape(int width, int height) {
	_width = width;
	_height = height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100, (float)width / (float)height, 1, 1800);
	glMatrixMode(GL_MODELVIEW);
}

//확정 블록 추가
void draw_complete() {
	block cur_block;
	cur_block.type = cur_type;
	cur_block.blc_trans_x = trans_x;
	cur_block.blc_trans_y = trans_y;
	cur_block.blc_trans_z = trans_z;
	cur_block.blc_rot_angle = rot_angle;
	cur_block.blc_rot_x = rot_x;
	cur_block.blc_rot_y = rot_y;
	cur_block.blc_rot_z = rot_z;

	block_list.push_back(cur_block);
	
}

//프리뷰 출력
void draw_preview_next(void) {
	glViewport(1.2 * _width / 2, 1.2 * _height / 2, _width / 2, _height / 2);
	glLoadIdentity();
	gluLookAt(5, 8, 10, 0, 0, 0, 0, 1, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	const char* str = "다음 블록(T)";
	glRasterPos3i(0, 0, 8);
	for (int i = 0; i < strlen(str); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	switch (cur_type + 1) {
	case 1:
		draw_block_1();
		break;
	case 2:
		draw_block_2();
		break;
	case 3:
		draw_block_3();
		break;
	case 4:
		draw_block_4();
		break;
	case 5:
		draw_block_5();
		break;
	case 6:
		draw_block_6();
		break;
	case 7:
		draw_block_7();
		break;
	case 8:
		draw_block_8();
		break;
	case 9:
		draw_block_9();
		break;
	default:
		draw_block_1();
		break;
	}
	glFlush();
}
void draw_preview_prev(void) {
	glViewport(-_width / 10, 1.2 * _height / 2, _width / 2, _height / 2);
	glLoadIdentity();
	gluLookAt(5, 8, 10, 0, 0, 0, 0, 1, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	const char* str = "이전 블록(R)";
	glRasterPos3i(0, 0, 8);
	for (int i = 0; i < strlen(str); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	switch (cur_type - 1) {
	case 1:
		draw_block_1();
		break;
	case 2:
		draw_block_2();
		break;
	case 3:
		draw_block_3();
		break;
	case 4:
		draw_block_4();
		break;
	case 5:
		draw_block_5();
		break;
	case 6:
		draw_block_6();
		break;
	case 7:
		draw_block_7();
		break;
	case 8:
		draw_block_8();
		break;
	case 9:
		draw_block_9();
		break;
	default:
		draw_block_9();
		break;
	}
	glFlush();
}
//기본 화면
void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, _width, _height);
	glLoadIdentity();

	if (th <= pi) {
		gluLookAt(look_x, look_z, look_y, 0, 0, 0, 0, 1, 0);
	}
	else if (th > pi) {
		gluLookAt(look_x, look_z, look_y, 0, 0, 0, 0, -1, 0);
	}
	glPushMatrix();
	glTranslatef(look_x, look_z, look_y);
	GLfloat light_position_0[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
	glPopMatrix();

	draw_floor();
	draw_block_list();

	glTranslatef(trans_x, trans_y, trans_z);
	glRotatef(rot_angle, rot_x, rot_y, rot_z);
	switch (cur_type) {
	case 1:
		draw_block_1();
		break;
	case 2:
		draw_block_2();
		break;
	case 3:
		draw_block_3();
		break;
	case 4:
		draw_block_4();
		break;
	case 5:
		draw_block_5();
		break;
	case 6:
		draw_block_6();
		break;
	case 7:
		draw_block_7();
		break;
	case 8:
		draw_block_8();
		break;
	case 9:
		draw_block_9();
		break;
	default:
		draw_block_1();
		break;
	}
	draw_preview_next();
	draw_preview_prev();
	glFlush();
	glutSwapBuffers();
}
//키보드 콜백
void specialkeyboard(int key, int x, int y) {
	//블록 상하좌우 이동
	if (key == GLUT_KEY_LEFT) {
		trans_z += 2;
	}
	else if (key == GLUT_KEY_RIGHT) {
		trans_z -= 2;
	}
	else if (key == GLUT_KEY_UP) {
		trans_x -= 2;
	}
	else if (key == GLUT_KEY_DOWN) {
		trans_x += 2;
	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	//블록 위 아래 이동
	case 'q':
		trans_y += 1;
		break;
	case 'w':
		trans_y -= 1;
		break;
	//블록 회전
	//반시계회전
	case 'a':
		rot_x = 0;
		rot_y = 1;
		rot_z = 0;
		rot_angle += 10;
		break;
	//시계회전
	case 's':
		rot_x = 0;
		rot_y = 1;
		rot_z = 0;
		rot_angle -= 10;
		break;
	case 'd':
		rot_x = 1;
		rot_y = 0;
		rot_z = 0;
		rot_angle += 10;
		break;
	case 'f':
		rot_x = 1;
		rot_y = 0;
		rot_z = 0;
		rot_angle -= 10;
		break;
	case 'g':
		rot_x = 0;
		rot_y = 0;
		rot_z = 1;
		rot_angle += 10;
		break;
	case 'h':
		rot_x = 0;
		rot_y = 0;
		rot_z = 1;
		rot_angle -= 10;
		break;
	//위치 확정
	case 'c':
		draw_complete();
		break;
	//가장 최근 블록 삭제
	case 'z':
		undo_drawing();
		break;
	//블록 변경
	case 'r':
		if (cur_type == 1/*처음인데 이전을 누르면 맨 뒤로*/) {
			cur_type = 9;
		}
		else {
			cur_type--;
		}
		break;
	case 't':
		if (cur_type == 9/*마지막인데 다음을 누르면 맨 앞으로*/) {
			cur_type = 1;
		}
		else {
			cur_type++;
		}
		break;
	}

	glutPostRedisplay();
}
//마우스 콜백
void mouse(int button, int state, int x, int y) {
	if (button == 3)
	{
		r -= 0.7;
		look_x = r * sin(th) * cos(p);
		look_y = r * sin(th) * sin(p);
		look_z = r * cos(th);
	}
	else if (button == 4)
	{
		r += 0.7;
		look_x = r * sin(th) * cos(p);
		look_y = r * sin(th) * sin(p);
		look_z = r * cos(th);
	}
	else if (state == 1)
	{
		pre_x = 0;
		pre_y = 0;
	}
	glutPostRedisplay();
}
void motion(int x, int y) {
	if (pre_x != 0) {
		p -= (pre_x - x) / 300;
		th += (pre_y - y) / 300;
		look_x = r * sin(th) * cos(p);
		look_y = r * sin(th) * sin(p);
		look_z = r * cos(th);
		glutPostRedisplay();
	}
	pre_x = x;
	pre_y = y;
}

int main(int argc, char** argv) {
	int submenu1;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glClearDepth(1.0f);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("openGL Project");
	init();

	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialkeyboard);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();

	return 0;
}
