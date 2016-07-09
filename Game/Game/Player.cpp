#include <iostream>

#include "Player.hpp"

#include <GL/glut.h>

using namespace std;

void Player::loadAnimations(void)
{
	animation = Animation("data/animations/Player.ani");
	animations.push_back(animation);
	Character::loadAnimations();
}

void Player::breakWall(void)
{
}

Player::Player()
	: Character()
{
	init();
}

Player::Player(const Vector<double>& position, const Size<double>& size, const Keypad& keypad)
	: Character(position, size), keypad(keypad)
{
	init();
}

Player::Player(const Vector<double>& position, const Keypad& keypad)
	: Character(position), keypad(keypad)
{
	init();
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
	glColor3d(1.0, 1.0, 1.0);
}

void Player::draw(void)
{
	Character::draw();
	Size<double> size = getSize();
	double width = size.getWidth();
	double height = size.getHeight();
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
}

Keypad Player::getKeypad(void) const
{
	return keypad;
}

