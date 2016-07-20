#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#include "CircularSector.hpp"

#include <GL/glut.h>

using namespace std;

CircularSector::CircularSector()
	: position(0.0, 0.0), angle(0.0), viewAngle(0.0), radius(0.0)
{
	adjustAngle();
}

CircularSector::CircularSector(const Vector<double>& position, double angle, double viewAngle, double radius)
	: position(position), angle(angle), viewAngle(viewAngle), radius(radius)
{
	adjustAngle();
}

bool CircularSector::isHit(const Vector<double>& _position) const
{
	Vector<double> v(_position);

	v -= position;
	double atan = atan2(v.getY(), v.getX()) / M_PI * 180;
	atan += 360.0;
	while (atan > 360.0)
		atan -= 360.0;
	double da = angle - atan;
	da = da > 0 ? da : -da;
	da = da > 180.0 ? da - 360.0 : da;
	da = da > 0 ? da : -da;
	if (da > viewAngle / 2)
		return false;
	if (v.norm2() > radius * radius)
		return false;
	return true;
}

void CircularSector::draw(void)
{
	glPushMatrix();
	glTranslated(position.getX(), position.getY(), 0.0);
	glRotated(angle, 0.0, 0.0, 1.0);
	glRotated(-viewAngle / 2, 0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(radius, 1.0);
	int n = 100;
	for (int i = 1; i <= n; i++) {
		double angle = (double)i / n * viewAngle / 180 * M_PI;
		double x = cos(angle) * radius;
		double y = sin(angle) * radius;
		glVertex2d(x, y);
	}
	glVertex2d(0.0, 0.0);
	glEnd();
	glPopMatrix();
}

