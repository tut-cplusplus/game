#ifndef ___Class_NormalEnemy
#define ___Class_NormalEnemy

#include "Enemy.hpp"

class NormalEnemy : public Enemy {
public:
	NormalEnemy();
	NormalEnemy(double x, double y, double width, double height, int size);
	NormalEnemy(double x, double y, int size);
	NormalEnemy(double x, double y);
};

#endif

