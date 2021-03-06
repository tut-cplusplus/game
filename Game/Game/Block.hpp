#ifndef ___Class_Block
#define ___Class_Block

#include <string>

#include "Size.hpp"
#include "Rectangle.hpp"
#include "Animation.hpp"
#include "Character.hpp"

/**
 * ブロッククラス．
 * 壁やトラップの基となる．
 */
class Block : public Utility::Rectangle {
private:
	Animation animation;
	Animation itemAnimation;

protected:
	int damage;	//耐久値

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
	 * 敵から見たときに透明ブロックかどうか．
	 *
	 * @return true 透明である場合
	 * @return false 透明でない場合
	 */
	virtual bool isTransparentByEnemy(void) const;
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
	 * キャラクターが当たったときに呼び出される
	 *
	 * @param character キャラクター
	 * @param position ブロックの座標
	 */
	virtual void onHit(Character& character, const Vector<int>& position);
	/**
	 * 描画時に呼ばれる．
	 */
	virtual void draw(void);
	/**
	 * アクセッサ
	 */
	void setSize(const Size<double>& size);
	const Animation& getItemAnimation(void) const;
	int getDamage(void) const;
	void setDamage(int damage);
	/**
	 * cloneを生成する
	 */
	virtual Block* clone(void) const;
	/**
	 * ブロックが壊された後に置かれるブロック
	 */
	virtual Block* brokenBlock(void) const;
};

inline void Block::setSize(const Size<double>& size)
{
	Rectangle::setSize(size);
	animation.setSize(size);
}

inline const Animation& Block::getItemAnimation(void) const
{
	return itemAnimation;
}

inline int Block::getDamage(void) const
{
	return damage;
}

inline void Block::setDamage(int damage)
{
	this->damage = damage;
}

#endif

