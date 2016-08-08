#ifndef ___Class_Region
#define ___Class_Region

#include <list>

#include "Vector.hpp"

class Region {
public:
	class PositionNotFoundException{};
	class CannotAddPositionException{};

private:
	std::list<Vector<int>> positions;

public:
	Region();

	std::list<Vector<int>>::iterator searchIterator(const Vector<int>& position);
	bool search(const Vector<int>& position) const;
	bool isAdable(const Vector<int>& position) const;
	void add(const Vector<int>& position);
	void remove(std::list<Vector<int>>::iterator itr);
	void remove(std::list<Vector<int>>::iterator& itr);
	void remove(const Vector<int>& position);

	void operator+=(const Region& region);
};

#endif

