#include <iostream>
#include <cmath>

#include "CircularSector.hpp"

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

void CircularSector::adjustAngle(void)
{
	angle += 360.0;
	while (angle >= 360.0)
		angle -= 360.0;
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

