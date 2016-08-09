#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include "RegionSet.hpp"

using namespace std;

Vector<int> RegionSet::neighbors[] = {
	Vector<int>(1, 0),
	Vector<int>(-1, 0),
	Vector<int>(0, 1),
	Vector<int>(0, -1),
};

Region RegionSet::getSubRegion(const Region& region, const Vector<int>& position) const
{
	queue<Vector<int>> positions;
	Region subRegion;
	subRegion += position;
	positions.push(position);
	while (positions.size()) {
		Vector<int> position = positions.front();
		positions.pop();
		unsigned n = sizeof(neighbors) / sizeof(neighbors[0]);
		for (unsigned i = 0; i < n; i++) {
			const Vector<int>& displacement = neighbors[i];
			Vector<int> neighbor = position + displacement;
			if (subRegion.search(neighbor))
				continue;
			if (!region.search(neighbor))
				continue;
			subRegion += neighbor;
			positions.push(neighbor);
		}
	}
	return subRegion;
}

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
	throw RegionNotFoundException(Vector<int>());
}

Region& RegionSet::search(const Vector<int>& position)
{
	for (auto itr = regions.begin(); itr != regions.end(); ++itr) {
		Region& region = *itr;
		if (region.search(position))
			return region;
	}
	throw RegionNotFoundException(Vector<int>());
}

const Region& RegionSet::search(const Vector<int>& position) const
{
	for (auto itr = regions.begin(); itr != regions.end(); ++itr) {
		const Region& region = *itr;
		if (region.search(position))
			return region;
	}
	throw RegionNotFoundException(position);
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
		catch (const RegionNotFoundException&) {

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
	auto itr = searchIterator(position);
	Region& region = *itr;
	region -= position;
	unsigned n = sizeof(neighbors) / sizeof(neighbors[0]);
	list<Vector<int>> neighborPositions;
	for (unsigned i = 0; i < n; i++) {
		const Vector<int>& displacement = neighbors[i];
		neighborPositions.push_back(position + displacement);
	}
	while (neighborPositions.size()) {
		Vector<int> position = neighborPositions.front();
		neighborPositions.pop_front();
		if (!region.search(position))
			continue;
		Region subRegion = getSubRegion(region, position);
		for (auto itr = neighborPositions.begin(); itr != neighborPositions.end();) {
			const Vector<int>& position = *itr;
			if (subRegion.search(position)) {
				itr = neighborPositions.erase(itr);
				continue;
			}
			++itr;
		}
		regions.push_back(subRegion);
	}
	regions.erase(itr);
}

