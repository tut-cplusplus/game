#include <iostream>
#include <fstream>

#include "EnemyGenerator.hpp"

using namespace std;

EnemyGenerator::EnemyGenerator(const string& fpath)
	: idx(0)
{
	ifstream ifs(fpath);

	string dummy;
	ifs >> dummy;
	ifs >> dummy;
	unsigned num;
	ifs >> num;
	ifs >> firstSpawnNum;
	ifs >> dummy;
	ifs >> dummy;
	ifs >> dummy;
	ifs >> dummy;
	for (unsigned i = 0; i < num; i++) {
		double speed;
		double viewAngle;
		double radius;
		int life;
		ifs >> speed >> viewAngle >> radius >> life;
		speeds.push_back(speed);
		viewAngles.push_back(viewAngle);
		radiuses.push_back(radius);
		lives.push_back(life);
	}
}

