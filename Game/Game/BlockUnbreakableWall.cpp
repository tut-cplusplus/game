#include "BlockUnbreakableWall.hpp"

#include "GL/glut.h"

BlockUnbreakableWall::BlockUnbreakableWall()
	: BlockWall()
{

}

BlockUnbreakableWall::BlockUnbreakableWall(const Size<double>& size)
	: BlockWall(size)
{

}

void BlockUnbreakableWall::changeColor(void) const
{
	//灰色に設定する
	glColor3d(0.5, 0.5, 0.5);
}

bool BlockUnbreakableWall::isBreakable(void) const
{
	//破壊不可能
	return false;
}

void BlockUnbreakableWall::draw(void)
{
	BlockWall::draw();
}

