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
	double speed;

public:
	Information();
	Information(const Vector<double>& position, double radius, const Character& character, double speed);

	void registerID(int ID);
	bool searchID(int ID) const;
	bool isHit(const Vector<double>& position) const;
	void draw(void);

	const Character& getCharacter(void) const;
};

inline void Information::registerID(int ID)
{
	IDs.push_back(ID);
}

inline bool Information::searchID(int ID) const
{
	for (auto itr = IDs.begin(); itr != IDs.end(); ++itr) {
		if (*itr == ID)
			return true;
	}
	return false;
}

inline const Character& Information::getCharacter(void) const
{
	return character;
}

#endif

