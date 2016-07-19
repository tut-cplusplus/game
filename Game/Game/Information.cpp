#define _USE_MATH_DEFINES
#include <cmath>

#include "Information.hpp"

#include <GL/glut.h>

Information::Information()
	: CircularSector()
{

}

Information::Information(const Vector<double>& position, double radius, const Character& character)
	: CircularSector(position, 0.0, 0.0, radius), character(character)
{

}

bool Information::isHit(const Vector<double>& position) const
{
	Vector<double> dposition = this->position - position;
	double dx = dposition.getX();
	double dy = dposition.getY();
	double r2 = dx * dx + dy * dy;
	if (r2 > radius * radius)
		return false;
	return true;
}

void Information::draw(void)
{
	glPushMatrix();
	Size<double> size = character.getSize();
	double x = position.getX() * size.getWidth();
	double y = position.getY() * size.getHeight();
	glTranslated(x, y, 0.0);
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
	radius += 1.0;
}

Character Information::getCharacter(void) const
{
	return character;
}

