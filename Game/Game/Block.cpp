#include "GL/glut.h"

#include "Block.hpp"

Block::Block(int width, int height)
	: width(width), height(height)
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

