#include <cmath>

#include "CircularSector.hpp"

CircularSector::CircularSector()
	: position(0.0, 0.0), angle(0.0), viewAngle(0.0), radius(0.0)
{

}

CircularSector::CircularSector(const Vector<double>& position, double angle, double viewAngle, double radius)
	: position(position), angle(angle), viewAngle(viewAngle), radius(radius)
{

}

bool CircularSector::isHit(const Vector<double>& _position) const
{
	Vector<double> v(_position);

	v -= position;
	double atan = atan2(v.getY(), v.getX()) / M_PI * 180;
	double da = angle - atan;
	da = da > 0 ? da : -da;
	if (da > viewAngle / 2)
		return false;
	if (v.norm2() > radius * radius)
		return false;
	return true;
}

