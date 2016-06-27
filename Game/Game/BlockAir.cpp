#include "GL/glut.h"

#include "BlockAir.hpp"

BlockAir::BlockAir(int width, int height)
	: Block(width, height)
{
	
}

void BlockAir::draw(void)
{
	glColor3d(1.0, 1.0, 0.0);
	Block::draw();
}

