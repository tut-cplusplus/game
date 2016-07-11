#include <iostream>

#include "BlockNormalWall.hpp"

using namespace std;

BlockNormalWall::BlockNormalWall()
	: BlockWall()
{

}

BlockNormalWall::BlockNormalWall(const Size<double>& size)
	: BlockWall(size)
{

}

Block* BlockNormalWall::clone(void) const
{
	return new BlockNormalWall(*this);
}

