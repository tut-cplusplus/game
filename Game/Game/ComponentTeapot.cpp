#include "GL/glut.h"

#include "ComponentTeapot.hpp"

using namespace std;

random_device ComponentTeapot::rd;
mt19937 ComponentTeapot::mt(rd());
uniform_int_distribution<int> ComponentTeapot::rnd(1, 10);

ComponentTeapot::ComponentTeapot()
{

}

ComponentTeapot::ComponentTeapot(int width, int height)
	: angle(0.0), Component(width, height)
{
	step = rnd(mt);
}

void ComponentTeapot::draw(void)
{
	int size = (width < height) ? width : height;
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
	glPushMatrix();
	glTranslated(width / 2.0, height / 2.0, 0.0);
	angle += step / 10.0;
	glRotated(angle, 0.0, 1.0, 0.0);
	glutWireTeapot(size / 3.5);
	glPopMatrix();
}

