#ifndef ___Class_EnemyGenerator
#define ___Class_EnemyGenerator

#include <vector>
#include <string>

class EnemyGenerator {
	unsigned firstSpawnNum;
	unsigned idx;
	std::vector<double> speeds;
	std::vector<double> viewAngles;
	std::vector<double> radiuses;
	std::vector<int> lives;
	std::vector<double> informationSpeeds; 

public:
	EnemyGenerator(const std::string& fpath);

	unsigned getFirstSpawnNum(void) const;
	size_t getSpawnNum(void) const;
	unsigned getSpawnedNum(void) const;
	void getParameter(double& speed, double& viewAngle, double& radius, int& life, double& informationSpeed);
};

inline unsigned EnemyGenerator::getFirstSpawnNum(void) const
{
	return firstSpawnNum;
}

inline size_t EnemyGenerator::getSpawnNum(void) const
{
	return speeds.size();
}

inline unsigned EnemyGenerator::getSpawnedNum(void) const
{
	return idx;
}

inline void EnemyGenerator::getParameter(double& speed, double& viewAngle, double& radius, int& life, double& informationSpeed)
{
	if (idx == speeds.size())
		return;
	speed = speeds[idx];
	viewAngle = viewAngles[idx];
	radius = radiuses[idx];
	life = lives[idx];
	informationSpeed = informationSpeeds[idx];
	idx++;
}

#endif

