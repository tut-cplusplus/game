#include "GL/glut.h"

#include "BlockWall.hpp"

BlockWall::BlockWall(int width, int height)
	: Block(width, height)
{

}

void BlockWall::draw(void)
{
	glColor3d(0.0, 0.0, 1.0);
	Block::draw();
}

