/*
*	name    :  Abdulrahman Gamal Ahmed
*	Dep     :   CS
*	section :   1
            : general
*/
#include<gl/glut.h>
#include<cmath>
#include<time.h>

const double PI = 3.14;
double angle = 0.0;
GLfloat windowWidth;
GLfloat windowHeight;

void sub() {

	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.0f, -10.0f);
	glVertex2f(0.0f, 48.0f);
	glEnd();
}
void sub2() {

	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2f(0.0f, -5.0f);
	glVertex2f(0.0f, 35.0f);
	glEnd();

}

void draw() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	glEnable(GL_LINE_SMOOTH);
	for (double a = 0.0; a <= (2 * PI); a += PI / 20.0f) {
		glLineWidth(6);
		glBegin(GL_LINE_STRIP);
		double x = sin(a);
		double y = cos(a);
		glVertex2f(54 * x, 54 * y);
	}
	glEnd();
	
	glColor3f(0.0f, 1.0f, 1.0f);

	for (double a = 0.0; a < (2 * PI); a += PI / 30.0f) {
		glLineWidth(3);
		glBegin(GL_LINES);

		double x = sin(a);
		double y = cos(a);
		glVertex2f(50 * x, 50 * y);
		glVertex2f(x * 48, y * 48);
		glEnd();
	}
	glColor3f(1.0f, 0.0f, 1.0f);

	for (double a = 0.0; a < (2 * PI); a += PI / 6.0f) {

		glLineWidth(4);
		glBegin(GL_LINES);

		double x = sin(a);
		double y = cos(a);
		glVertex2f(50 * x, 50 * y);
		glVertex2f(x * 40, y * 40);
		glEnd();
	}
	glEnable(GL_POINT_SMOOTH);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glRotated(-1.0 * angle, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	sub();

	glPopMatrix();

	glPushMatrix();
	glRotated((-1.0 * angle) / 60., 0.0f, 0.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 1.0f);
	sub2();
	glPopMatrix();

	angle += 6.f;

	glutSwapBuffers();
}
void ChangeSize(int w, int h) {
	GLfloat aspectRatio;

	if (h == 0)        h = 1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);    glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h) {
		windowWidth = 100;        windowHeight = 100 / aspectRatio;
		glOrtho(-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
	}
	else {
		windowWidth = 100 * aspectRatio;        windowHeight = 100;
		glOrtho(-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
	}

}
void TimerFunction(int value) {

	glutPostRedisplay();
	glutTimerFunc(1000, TimerFunction, 1);
}
void setRC() {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

}
int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("test");
	setRC();
	glutDisplayFunc(draw);
	//glutIdleFunc(draw);
	glutReshapeFunc(ChangeSize);

	glutTimerFunc(1000, TimerFunction, 1);
	glutMainLoop();

}
/*
*	name    :  Abdulrahman Gamal Ahmed
*	Dep     :   CS
*	section :   1
			: general
*/