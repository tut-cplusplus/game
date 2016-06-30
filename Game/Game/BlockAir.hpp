#ifndef ___Class_BlockAir
#define ___Class_BlockAir

#include "Block.hpp"

/**
 * 空気ブロッククラス．
 */
class BlockAir : public Block {
public:
	BlockAir(double width, double height);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
};

#endif

