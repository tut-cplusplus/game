#ifndef ___Class_BlockWall
#define ___Class_BlockWall

#include "Block.hpp"

/**
 * 壁クラス．
 */
class BlockWall : public Block {
public:
	BlockWall(double width, double height);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
};

#endif

