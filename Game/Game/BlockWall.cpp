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

Block* BlockWall::clone(void) const
{
	return new BlockWall(*this);
}

