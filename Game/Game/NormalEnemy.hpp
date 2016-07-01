#ifndef ___Class_NormalEnemy
#define ___Class_NormalEnemy

#include "Enemy.hpp"
#include "Size.hpp"

class NormalEnemy : public Enemy {
public:
	NormalEnemy();
	NormalEnemy(double x, double y, const Size<double>& size);
	NormalEnemy(double x, double y);
};

#endif

