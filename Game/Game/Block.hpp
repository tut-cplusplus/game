#ifndef ___Class_Block
#define ___Class_Block

#include "Size.hpp"

/**
 * ブロッククラス．
 * 壁やトラップの基となる．
 */
class Block {
protected:
	Size<double> size;	//ブロックの大きさ

public:
	Block();
	Block(const Size<double>& size);
	virtual ~Block();
	/**
	 * 色を変更する
	 * テクスチャの実装に伴って削除する
	 */
	virtual void changeColor(void) const;
	/**
	 * 透明ブロックかどうか．
	 * 透明ブロックを作る場合にはoverrideする．
	 *
	 * @return true 透明である場合
	 * @return false 透明でない場合
	 */
	virtual bool isTransparent(void) const;
	/**
	 * 破壊可能かどうか．
	 * 外壁など，破壊不可能であるべきブロックではoverrideする．
	 *
	 * @return true 破壊できる場合
	 * @return false 破壊できない場合
	 */
	virtual bool isBreakable(void) const;
	/**
	 * ブロックの破壊時に呼ばれる．
	 */
	virtual void onDestroy(void);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);

	/**
	 * セッター及びゲッター
	 */
	Size<double> getSize(void) const;
	void setSize(const Size<double>& size);

};

inline Size<double> Block::getSize(void) const
{
	return size;
}

inline void Block::setSize(const Size<double>& size)
{
	this->size = size;
}

#endif

