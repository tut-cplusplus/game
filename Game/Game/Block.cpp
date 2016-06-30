#include <iostream>

#include "Block.hpp"

#include "GL/glut.h"

using namespace std;

Block::Block()
{

}

Block::Block(double width, double height)
	: width(width), height(height)
{

}

Block::~Block()
{

}

void Block::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

bool Block::isTransparent(void) const
{
	return false;
}

bool Block::isBreakable(void) const
{
	return true;
}

void Block::destroy(void)
{

}

void Block::draw(void)
{
	changeColor();
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
}

