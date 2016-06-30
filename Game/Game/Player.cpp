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

Player::Player(int x, int y, int size, int x_w, int y_w) : Character(x,y,size), x_width(x_w), y_width(y_w)
{
}


Player::~Player()
{
}


void Player::drawDisplay(void)
{
	glBegin(GL_QUADS);
	glVertex2d(x, y + y_width);
	glVertex2d(x, y);
	glVertex2d(x + x_width, y);
	glVertex2d(x + x_width, y + y_width);
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
