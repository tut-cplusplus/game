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

Player::Player(double x, double y, const Size<double>& size)
	: Character(x, y, size)
{

}

Player::Player(double x, double y)
	: Character(x, y)
{

}


Player::~Player()
{
}

void Player::changeColor(void) const
{
	glColor3d(1.0, 0.0, 0.0);
}

