#include <iostream>

#include "BlockTrap.hpp"

using namespace std;

BlockTrap::BlockTrap()
	: Block()
{
	loadAnimations();
}

BlockTrap::BlockTrap(const Size<double>& size)
	: Block(size)
{
	loadAnimations();
}

void BlockTrap::loadAnimations(void)
{
	Block::loadAnimations();
}

string BlockTrap::getAnimationPath(void) const
{
	return "data/animations/Trap.ani";
}

bool BlockTrap::isTransparent(void) const
{
	return false;
}

bool BlockTrap::isTransparentByEnemy(void) const
{
	return true;
}

void BlockTrap::draw(void)
{
	Block::draw();
}

Block* BlockTrap::clone(void) const
{
	return new BlockTrap(*this);
}

