#include <iostream>

#include "Block.hpp"
#include "BlockAir.hpp"

#include "GL/glut.h"

using namespace std;

Block::Block()
	: damage(300)
{
	loadAnimations();
}

Block::Block(const Size<double>& size)
	: Rectangle(size), damage(300)
{
	loadAnimations();
}

Block::~Block()
{

}

void Block::loadAnimations(void)
{
	animation = Animation(getAnimationPath());
	itemAnimation = Animation(getItemAnimationPath());
	animation.setSize(size);
	itemAnimation.setSize(size);
}

string Block::getAnimationPath(void) const
{
	return "data/animations/Block/BlockWall.ani";
}

string Block::getItemAnimationPath(void) const
{
	return "data/animations/test.ani";
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

bool Block::isTransparentByEnemy(void) const
{
	return isTransparent();
}

bool Block::isBreakable(void) const
{
	return true;
}

void Block::onDestroy(void)
{

}

void Block::onHit(Character& character)
{

}

void Block::draw(void)
{
	changeColor();
	glEnable(GL_TEXTURE_2D);
	animation.draw();
	glDisable(GL_TEXTURE_2D);
}

Block* Block::clone(void) const
{
	return new Block(*this);
}

Block* Block::brokenBlock(void) const
{
	return new BlockAir(size);
}

