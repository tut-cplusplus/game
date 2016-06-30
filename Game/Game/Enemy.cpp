#include "Enemy.hpp"
#include <GL/glut.h>


void Enemy::move(void)
{
}

void Enemy::breakWall(void)
{
}

Enemy::Enemy()
{
}

Enemy::Enemy(int x, int y, int size, int x_w, int y_w) : x_width(x_w),y_width(y_w) {
}


Enemy::~Enemy()
{
}

void Enemy::drawDisplay(void)
{
	glBegin(GL_QUADS);
	glVertex2d(x, y + y_width);
	glVertex2d(x, y);
	glVertex2d(x + x_width, y);
	glVertex2d(x + x_width, y + y_width);
	glEnd();
}

void Enemy::visibility(int state)
{
}

void Enemy::resize(int w, int h)
{
}

void Enemy::inputMouse(int button, int state, int x, int y)
{
}

void Enemy::inputActiveMotion(int x, int y)
{
}

void Enemy::inputPassiveMotion(int x, int y)
{
}

void Enemy::inputKeyboard(unsigned char key, int x, int y)
{
}

void Enemy::inputKeyboardUp(unsigned char key, int x, int y)
{
}

void Enemy::inputSpecialKey(unsigned char key, int x, int y)
{
}

void Enemy::inputSpecialKeyUp(unsigned char key, int x, int y)
{
}

void Enemy::idle(void)
{
}
