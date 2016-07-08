#include <iostream>

#include "Block.hpp"

#include "GL/glut.h"

using namespace std;

Block::Block()
{

}

Block::Block(const Size<double>& size)
	: Rectangle(size)
{

}

Block::~Block()
{

}

void Block::changeColor(void) const
{
	//白に設定する
	glColor3d(1.0, 1.0, 1.0);
}

bool Block::isTransparent(void) const
{
	return false;
}

bool Block::isBreakable(void) const
{
	return true;
}

void Block::onDestroy(void)
{

}

void Block::draw(void)
{
	changeColor();
	double width = size.getWidth();
	double height = size.getHeight();
	glBegin(GL_LINE_LOOP);
	glVertex2d(0.0, 0.0);
	glVertex2d(width, 0.0);
	glVertex2d(width, height);
	glVertex2d(0.0, height);
	glEnd();
}

