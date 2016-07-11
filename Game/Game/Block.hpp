#ifndef ___Class_Block
#define ___Class_Block

#include <string>

#include "Size.hpp"
#include "Rectangle.hpp"
#include "Animation.hpp"

/**
 * ブロッククラス．
 * 壁やトラップの基となる．
 */
class Block : public Rectangle {
private:
	Animation animation;
	Animation itemAnimation;

public:
	Block();
	Block(const Size<double>& size);
	virtual ~Block();
	/**
	 * アニメーションを読み込む
	 */
	void loadAnimations(void);
	/**
	 * アニメーションファイルのパスを返す
	 */
	virtual std::string getAnimationPath(void) const;
	/**
	 * アイテムのアニメーションファイルのパスを返す
	 */
	virtual std::string getItemAnimationPath(void) const;
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
	 * アクセッサ
	 */
	void setSize(const Size<double>& size);
	Animation getItemAnimation(void) const;
	/**
	 * cloneを生成する
	 */
	virtual Block* clone(void) const;
};

#endif

