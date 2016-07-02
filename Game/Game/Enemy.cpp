#include "Enemy.hpp"
#include <GL/glut.h>

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

Enemy::Enemy(const Vector<double>& position, const Size<double>& size)
	: Character(position, size)
{

}

Enemy::Enemy(const Vector<double>& position)
	: Character(position)
{

}


Enemy::~Enemy()
{
}

void Enemy::changeColor(void) const
{
	glColor3d(0.0, 1.0, 0.0);
}

