#include "BlockWall.hpp"

#include "GL/glut.h"

BlockWall::BlockWall(double width, double height)
	: Block(width, height)
{

}

void BlockWall::draw(void)
{
	glColor3d(0.0, 0.0, 1.0);
	Block::draw();
}

