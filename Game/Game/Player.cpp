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


void Player::draw(void)
{
	glBegin(GL_QUADS);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
}

