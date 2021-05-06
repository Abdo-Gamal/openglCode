
#include<gl/glut.h>
#include<cmath>
#include<time.h>

double year = 0.0, day = 0.0;
double xRot = 0.0, yRot = 0.0;
double x = 0.0, lx = 0.0,z=0,lz=0;

GLfloat PI = 3.14;

GLfloat windowWidth;
GLfloat windowHeight;

void init_h(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { 0.0, 1700.0, 1700.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);

}

void init_y(void) {

	GLfloat mat_specular[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { 600.0, 600.0, 0.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT1);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);

}

void init_r(void) {

	GLfloat mat_specular[] = { 0.9, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { 1300.0, 1300.0, 0.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT2);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);

}
void init_b(void) {

	GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { 1700.0, 1700.0, 0.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT3);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);

}
void init_n(void) {

	GLfloat mat_specular[] = { 0.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { 1700.0, 1700.0, 0.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT3);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);

}
void init_n1(void) {

	GLfloat mat_specular[] = { 1.0, .0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { 1700.0, 1700.0, 0.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT3);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);

}


void circle(int r) {

	init_h();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);

	for (double ang = 0.0; ang <= (2 * PI); ang += PI / 60) {
		double x = r * cos(ang);
		double y = r * sin(ang);
		glVertex2f(x, y);

	}
	glEnd();
}
void sun(void) {

	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glRotatef(day, 0.0, 1.0, 0.0);
	init_y();
	glutSolidSphere(300.0, 80, 90);                 /* draw sun */
	glPopMatrix();

}
void moon(void) {

	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(30.0, 100, 90);                 /* draw sun */
}

void planet1(int size) {


	glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();

	glRotatef(year * 3, 0.0, 1.0, 0.0);
	glTranslatef(size, 1.0, 0.0);
	
	glutSolidSphere(150.0, 50, 40);    /* draw smaller planet1 */


	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(210);
	glPopMatrix();

	glRotatef(year * 2, 0.0, 1.0, 0.0);
	glTranslatef(210.0, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	init_y();
	moon();
	glPopMatrix();

}
void planet2(int size) {

	glColor3f(0.0, 1.0, 0.0);


	glPushMatrix();
	glRotatef(year * 2, 0.0, 1.0, 0.0);
	glTranslatef(size, 0.0, 0.0);
	init_n1();
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(180.0, 50, 40);    /* draw smaller planet1 */


	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(250);
	glPopMatrix();

	glPushMatrix();
	glRotatef(year * 10, 0.0, 1.0, 0.0);
	glTranslatef(250, 0.0, 0.0);
	
	moon();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(300);
	glPopMatrix();

	glPushMatrix();
	glRotatef(year * 3, 0.0, 1.0, 0.0);
	glTranslatef(300, 0.0, 0.0);
	init_r();
	moon();
	glPopMatrix();


	glPopMatrix();
}
void planet3(int size) {


	glColor3f(1.0, 0.0, 1.0);

	glPushMatrix();
	glRotatef(year, 0.0, 1.0, 0.0);
	glTranslatef(size, 0.0, 0.0);
	init_n();
	glutSolidSphere(200.0, 50, 40);    /* draw smaller planet1 */

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(300);
	glPopMatrix();

	glPushMatrix();
	glRotatef(year * 10, 0.0, 1.0, 0.0);
	glTranslatef(300, 0.0, 0.0);
	moon();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(350);
	glPopMatrix();

	glPushMatrix();
	glRotatef(year * 7, 0.0, 1.0, 0.0);
	glTranslatef(350, 0.0, 0.0);
	moon();
	glPopMatrix();

	glPushMatrix();
	circle(400);
	glPopMatrix();

	glPushMatrix();
	glRotatef(year * 3, 0.0, 0.0, 1.0);
	glTranslatef(400, 0.0, 0.0);
	init_b();
	moon();
	glPopMatrix();

	glPopMatrix();
}
void drawStar() {

	//white color
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);

	glVertex3f(-1000.0f, -300.0f, 0.0f);
	glVertex3f(-1200.0f, -300.0f, 0.0f);
	glVertex3f(-1400.0f, -300.0f, 0.0f);

	glVertex3f(1200.0f, 1210.0f, 0.0f);
	glVertex3f(1300.0f, 1300.0f, 0.0f);
	glVertex3f(1300.0f, 4.0f, 0.0f);
	glVertex3f(1002.0f, 1400.0f, 0.0f);
	glVertex3f(1003.0f, 1032.0f, 0.0f);
	glVertex3f(1993.0f, 1005.0f, 0.0f);
	glVertex3f(1000.0f, 620.0f, 0.0f);
	glVertex3f(200.0f, 500.0f, 0.0f);
	glVertex3f(300.0f, 400.0f, 0.0f);
	glVertex3f(200.0f, 400.0f, 0.0f);
	glVertex3f(300.0f, 600.0f, 0.0f);
	glVertex3f(400.0f, 100.0f, 0.0f);
	glVertex3f(600.0f, 100.0f, 0.0f);
	glVertex3f(800.0f, .0f, 0.0f);
	glVertex3f(1300.0f, 1600.0f, 0.0f);
	glVertex3f(1400.0f, 100.0f, 0.0f);
	glVertex3f(600.0f, 1.0f, 0.0f);
	glVertex3f(800.0f, .0f, 0.0f);
	glVertex3f(600.0f, -100.0f, 0.0f);
	glVertex3f(800.0f, -100.0f, 0.0f);
	glVertex3f(-1000.0f, 300.0f, 0.0f);
	glVertex3f(-1200.0f, 300.0f, 0.0f);
	glVertex3f(-1400.0f, -300.0f, 0.0f);
	glVertex3f(-1000.0f, 400.0f, 0.0f);
	glVertex3f(-1200.0f, 500.0f, 0.0f);
	glVertex3f(-1400.0f, 600.0f, 0.0f);
	glVertex3f(-1500.0f, 400.0f, 0.0f);
	glVertex3f(-1300.0f, 500.0f, 0.0f);
	glVertex3f(-1100.0f, 600.0f, 0.0f);


	glEnd();

}

