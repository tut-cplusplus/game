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
	 * 透明ブロックかどうか．
	 *
	 * @return true 透明である場合
	 * @return false 透明でない場合
	 */
	virtual bool isTransparent(void) const;
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
};

#endif

