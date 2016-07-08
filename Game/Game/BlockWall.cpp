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
	//四角形の描画
	Block::draw();
	double width = size.getWidth();
	double height = size.getHeight();
	//x印の描画
	glBegin(GL_LINES);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, height);
	glVertex2d(width, 0.0);
	glVertex2d(0.0, height);
	glEnd();
}

