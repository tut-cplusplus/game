#include "BlockAir.hpp"

#include "GL/glut.h"

BlockAir::BlockAir(double width, double height)
	: Block(width, height)
{
	
}

bool BlockAir::isTransparent(void) const
{
	return true;
}

void BlockAir::draw(void)
{

}

