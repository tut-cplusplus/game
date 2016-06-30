#include "BlockWall.hpp"

#include "GL/glut.h"

BlockWall::BlockWall(double width, double height)
	: Block(width, height)
{

}

void BlockWall::draw(void)
{
	glColor3d(1.0, 1.0, 1.0);
	Block::draw();
	glBegin(GL_LINES);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, height);
	glVertex2d(width, 0.0);
	glVertex2d(0.0, height);
	glEnd();
}

