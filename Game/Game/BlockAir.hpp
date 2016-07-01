#ifndef ___Class_BlockAir
#define ___Class_BlockAir

#include "Block.hpp"
#include "Size.hpp"

/**
 * 空気ブロッククラス．
 */
class BlockAir : public Block {
public:
	BlockAir();
	BlockAir(const Size<double>& size);

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

