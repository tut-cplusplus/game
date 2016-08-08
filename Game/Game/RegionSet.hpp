#ifndef ___Class_RegionSet
#define ___Class_RegionSet

#include <list>

#include "Region.hpp"

class RegionSet {
private:
	static Vector<int> neighbors[];

public:
	class RegionNotFoundException{};

private:
	std::list<Region> regions;

private:
	Region getSubRegion(const Region& region, const Vector<int>& position) const;

public:
	RegionSet();

	std::list<Region>::iterator searchIterator(const Vector<int>& position);
	std::list<Region>::iterator searchIterator(const Region& region);
	Region& search(const Vector<int>& position);
	const Region& search(const Vector<int>& position) const;
	void operator+=(const Vector<int>& position);
	void operator-=(const Vector<int>& position);
	unsigned getRegionNum(void) const;
};

inline unsigned RegionSet::getRegionNum(void) const
{
	return regions.size();
}

#endif

