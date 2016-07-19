#ifndef ___Class_Circle
#define ___Class_Circle

#include <vector>

#include "CircularSector.hpp"
#include "Vector.hpp"
#include "Character.hpp"

class Information : public CircularSector {
private:
	Character character;
	std::vector<int> IDs;

public:
	Information();
	Information(const Vector<double>& position, double radius, const Character& character);

	void registerID(int ID);
	bool searchID(int ID) const;
	bool isHit(const Vector<double>& position) const;
	void draw(void);

	Character getCharacter(void) const;
};

#endif

