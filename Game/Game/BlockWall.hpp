#ifndef ___Class_BlockWall
#define ___Class_BlockWall

#include "Block.hpp"

/**
 * 壁クラス．
 */
class BlockWall : public Block {
public:
	BlockWall(int width, int height);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
};

BlockWall::BlockWall(int width, int height)
	: Block(width, height)
{

}

void BlockWall::draw(void)
{
	glColor3d(0.0, 0.0, 1.0);
	Block::draw();
}

#endif

