#include <iostream>

#include "Block.hpp"

#include "GL/glut.h"

using namespace std;

Block::Block()
{
	loadAnimations();
}

Block::Block(const Size<double>& size)
	: Rectangle(size)
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
	return "data/animations/Wall.ani";
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
	animation.draw();
}

void Block::setSize(const Size<double>& size)
{
	Rectangle::setSize(size);
	animation.setSize(size);
}

Animation Block::getItemAnimation(void) const
{
	return itemAnimation;
}

Block* Block::clone(void) const
{
	return new Block(*this);
}


