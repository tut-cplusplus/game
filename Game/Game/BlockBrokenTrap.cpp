#include <iostream>

#include "BlockBrokenTrap.hpp"

using namespace std;

BlockBrokenTrap::BlockBrokenTrap()
	: Block()
{
	loadAnimations();
}

BlockBrokenTrap::BlockBrokenTrap(const Size<double>& size)
	: Block(size)
{
	loadAnimations();
}

void BlockBrokenTrap::loadAnimations(void)
{
	Block::loadAnimations();
}

string BlockBrokenTrap::getAnimationPath(void) const
{
	return "data/animations/Trap.ani";
}

bool BlockBrokenTrap::isTransparent(void) const
{
	return true;
}

