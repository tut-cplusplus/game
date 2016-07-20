#include <iostream>

#include "BlockTrap.hpp"
#include "BlockBrokenTrap.hpp"

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
	return "data/animations/Block/BlockTrap.ani";
}

bool BlockTrap::isTransparent(void) const
{
	return false;
}

bool BlockTrap::isTransparentByEnemy(void) const
{
	return true;
}

void BlockTrap::onHit(Character& character)
{
	const Vector<double>& destination = character.getDestination();
	double x = (int)destination.getX();
	double y = (int)destination.getY();
	const Vector<double>& position = character.getPosition();
	double dx = position.getX() - x;
	double dy = position.getY() - y;
	double r2 = dx * dx + dy * dy;
	if (r2 > 0.10)
		return;
	character.onHit();
	character.setPosition(destination);
	character.setDirection(Character::WEST);
	damage--;
}

void BlockTrap::draw(void)
{
	Block::draw();
}

Block* BlockTrap::clone(void) const
{
	return new BlockTrap(*this);
}

Block* BlockTrap::brokenBlock(void) const
{
	return new BlockBrokenTrap(size);
}

