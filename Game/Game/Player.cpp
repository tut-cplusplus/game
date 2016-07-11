#include <iostream>

#include "Player.hpp"

#include <GL/glut.h>

using namespace std;

void Player::init(void)
{
	lastUp = false;
	lastDown = false;
	lastLeft = false;
	lastRight = false;
	lastBreakBlock = false;
	lastPlaceBlock = false;
	loadAnimations();
}

void Player::loadAnimations(void)
{
	animation = Animation("data/animations/Player.ani");
	animations.push_back(animation);
	Character::loadAnimations();
}

void Player::startPlacing(void)
{
	isPlacing = true;
}

Player::Player()
	: Character(), isPlacing(false)
{
	init();
}

Player::Player(const Vector<double>& position, const Size<double>& size, const Keypad& keypad)
	: Character(position, size), keypad(keypad), isPlacing(false)
{
	init();
}

Player::Player(const Vector<double>& position, const Keypad& keypad)
	: Character(position), keypad(keypad), isPlacing(false)
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
	startBreaking();
}

void Player::onPlaceBlock(void)
{
	startPlacing();
}

void Player::onUpDown(void)
{

}

void Player::onDownDown(void)
{

}

void Player::onLeftDown(void)
{

}

void Player::onRightDown(void)
{

}

void Player::onBreakBlockDown(void)
{

}

void Player::onPlaceBlockDown(void)
{

}

void Player::onUpUp(void)
{

}

void Player::onDownUp(void)
{

}

void Player::onLeftUp(void)
{

}

void Player::onRightUp(void)
{

}

void Player::onBreakBlockUp(void)
{

}

void Player::onPlaceBlockUp(void)
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

