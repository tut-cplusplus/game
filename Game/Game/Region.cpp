#include <iostream>
#include <algorithm>

#include "Region.hpp"

using namespace std;

Region::Region()
{

}

list<Vector<int>>::iterator Region::searchIterator(const Vector<int>& position)
{
	auto itr = find(positions.begin(), positions.end(), position);
	if (itr == positions.end())
		throw PositionNotFoundException();
	return itr;
}

bool Region::search(const Vector<int>& position) const
{
	auto itr = find(positions.begin(), positions.end(), position);
	if (itr == positions.end())
		return false;
	return true;
}

bool Region::isAdable(const Vector<int>& position) const
{
	static Vector<int> dtable[] = {
		Vector<int>(1, 0),
		Vector<int>(-1, 0),
		Vector<int>(0, 1),
		Vector<int>(0, -1),
	};
	unsigned n = sizeof(dtable) / sizeof(dtable[0]);
	for (unsigned i = 0; i < n; i++) {
		const Vector<int>& displacement = dtable[i];
		if(search(position + displacement))
			return true;
	}
	return false;
}

void Region::add(const Vector<int>& position)
{
	positions.push_back(position);
}

void Region::remove(list<Vector<int>>::iterator itr)
{
	positions.erase(itr);
}

void Region::remove(list<Vector<int>>::iterator& itr)
{
	itr = positions.erase(itr);
}

void Region::remove(const Vector<int>& position)
{
	remove(searchIterator(position));
}

void Region::operator+=(const Region& region)
{
	positions.insert(positions.end(), region.positions.begin(), region.positions.end());
}

