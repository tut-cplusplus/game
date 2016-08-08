#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

#include "Region.hpp"

using namespace std;

Vector<int> Region::neighbors[] = {
	Vector<int>(1, 0),
	Vector<int>(-1, 0),
	Vector<int>(0, 1),
	Vector<int>(0, -1),
};

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
	unsigned n = sizeof(neighbors) / sizeof(neighbors[0]);
	for (unsigned i = 0; i < n; i++) {
		const Vector<int>& displacement = neighbors[i];
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

Route Region::breadthFirstSearch(const Vector<int>& start, const Vector<int>& end) const
{
	queue<Route> routes;
	vector<Vector<int>> visited;
	Route route;
	route += start;
	routes.push(route);
	visited.push_back(start);
	while (routes.size()) {
		Route route = routes.front();
		routes.pop();
		const list<Vector<int>>& positions = route.getPositions();
		const Vector<int>& position = positions.back();
		unsigned n = sizeof(neighbors) / sizeof(neighbors[0]);
		for (unsigned i = 0; i < n; i++) {
			const Vector<int>& displacement = neighbors[i];
			Vector<int> neighbor = position + displacement;
			if (find(visited.begin(), visited.end(), neighbor) != visited.end())
				continue;
			if (!search(neighbor))
				continue;
			visited.push_back(neighbor);
			Route newRoute(route);
			newRoute += neighbor;
			if (neighbor == end)
				return newRoute;
			routes.push(newRoute);
		}
	}
	throw CannotArriveException{};
}

void Region::operator+=(const Region& region)
{
	positions.insert(positions.end(), region.positions.begin(), region.positions.end());
}

