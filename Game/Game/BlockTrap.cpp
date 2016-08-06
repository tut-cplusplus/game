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

void BlockTrap::onHit(Character& character, const Vector<int>& position)
{
	/*
	const Vector<double>& destination = character.getDestination();
	const Vector<double>& source = character.getSource();
	double x = (int)source.getX();
	double y = (int)source.getY();
	const Vector<double>& position = character.getPosition();
	double dx = position.getX() - x;
	double dy = position.getY() - y;
	double r2 = dx * dx + dy * dy;
	if (r2 > 0.10)
		character.setPosition(
	*/

	//character.setPosition(destination);
	//character.setDirection(Character::WEST);
	const Vector<double>& characterPosition = character.getPosition();
	double x = position.getX();
	double y = position.getY();
	double dx = x - characterPosition.getX();
	double dy = y - characterPosition.getY();
	double r2 = dx * dx + dy * dy;
	if (r2 > 0.10)
		return;
	character.setPosition(Vector<double>(position.getX(), position.getY()));
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

