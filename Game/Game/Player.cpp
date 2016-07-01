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

void Player::changeColor(void) const
{
	glColor3d(1.0, 0.0, 0.0);
}

