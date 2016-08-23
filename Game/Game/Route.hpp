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
	std::list<Vector<int>>::size_type getPositionNum(void) const;
	std::list<Vector<int>>::size_type getDistance(void) const;
	const std::list<Vector<int>> getPositions(void) const;
	Vector<int> getNextPosition(void) const;
};

inline void Route::operator+=(const Vector<int>& position)
{
	positions.push_back(position);
}

inline Route& Route::operator--(void)
{
	positions.pop_front();
	return *this;
}

inline std::list<Vector<int>>::size_type Route::getPositionNum(void) const
{
	return positions.size();
}

inline std::list<Vector<int>>::size_type Route::getDistance(void) const
{
	return positions.size() - 1;
}

inline const std::list<Vector<int>> Route::getPositions(void) const
{
	return positions;
}

inline Vector<int> Route::getNextPosition(void) const
{
	return *(positions.begin());
}

#endif
