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
}

