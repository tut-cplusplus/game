#include "Enemy.hpp"
#include <GL/glut.h>

void Enemy::move(void)
{
}

void Enemy::breakWall(void)
{
}

void Enemy::message(void)
{
}

Enemy::Enemy()
	: Character()
{

}

Enemy::Enemy(double x, double y, const Size<double>& size)
	: Character(x, y, size)
{

}

Enemy::Enemy(double x, double y)
	: Character(x, y)
{

}


Enemy::~Enemy()
{
}

void Enemy::changeColor(void) const
{
	glColor3d(0.0, 1.0, 0.0);
}

