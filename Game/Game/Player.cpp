#include <iostream>

#include "Player.hpp"

#include <GL/glut.h>

using namespace std;

void Player::move(void)
{
}

void Player::breakWall(void)
{
}

Player::Player()
	: Character()
{

}

Player::Player(double x, double y, const Size<double>& size, const Keypad& keypad)
	: Character(x, y, size), keypad(keypad)
{

}

Player::Player(double x, double y, const Keypad& keypad)
	: Character(x, y), keypad(keypad)
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

