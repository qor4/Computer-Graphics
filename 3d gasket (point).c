#include <stdio.h>
#include <GL/glut.h>

void MyDisplay(void)
{
	int i, j, k;
	float p[3] = { 75.0, 50.0, 100.0 }; //찍힐 포인트
	float vertices[4][3] = { //vertices[3][2]의 3개의 꼭짓점을 가진 x, y 좌표에서 4개의 꼭짓점을 가진 x, y, z 좌표로 변경
	  {   0.0,   0.0,   0.0 },
	  { 250.0, 500.0, 100.0 },
	  { 500.0, 250.0, 250.0 },
	  { 250.0, 100.0, 250.0 } };
	for (k = 0; k < 50000; k++) //50000번 반복
	{
		j = rand() % 4; //4개의 꼭짓점 중에서 하나의 꼭짓점을 무작위로 선택

		//찍힐 포인트 p와 vertices 점들의 평균 == 새로 찍을 점
		p[0] = (p[0] + vertices[j][0]) / 2;
		p[1] = (p[1] + vertices[j][1]) / 2;
		p[2] = (p[2] + vertices[j][2]) / 2;
		glBegin(GL_POINTS);
		glVertex3fv(p); //새로 점을 찍음
		glEnd();
	}
	glFlush();

}

void MyInit(void){
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경 색 설정(흰색)
	glColor3f(1.0, 0.0, 0.0); //점의 색 설정(빨강색)
}

void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight); //현재 width와 height
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500; //변경된 width의 비율을 구함
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500; //변경된 height의 비율을 구함
	glMatrixMode(GL_PROJECTION); //행렬 모드 설정(투영 행렬)
	glLoadIdentity(); //투영 행렬 초기화
	glOrtho(0.0*Widthfactor, 500.0*Widthfactor, 0.0*Heightfactor, 500.0*Heightfactor, -250.0, 250.0); //투영 행렬을 사용하여 비율만큼 가시부피 변환
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500); //윈도우 크기
	glutInitWindowPosition(0, 0); //윈도우 위치
	glutCreateWindow("3d gasket"); //윈도우 이름
	glutDisplayFunc(MyDisplay);
	MyInit();
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}

