#include <iostream>

#include "Block.hpp"

#include "GL/glut.h"

using namespace std;

Block::Block(double width, double height)
	: width(width), height(height)
{

}

Block::~Block()
{

}

bool Block::isTransparent(void) const
{
	return false;
}

void Block::destroy(void)
{

}

void Block::draw(void)
{
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
}

