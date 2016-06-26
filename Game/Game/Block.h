#ifndef ___Class_Block
#define ___Class_Block

/**
 * ブロッククラス．
 * 壁やトラップの基となる．
 */
class Block {
private:
	int width;	/* 幅 */
	int height;	/* 高さ */
public:
	/**
	 * ブロックの破壊時に呼ばれる．将来的にブロックアイテムのドロップやアニメーションインスタンスの生成を行う．
	 */
	virtual void destroy(void) = 0;
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void) = 0;

	/**
	 * セッター及びゲッター
	 */
	int getWidth(void) const;
	int getHeight(void) const;
	void setWidth(int width);
	void setHeight(int height);

};

inline int Block::getWidth(void) const
{
	return width;
}

inline int Block::getHeight(void) const
{
	return height;
}

inline void Block::setWidth(int width)
{
	this->width = width;
}

inline void Block::setHeight(int height)
{
	this->height = height;
}

#endif

