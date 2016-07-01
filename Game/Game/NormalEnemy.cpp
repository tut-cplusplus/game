#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy()
	: Enemy()
{

}

NormalEnemy::NormalEnemy(double x, double y, const Size<double>& size)
	: Enemy(x, y, size)
{

}

NormalEnemy::NormalEnemy(double x, double y)
	: Enemy(x, y)
{

}

