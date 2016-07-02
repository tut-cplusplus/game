#ifndef ___Class_NormalEnemy
#define ___Class_NormalEnemy

#include "Enemy.hpp"
#include "Size.hpp"

class NormalEnemy : public Enemy {
public:
	NormalEnemy();
	NormalEnemy(const Vector<double>& position, const Size<double>& size);
	NormalEnemy(const Vector<double>& position);
};

#endif

