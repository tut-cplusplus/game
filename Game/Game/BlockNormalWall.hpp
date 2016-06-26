#ifndef ___Class_BlockNormalWall
#define ___Class_BlockNormalWall

#include "BlockWall.hpp"

class BlockNormalWall : public BlockWall {
public:
	BlockNormalWall(int width, int height);
};

BlockNormalWall::BlockNormalWall(int width, int height)
	: BlockWall(width, height)
{

}

#endif

