#include "RelativeLayout.hpp"

#include "GL/glut.h"

RelativeLayout::RelativeLayout(const Size<double>& size)
	: Layout(size)
{

}

void RelativeLayout::init(void)
{

}

void RelativeLayout::draw(void)
{
	double width = size.getWidth();
	double height = size.getHeight();
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
	unsigned n = (unsigned)components.size();
	for (unsigned i = 0; i < n; i++) {
		Component* component = components[i];
		const Vector<double>& v = vs[i];
		glPushMatrix();
		glTranslated(v.getX(), v.getY(), 0.0);
		component->draw();
		glPopMatrix();
	}
}

