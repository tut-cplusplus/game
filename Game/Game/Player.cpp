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
	cout << "onUp" << endl;
}

void Player::onDown(void)
{
	cout << "onDown" << endl;
}

void Player::onLeft(void)
{
	cout << "onLeft" << endl;
}

void Player::onRight(void)
{
	cout << "onRight" << endl;
}

void Player::onBreakBlock(void)
{
	cout << "onBreakBlock" << endl;
}

void Player::changeColor(void) const
{
	glColor3d(1.0, 0.0, 0.0);
}

Keypad Player::getKeypad(void) const
{
	return keypad;
}

