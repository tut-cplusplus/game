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
	: Character(), isChangingDirection(false), isPlacing(false)
{
	init();
}

Player::Player(const Vector<double>& position, const Size<double>& size, const Keypad& keypad)
	: Character(position, size), keypad(keypad), isChangingDirection(false), isPlacing(false)
{
	init();
}

Player::Player(const Vector<double>& position, const Keypad& keypad)
	: Character(position), keypad(keypad), isChangingDirection(false), isPlacing(false)
{
	init();
}


Player::~Player()
{
}

void Player::onUp(void)
{
	try2startMoving(NORTH);
}

void Player::onDown(void)
{
	try2startMoving(SOUTH);
}

void Player::onLeft(void)
{
	try2startMoving(WEST);
}

void Player::onRight(void)
{
	try2startMoving(EAST);
}

void Player::onBreakBlock(void)
{

}

void Player::onPlaceWall(void)
{

}

void Player::onPlaceTrap(void)
{

}

void Player::onPlaceDecoy(void)
{

}

void Player::onUpDown(void)
{
	try2changeDirection(NORTH);
}

void Player::onDownDown(void)
{
	try2changeDirection(SOUTH);
}

void Player::onLeftDown(void)
{
	try2changeDirection(WEST);
}

void Player::onRightDown(void)
{
	try2changeDirection(EAST);
}

void Player::onBreakBlockDown(void)
{
	startBreaking();
}

void Player::onPlaceWallDown(void)
{
	startPlacing();
}

void Player::onPlaceTrapDown(void)
{

}

void Player::onPlaceDecoyDown(void)
{

}

void Player::onUpUp(void)
{
	isChangingDirection = false;
}

void Player::onDownUp(void)
{
	isChangingDirection = false;
}

void Player::onLeftUp(void)
{
	isChangingDirection = false;
}

void Player::onRightUp(void)
{
	isChangingDirection = false;
}

void Player::onBreakBlockUp(void)
{

}

void Player::onPlaceWallUp(void)
{

}

void Player::onPlaceTrapUp(void)
{

}

void Player::onPlaceDecoyUp(void)
{

}

void Player::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

void Player::try2changeDirection(Direction direction)
{
	if (isMoving)
		return;
	if (this->direction != direction) {
		this->direction = direction;
		isChangingDirection = true;
		return;
	}
}

void Player::try2startMoving(Direction direction)
{
	if (isMoving)
		return;
	if (isChangingDirection)
		return;
	if (this->direction != direction)
		this->direction = direction;
	startMoving();
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

