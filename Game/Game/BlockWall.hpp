#ifndef ___Class_BlockWall
#define ___Class_BlockWall

#include "Block.hpp"
#include "Size.hpp"

/**
 * 壁クラス．
 */
class BlockWall : public Block {
public:
	BlockWall();
	BlockWall(const Size<double>& size);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
};

#endif