void make_Star() {

			for (int i = -1; i < 3; i++) {
				for (int j = -1; j < 3; j++) {
			glPushMatrix();
			glRotatef(j * 90, 0, 0, 1);
			glRotatef(j * 90, 0, 1, 0);
			glRotatef(j * 90, 1, 0, 0);

					glTranslatef(i * 500.0, 0, j *500.0);

					drawStar();
			glPopMatrix();
				}
			}

}

void camera() {

	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	make_Star();
	glPushMatrix();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	///////////////////////////////////////
	glPushMatrix();
	sun();
	glPopMatrix();
	///////////////////////////////////////
	glPushMatrix();

	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(600);
	glPopMatrix();

	glPushMatrix();
	glRotatef(70.0, 0.0, 1.0, 0.0);
	planet1(600);
	glPopMatrix();


	///////////////////////////////////////
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(1100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(50.0, 0.0, 1.0, 0.0);
	planet2(1100);
	glPopMatrix();


	///////////////////////////////////////
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	circle(1700);
	glPopMatrix();


	planet3(1700);


	///////////////////////////////////////
	glPopMatrix();

	day += 1.1;
	year += 1.1;

	glutSwapBuffers();
}
void mouse(int btn, int state, int x, int y) {

	if (state == GLUT_DOWN)
	{
		if (btn == GLUT_LEFT_BUTTON) {
			day = day + 0.1f;
			year += 0.1;
		}
		else if (btn == GLUT_RIGHT_BUTTON) {
			day = day - 0.1f;
			year -= 0.1;

		}
		else {
			day = 0.0f;
			year = 0.0;;

		}
	}

	// Refresh the Window
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;
	}
}
void SpecialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP) xRot -= 5.0f;
	if (key == GLUT_KEY_DOWN)  xRot += 5.0f;
	if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT) yRot += 5.0f;

	if (xRot > 356.0f) xRot = 0.0f;
	if (xRot < -1.0f) xRot = 355.0f;
	if (yRot > 356.0f) yRot = 0.0f;
	if (yRot < -1.0f) yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
}
void ChangeSize(int w, int h) {
	GLfloat aspectRatio;

	if (h == 0)        h = 1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h) {
		windowWidth = 2000.0;        windowHeight = 2000.0 / aspectRatio;
		glOrtho(-2000.0, 2000.0, -windowHeight, windowHeight, 2000.0, -2000.0);
	}
	else {
		windowWidth = 2000 * aspectRatio;        windowHeight = 2000;
		glOrtho(-windowWidth, windowWidth, -2000.0, 2000.0, 2000.0, -2000.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
void TimerFunction(int value) {

	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}
void setRC() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
}
int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Solar System ");
	setRC();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutSpecialFunc(SpecialKeys);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(1000, TimerFunction, 1);
	glutMainLoop();

}
