#ifndef ___Class_Block
#define ___Class_Block

/**
 * ブロッククラス．
 * 壁やトラップの基となる．
 */
class Block {
protected:
	double width;	/* 幅 */
	double height;	/* 高さ */

public:
	Block();
	Block(double width, double height);
	virtual ~Block();
	/**
	 * 色を変更する
	 * テクスチャの実装に伴って削除する
	 */
	virtual void changeColor(void) const;
	/**
	 * 透明ブロックかどうか．
	 *
	 * @return true 透明である場合
	 * @return false 透明でない場合
	 */
	virtual bool isTransparent(void) const;
	/**
	 * 破壊可能かどうか．
	 *
	 * @return true 破壊できる場合
	 * @return false 破壊できない場合
	 */
	virtual bool isBreakable(void) const;
	/**
	 * ブロックの破壊時に呼ばれる．将来的にブロックアイテムのドロップやアニメーションインスタンスの生成を行う．
	 */
	virtual void destroy(void);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);

	/**
	 * セッター及びゲッター
	 */
	double getWidth(void) const;
	double getHeight(void) const;
	void setWidth(double width);
	void setHeight(double height);

};

inline double Block::getWidth(void) const
{
	return width;
}

inline double Block::getHeight(void) const
{
	return height;
}

inline void Block::setWidth(double width)
{
	this->width = width;
}

inline void Block::setHeight(double height)
{
	this->height = height;
}

#endif

