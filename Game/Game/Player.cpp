#include <iostream>

#include "Player.hpp"
#include "CircularSector.hpp"

#include <GL/glut.h>

using namespace std;

void Player::init(void)
{
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

}

void Player::onDown(void)
{

}

void Player::onLeft(void)
{

}

void Player::onRight(void)
{

}

void Player::onBreakBlock(void)
{

}

void Player::onPlaceBlock(void)
{

}

void Player::onUpDown(void)
{
	if (isMoving)
		return;
	direction = NORTH;
	startMoving();
}

void Player::onDownDown(void)
{
	if (isMoving)
		return;
	direction = SOUTH;
	startMoving();
}

void Player::onLeftDown(void)
{
	if (isMoving)
		return;
	direction = WEST;
	startMoving();
}

void Player::onRightDown(void)
{
	if (isMoving)
		return;
	direction = EAST;
	startMoving();
}

void Player::onBreakBlockDown(void)
{
	startBreaking();
}

void Player::onPlaceBlockDown(void)
{
	startPlacing();
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
	//プレイヤーの向きを表示
	double angle = getAngle();
	double viewAngle = 0.0;
	double radius = width;
	CircularSector circularSector(Vector<double>(width / 2, height / 2), angle, viewAngle, radius);
	circularSector.draw();
}

Keypad Player::getKeypad(void) const
{
	return keypad;
}

