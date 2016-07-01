#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy()
{

}

NormalEnemy::NormalEnemy(double x, double y, double width, double height, int size)
	: Enemy(x, y, width, height, size)
{

}

NormalEnemy::NormalEnemy(double x, double y, int size)
	: Enemy(x, y, size)
{

}

NormalEnemy::NormalEnemy(double x, double y)
	: Enemy(x, y)
{

}

