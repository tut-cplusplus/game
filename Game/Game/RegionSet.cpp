#include <vector>

#include "RegionSet.hpp"

using namespace std;

Vector<int> RegionSet::neighbors[] = {
	Vector<int>(1, 0),
	Vector<int>(-1, 0),
	Vector<int>(0, 1),
	Vector<int>(0, -1),
};

RegionSet::RegionSet()
{

}

list<Region>::iterator RegionSet::searchIterator(const Vector<int>& position)
{
	return searchIterator(search(position));
}

std::list<Region>::iterator RegionSet::searchIterator(const Region& region)
{
	for (auto itr = regions.begin(); itr != regions.end(); ++itr) {
		Region& r= *itr;
		if (&r == &region)
			return itr;
	}
	throw RegionNotFoundException();
}

Region& RegionSet::search(const Vector<int>& position)
{
	for (auto itr = regions.begin(); itr != regions.end(); ++itr) {
		Region& region = *itr;
		if (region.search(position))
			return region;
	}
	throw RegionNotFoundException();
}

const Region& RegionSet::search(const Vector<int>& position) const
{
	for (auto itr = regions.begin(); itr != regions.end(); ++itr) {
		const Region& region = *itr;
		if (region.search(position))
			return region;
	}
	throw RegionNotFoundException();
}

void RegionSet::operator+=(const Vector<int>& position)
{
	unsigned n = sizeof(neighbors) / sizeof(neighbors[0]);
	//positionが追加されることによって接続される領域のリスト
	vector<Region*> foundRegions;
	for (unsigned i = 0; i < n; i++) {
		const Vector<int>& displacement = neighbors[i];
		Vector<int> neighborPosition = position + displacement;
		bool flag = false;
		for (auto itr = foundRegions.begin(); itr != foundRegions.end(); ++itr) {
			Region& region = **itr;
			if (region.search(neighborPosition)) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		try {
			Region& region = search(neighborPosition);
			foundRegions.push_back(&region);
		}
		catch (const RegionNotFoundException& e) {

		}
	}
	if (!foundRegions.size()) {
		Region region;
		region += position;
		regions.push_back(region);
		return;
	}
	Region& region = *foundRegions[0];
	for (auto itr = foundRegions.begin() + 1; itr != foundRegions.end(); ++itr) {
		Region& src = **itr;
		region += src;
		regions.erase(searchIterator(src));
	}
	region += position;
}

void RegionSet::operator-=(const Vector<int>& position)
{
	Region& region = search(position);
	//未実装
}

