#ifndef ___Class_BlockAir
#define ___Class_BlockAir

#include "Block.hpp"

/**
 * 空気ブロッククラス．
 */
class BlockAir : public Block {
public:
	BlockAir(int width, int height);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
};

BlockAir::BlockAir(int width, int height)
	: Block(width, height)
{
	
}

void BlockAir::draw(void)
{
	glColor3d(1.0, 1.0, 0.0);
	Block::draw();
}

#endif

