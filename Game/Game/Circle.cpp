#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.hpp"

#include <GL/glut.h>

Circle::Circle()
	: CircularSector()
{

}

Circle::Circle(const Vector<double>& position, double radius)
	: CircularSector(position, 0.0, 0.0, radius)
{

}

bool Circle::isHit(const Vector<double>& position) const
{
	Vector<double> dposition = this->position - position;
	double dx = dposition.getX();
	double dy = dposition.getY();
	double r2 = dx * dx + dy * dy;
	if (r2 > radius * radius)
		return false;
	return true;
}

void Circle::draw(void) const
{
	glPushMatrix();
	glTranslated(position.getX(), position.getY(), 0.0);
	glBegin(GL_LINE_LOOP);
	int n = 100;
	for (int i = 0; i <= n; i++) {
		double angle = 2 * M_PI * i / n;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(x, y);
	}
	glEnd();
	glPopMatrix();
}

