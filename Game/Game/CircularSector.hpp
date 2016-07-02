#ifndef ___Class_CircularSector
#define ___Class_CircularSector

#include "Vector.hpp"

class CircularSector {
private:
	Vector<double> position;
	double angle;
	double viewAngle;
	double radius;

public:
	CircularSector();
	CircularSector(const Vector<double>& position, double angle, double viewAngle, double radius);

	bool isHit(const Vector<double>& position) const;
};

#endif

