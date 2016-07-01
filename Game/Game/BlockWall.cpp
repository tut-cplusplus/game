#include "BlockWall.hpp"

#include "GL/glut.h"

BlockWall::BlockWall()
	: Block()
{

}

BlockWall::BlockWall(const Size<double>& size)
	: Block(size)
{

}

void BlockWall::draw(void)
{
	Block::draw();
	double width = size.getWidth();
	double height = size.getHeight();
	glBegin(GL_LINES);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, height);
	glVertex2d(width, 0.0);
	glVertex2d(0.0, height);
	glEnd();
}

