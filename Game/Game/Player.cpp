#include "Player.hpp"

#include <GL/glut.h>

void Player::move(void)
{
}

void Player::breakWall(void)
{
}

Player::Player()
{
}

Player::Player(int x, int y, int width, int height, int size)
	: Character(x, y, width, height, size)
{

}

Player::Player(int x, int y, int size)
	: Character(x, y, size)
{

}

Player::Player(int x, int y)
	: Character(x, y)
{

}


Player::~Player()
{
}


void Player::draw(void)
{
	glBegin(GL_QUADS);
	glVertex2d(x, y + height);
	glVertex2d(x, y);
	glVertex2d(x + width, y);
	glVertex2d(x + width, y + height);
	glEnd();
}

