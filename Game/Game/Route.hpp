#ifndef ___Class_Route
#define ___Class_Route

#include <list>

#include "Vector.hpp"

class Route {
private:
	std::list<Vector<int>> positions;

public:
	Route();

	void operator+=(const Vector<int>& position);
	Route& operator--(void);
	unsigned getPositionNum(void) const;
	unsigned getDistance(void) const;
	const std::list<Vector<int>> getPositions(void) const;
};

inline void Route::operator+=(const Vector<int>& position)
{
	positions.push_back(position);
}

inline Route& Route::operator--(void)
{
	positions.pop_back();
	return *this;
}

inline unsigned Route::getPositionNum(void) const
{
	return positions.size();
}

inline unsigned Route::getDistance(void) const
{
	return positions.size() - 1;
}

inline const std::list<Vector<int>> Route::getPositions(void) const
{
	return positions;
}

#endif

