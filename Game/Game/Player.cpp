#include <iostream>

#include "Player.hpp"

#include <GL/glut.h>

using namespace std;

void Player::breakWall(void)
{
}

Player::Player()
	: Character()
{

}

Player::Player(const Vector<double>& position, const Size<double>& size, const Keypad& keypad)
	: Character(position, size), keypad(keypad)
{

}

Player::Player(const Vector<double>& position, const Keypad& keypad)
	: Character(position), keypad(keypad)
{

}


Player::~Player()
{
}

void Player::onUp(void)
{
	if (isMoving)
		return;
	direction = NORTH;
	startMoving();
}

void Player::onDown(void)
{
	if (isMoving)
		return;
	direction = SOUTH;
	startMoving();
}

void Player::onLeft(void)
{
	if (isMoving)
		return;
	direction = WEST;
	startMoving();
}

void Player::onRight(void)
{
	if (isMoving)
		return;
	direction = EAST;
	startMoving();
}

void Player::onBreakBlock(void)
{

}

void Player::changeColor(void) const
{
	glColor3d(1.0, 0.0, 0.0);
}

Keypad Player::getKeypad(void) const
{
	return keypad;
}

