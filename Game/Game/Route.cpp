#include "Route.hpp"

using namespace std;

Route::Route()
{

}


Route::Route(const Vector<int>& start, const Vector<int>& end)
{
	Vector<int> position(start);
	while (position != end) {
		Vector<int> displacement = end - position;
		positions.push_back(position);
		if (abs(displacement.getX()) > abs(displacement.getY())) {
			position += (displacement.getX() > 0) ? Vector<int>(1, 0) : Vector<int>(-1, 0);
		} else {
			position += (displacement.getY() > 0) ? Vector<int>(0, 1) : Vector<int>(0, -1);
		}
	}
	positions.push_back(end);
}

