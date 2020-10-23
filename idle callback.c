#include <gl/glut.h>
glfloat delta_x = 0.0;
glfloat delta_y = 0.0;
glint dir;


void mydisplay() {
	glclear(gl_color_buffer_bit);
	glbegin(gl_polygon);
	glcolor3f(0.0, 0.5, 0.8);
	glvertex3f(-1.0 + delta_x, -0.5 + delta_y, 0.0);
	glvertex3f(0.0 + delta_x, -0.5 + delta_y, 0.0);
	glvertex3f(0.0 + delta_x, 0.5 + delta_y, 0.0);
	glvertex3f(-1.0 + delta_x, 0.5 + delta_y, 0.0);
	glend();
	glutswapbuffers();
}
void myidle() {
	if (dir == 1) {
		if(delta_x >= 0)
			delta_x -= 0.001;
	}
	else if (dir == 2) {
		if (delta_x <= 1)
			delta_x += 0.001;

	}
	else if (dir == 3) {
		if (delta_y <= 0.5)
			delta_y += 0.001;

	}
	else if (dir == 4) {
		if (delta_y >= -0.5)
			delta_y -= 0.001;

	}
	glutpostredisplay();
}
void myspecial(int key, int x, int y) {
	switch (key) {
	case glut_key_f1:
		break;
	case glut_key_left:
		dir = 1;
		break;
	case glut_key_right:
		dir = 2;
		break;
	case glut_key_up:
		dir = 3;
		break;
	case glut_key_down:
		dir = 4;
		break;
	default:
		break;
	}
}

void myinit() {
	glclearcolor(1.0, 1.0, 1.0, 1.0);
	glmatrixmode(gl_projection);
	glloadidentity();
	glortho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutinit(&argc, argv);
	glutinitdisplaymode(glut_rgb | glut_double);
	glutinitwindowsize(300, 300);
	glutinitwindowposition(0, 0);
	glutcreatewindow("idle callback");
	myinit();
	glutdisplayfunc(mydisplay);
	glutidlefunc(myidle);
	glutspecialfunc(myspecial);
	glutmainloop();
	return 0;
}
