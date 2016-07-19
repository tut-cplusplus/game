#ifndef ___Class_Circle
#define ___Class_Circle

#include "CircularSector.hpp"
#include "Vector.hpp"

class Circle : CircularSector {
public:
	Circle();
	Circle(const Vector<double>& position, double radius);

	bool isHit(const Vector<double>& position) const;
	void draw(void) const;
};

#endif

