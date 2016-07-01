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
{
}

Player::Player(double x, double y, double width, double height, int size)
	: Character(x, y, width, height, size)
{

}

Player::Player(double x, double y, int size)
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

