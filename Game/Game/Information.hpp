#ifndef ___Class_Circle
#define ___Class_Circle

#include "CircularSector.hpp"
#include "Vector.hpp"
#include "Character.hpp"

class Information : public CircularSector {
private:
	Character character;

public:
	Information();
	Information(const Vector<double>& position, double radius, const Character& character);

	bool isHit(const Vector<double>& position) const;
	void draw(void);

	Character getCharacter(void) const;
};

#endif

