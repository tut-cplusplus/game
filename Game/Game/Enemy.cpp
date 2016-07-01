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
{
}

Enemy::Enemy(int x, int y, int width, int height, int size)
	: Character(x, y, width, height, size)
{

}

Enemy::Enemy(int x, int y, int size)
	: Character(x, y, size)
{

}

Enemy::Enemy(int x, int y)
	: Character(x, y)
{

}


Enemy::~Enemy()
{
}

void Enemy::draw(void)
{
	glBegin(GL_QUADS);
	glVertex2d(x, y + height);
	glVertex2d(x, y);
	glVertex2d(x + width, y);
	glVertex2d(x + width, y + height);
	glEnd();
}

