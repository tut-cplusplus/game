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


Player::~Player()
{
}


void Player::drawDisplay(void)
{
	glBegin(GL_QUADS);
	glVertex2d(x, y + height);
	glVertex2d(x, y);
	glVertex2d(x + width, y);
	glVertex2d(x + width, y + height);
	glEnd();
}

void Player::visibility(int state)
{
}

void Player::resize(int w, int h)
{
}

void Player::inputMouse(int button, int state, int x, int y)
{
}

void Player::inputActiveMotion(int x, int y)
{
}

void Player::inputPassiveMotion(int x, int y)
{
}

void Player::inputKeyboard(unsigned char key, int x, int y)
{
}

void Player::inputKeyboardUp(unsigned char key, int x, int y)
{
}

void Player::inputSpecialKey(unsigned char key, int x, int y)
{
}

void Player::inputSpecialKeyUp(unsigned char key, int x, int y)
{
}

void Player::idle(void)
{
}
