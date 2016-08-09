#ifndef ___Class_RegionSet
#define ___Class_RegionSet

#include <list>

#include "Region.hpp"
#include "Exception.hpp"

using Exception_ = Exception;

class RegionSet {
private:
	static Vector<int> neighbors[];

public:
	class RegionNotFoundException : public Exception {
	private:
		Vector<int> position;

	public:
		RegionNotFoundException(const std::string& file, int line, const Vector<int>& position);

		const Vector<int>& getPosition(void) const;
	};

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
	size_t getRegionNum(void) const;
	const std::list<Region>& getRegions(void) const;
};

inline RegionSet::RegionNotFoundException::RegionNotFoundException(const std::string& file, int line, const Vector<int>& position)
	: Exception_(file, line), position(position)
{

}

inline const Vector<int>& RegionSet::RegionNotFoundException::getPosition(void) const
{
	return position;
}

inline size_t RegionSet::getRegionNum(void) const
{
	return regions.size();
}

inline const std::list<Region>& RegionSet::getRegions(void) const
{
	return regions;
}

#define RegionNotFoundException(x) RegionNotFoundException(__FILE__, __LINE__, x)

#endif

