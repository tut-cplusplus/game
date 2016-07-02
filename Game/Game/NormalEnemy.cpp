#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy()
	: Enemy()
{

}

NormalEnemy::NormalEnemy(const Vector<double>& position, const Size<double>& size)
	: Enemy(position, size)
{

}

NormalEnemy::NormalEnemy(const Vector<double>& position)
	: Enemy(position)
{

}

