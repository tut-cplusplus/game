#include "BlockAir.hpp"

#include "GL/glut.h"

BlockAir::BlockAir()
	: Block()
{

}

BlockAir::BlockAir(const Size<double>& size)
	: Block(size)
{
	
}

bool BlockAir::isTransparent(void) const
{
	return true;
}

void BlockAir::draw(void)
{
	//何も描画しない
}

