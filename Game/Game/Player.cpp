#include <iostream>

#include "Player.hpp"
#include "CircularSector.hpp"
#include "FPSManager.hpp"

#include <GL/glut.h>

using namespace std;

void Player::init(void)
{
	loadAnimations();
}

void Player::loadAnimations(void)
{
	animations.push_back(Animation());
	animations.push_back(Animation("data/animations/Player/up.ani"));
	animations.push_back(Animation("data/animations/Player/down.ani"));
	animations.push_back(Animation("data/animations/Player/right.ani"));
	animations.push_back(Animation("data/animations/Player/left.ani"));
	for (auto itr = animations.begin(); itr != animations.end(); ++itr) {
		Animation& animation = *itr;
		animation.setLoop(true);
	}
	animation = animations[direction];
	Character::loadAnimations();
}

void Player::startPlacing(BlockType blockType)
{
	isPlacing = true;
	placingBlockType = blockType;
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
	startBreaking();
}

void Player::onPlaceWall(void)
{
	startPlacing(WALL);
}

void Player::onPlaceTrap(void)
{
	startPlacing(TRAP);
}

void Player::onPlaceDecoy(void)
{
	startPlacing(DECOY);
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
}

void Player::onPlaceWallDown(void)
{

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
		animation = animations[direction];
		isChangingDirection = true;
		changeDirectionCount = 0;
		return;
	}
}

void Player::try2startMoving(Direction direction)
{
	if (isMoving)
		return;
	if (isChangingDirection) {
		//1/4秒で移動を開始する
		if (++changeDirectionCount >= FPSManager::getFPS() / 4) {
			isChangingDirection = false;
		}
		return;
	}
	if (this->direction != direction) {
		this->direction = direction;
		animation = animations[direction];
	}
	startMoving();
}

const Keypad& Player::getKeypad(void) const
{
	return keypad;
}

