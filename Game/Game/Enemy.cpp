#include <random>

#include "Enemy.hpp"
#include <GL/glut.h>

using namespace std;

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

void Enemy::onMoveAI(void)
{
	if (isMoving)
		return;
	static random_device rd;
	static mt19937 mt(rd());
	static uniform_int_distribution<int> randomDirection(NORTH, WEST);
	direction = (Direction)randomDirection(mt);
	startMoving();
}

void Enemy::changeColor(void) const
{
	glColor3d(0.0, 1.0, 0.0);
}

