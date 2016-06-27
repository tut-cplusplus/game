#ifndef ___Class_ComponentTeapot
#define ___Class_ComponentTeapot

#include "GL/glut.h"

#include "Component.hpp"

/**
 * Teapotコンポーネント．
 * レイアウトのテストに用いる．
 */
class ComponentTeapot : public Component {
private:
	int angle;

public:
	ComponentTeapot();
	ComponentTeapot(int width, int height);

	virtual void draw(void);
};

ComponentTeapot::ComponentTeapot()
{

}

ComponentTeapot::ComponentTeapot(int width, int height)
	: angle(0), Component(width, height)
{

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
	glRotated(angle++, 0.0, 1.0, 0.0);
	glutWireTeapot(size / 3.5);
	glPopMatrix();
}

#endif
